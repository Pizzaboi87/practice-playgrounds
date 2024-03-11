#include <stdio.h>
#include <math.h>

int main() {
    //Declare steps variable
    double steps;
    
    //Ask the value of calculation steps from the user
    do {
        printf("Please add the size of steps between the values (0.01 - 1): ");
        scanf("%lf", &steps);
    } while (steps > 1 || steps < 0.01);
    
    //x means the calculation base value
    //cos(x) means cosine value of x
    //sin(x) means sine value of x
    
    //Print the table header
    printf("\nSine and cosine values with %lf steps\n", steps);
    printf("x\t\tcos(x)\t\tsin(x)\n");
    printf("______________________________________\n");

    //Print the table values with the selected steps
    for (double x = 0; x <= 1; x += steps) {
        printf("%.4lf\t\t%.4lf\t\t%.4lf\n", x, cos(x), sin(x));
    }

    return 0;
}