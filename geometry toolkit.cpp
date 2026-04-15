#include<stdio.h>

void triangle(){
    float base, height;
    float *b = &base, *h = &height;

    printf("Enter base: \n");
    scanf("%f", b);

    printf("Enter height: \n");
    scanf("%f", h);

    float area = 0.5 * (*b) * (*h);
    printf("Area of triangle = %.2f\n", area);
}

void square(){
    float side;
    float *s = &side;

    printf("Enter side: \n");
    scanf("%f", s);

    printf("Area of Square = %.2f\n", (*s) * (*s));
    printf("Perimeter of Square = %.2f\n", 4 * (*s));
}

void rectangle(){
    float length, breadth;
    float *l = &length, *br = &breadth;

    printf("Enter length: \n");
    scanf("%f", l);

    printf("Enter breadth: \n");
    scanf("%f", br);

    printf("Area of Rectangle = %.2f\n", (*l) * (*br));
    printf("Perimeter of Rectangle = %.2f\n", 2 * ((*l) + (*br)));
}

void circle(){
    float radius;
    float *r = &radius;

    printf("Enter radius: \n");
    scanf("%f", r);

    printf("Area of circle = %.2f\n", 3.14 * (*r) * (*r));
    printf("Perimeter of circle = %.2f\n", 2 * 3.14 * (*r));
}

int main(){
    int choice;

    do{
        printf("\n*** MINI GEOMETRY TOOL KIT ***\n");
        printf("1. Triangle\n");
        printf("2. Square\n");
        printf("3. Rectangle\n");
        printf("4. Circle\n");
        printf("5. Exit...\n");

        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch(choice){
            case 1: triangle(); break;
            case 2: square(); break;
            case 3: rectangle(); break;
            case 4: circle(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}
