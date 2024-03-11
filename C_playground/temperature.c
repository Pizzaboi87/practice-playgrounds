#include <stdio.h>
#include <ctype.h>

int main() {
    char unit;
    float temp;
    float result;

    printf("Is the temperature in Farenheit (F) or Celsius (C)?: ");
    scanf("%c", &unit);

    unit = toupper(unit);

    if(unit == 'C'){
        printf("\nWhat is the current temperature in Celsius?: ");
        scanf("%f", &temp);
        result = (temp * 9 / 5) + 32;
        printf("\nThe temperature %.1f°C in Farenheit is %.1f°F\n\n", temp, result);
    } else if (unit == 'F'){
        printf("\nWhat is the current temperature in Farenheit?: ");
        scanf("%f", &temp);
        result = ((temp - 32) * 5) / 9;
        printf("\nThe temperature %.1f°F in Farenheit is %.1f°C\n\n", temp, result);
    } else {
        printf("\nThe %c is not a valid unit.", unit);
    }


    return 0;
}