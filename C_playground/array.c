#include <stdio.h>

int main()
{
    int nums[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    int rows = sizeof(nums)/sizeof(nums[0]);
    int cols = sizeof(nums[0])/sizeof(nums[0][0]);
    
    printf("Rows: %d\n", rows);
    printf("Cols: %d\n\n", cols);
    
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d ", nums[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}