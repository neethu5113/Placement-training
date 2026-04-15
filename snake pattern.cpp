#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10;
    char board[10][10];

    char *ptr = &board[0][0];

    // Fill board
    for(int i = 0; i < n*n; i++) {
        *(ptr + i) = '.';
    }

    // Snake head
    *(ptr + 22) = 'O';

    // Print board
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}

