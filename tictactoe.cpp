#include <stdio.h>

#define SIZE 3

// Function to display board
void display(char (*board)[SIZE]) {
    printf("\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf(" %c ", *(*(board + i) + j));
            if(j < SIZE - 1) printf("|");
        }
        printf("\n");
        if(i < SIZE - 1) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check winner
char checkWinner(char (*board)[SIZE]) {
    // Rows & Columns
    for(int i = 0; i < SIZE; i++) {
        if(*(*(board+i)+0) == *(*(board+i)+1) &&
           *(*(board+i)+1) == *(*(board+i)+2))
            return *(*(board+i)+0);

        if(*(*(board+0)+i) == *(*(board+1)+i) &&
           *(*(board+1)+i) == *(*(board+2)+i))
            return *(*(board+0)+i);
    }

    // Diagonals
    if(*(*(board+0)+0) == *(*(board+1)+1) &&
       *(*(board+1)+1) == *(*(board+2)+2))
        return *(*(board+0)+0);

    if(*(*(board+0)+2) == *(*(board+1)+1) &&
       *(*(board+1)+1) == *(*(board+2)+0))
        return *(*(board+0)+2);

    return ' '; // No winner
}

int main() {
    char board[SIZE][SIZE];
    int row, col;
    char player = 'X';

    // Initialize board
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            *(*(board + i) + j) = ' ';
        }
    }

    printf("?? TIC TAC TOE GAME ??\n");

    for(int move = 0; move < SIZE * SIZE; move++) {
        display(board);

        printf("Player %c, enter row and column (0-2): ", player);
        scanf("%d %d", &row, &col);

        // Validate move
        if(row < 0 || row >= SIZE || col < 0 || col >= SIZE ||
           *(*(board + row) + col) != ' ') {
            printf("Invalid move! Try again.\n");
            move--;
            continue;
        }

        // Place move using pointer
        *(*(board + row) + col) = player;

        // Check winner
        char winner = checkWinner(board);
        if(winner != ' ') {
            display(board);
            printf("?? Player %c wins!\n", winner);
            return 0;
        }

        // Switch player
        player = (player == 'X') ? 'O' : 'X';
    }

    display(board);
    printf("?? It's a draw!\n");

    return 0;
}

