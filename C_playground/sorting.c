#include <stdio.h>

void getNums(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("\nEnter a new number: ");
        scanf("%d", &array[i]);
    }
}

void sort(int array[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void printArray(int array[], int size)
{
    printf("\n\nThe ascending order: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

int main()
{
    int size;
    
    printf("How many numbers want you sort?\n");
    printf("Quantity: ");
    scanf("%d", &size);
    printf("\n");
    
    int array[size];
    
    getNums(array, size);
    sort(array, size);
    printArray(array, size);
    
    return 0;
}