#include <stdio.h>   
#include <math.h>

int main(void) {
    //declare the input number
    double number;
    
    //ask the input while it's not in the correct range
    do {
        printf("Enter a number between 1 and 0: ");
        scanf("%lf", &number);
    } while (number > 1 || number < 0);
    
    //calculate sine value of the input and print it
    printf("The sine of your number is: %lf\n", sin(number));
    
    return 0;
}