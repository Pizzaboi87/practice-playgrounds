#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int MIN = 1;
    const int MAX = 100;
    int guesses = 0;
    int guess;
    int answer;
    
    srand(time(0));
    
    answer = (rand() % MAX) + MIN;
    
    do {
        printf("Enter a guess: ");
        scanf("%d", &guess);
        
        if(guess > answer)
        {
            printf("Too high!\n");
        }
        else if(guess < answer)
        {
            printf("Too low!\n");
        }
        else
        {
            printf("CORRECT!\n\n");
        }
        guesses++;
    } while(guess != answer);
    
    printf("********************\n");
    printf("Answer: %d\n", answer);
    printf("Your tips: %d\n", guesses);
    printf("********************\n\n");    
    
    return 0;
}