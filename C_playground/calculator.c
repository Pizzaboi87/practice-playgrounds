#include <stdio.h>

void giveNums(double *nums){
    printf("Please add the first number: ");
    scanf("%lf", &nums[0] );
    
    printf("Please add the second number: ");
    scanf("%lf", &nums[1] );
}

double addition(double num1, double num2){
    return num1 + num2;
}

double subtraction(double num1, double num2){
    return num1 - num2;
}

double multiplication(double num1, double num2){
    return num1 * num2;
}

double division(double num1, double num2){
    return num1 / num2;
}

int main() {
    double nums[2];
    double result;
    char operate;

    printf("What will be the operation (+ - / *)?: ");
    scanf("%c", &operate);
    
    giveNums(nums);
    
    switch(operate){
        case '+':
            result = addition(nums[0], nums[1]);
            printf("\nThe result is %lf\n\n", result);
            break;
        case '-':
            result = subtraction(nums[0], nums[1]);
            printf("\nThe result is %lf\n\n", result);
            break;
        case '*':
            result = multiplication(nums[0], nums[1]);
            printf("\nThe result is %lf\n\n", result);
            break;
        case '/':
            result = division(nums[0], nums[1]);
            printf("\nThe result is %lf\n\n", result);
            break;
        default:
            printf("\nThe operator %c is not valid.\n\n", operate);
            break;
    }
    
    return 0;
}