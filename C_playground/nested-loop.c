#include <stdio.h>

int main()
{
    int row, col;
    char symbol;
    
    printf("Please give me the number of rows: ");
    scanf("%d", &row);
    
    printf("\nPlease give me the number of columns: ");
    scanf("%d", &col);
    
    printf("\nPlease give me a symbol to use: ");
    scanf(" %c", &symbol);
    
    printf("\nThank you. Here is your rectangle:\n\n");
    
    for(int i = 1; i <= row; i++)
    {
        for(int j = 1; j <= col; j++)
        {
            printf("%c ", symbol);
        }
        printf("\n");
    }
    
    return 0;
}