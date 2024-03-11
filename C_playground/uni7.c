#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("be.txt", "r");
    char c;
    int x = 0, y = 0;
    int irany = 0;
    while ((c = fgetc(fp)) != EOF)
    {
        if (c == 'b')
        {
            irany = (irany + 3) % 4;
        }
        else if (c == 'j')
        {
            irany = (irany + 1) % 4;
        }
        else if (c == 'e')
        {
            irany = 0;
        }
        else if (c == 'k')
        {
            irany = 1;
        }
        else if (c == 'd')
        {
            irany = 2;
        }
        else if (c == 'n')
        {
            irany = 3;
        }
        else if (c >= '1' && c <= '9')
        {
            int lepes = c - '0';
            if (irany == 0)
            {
                y += lepes;
            }
            else if (irany == 1)
            {
                x += lepes;
            }
            else if (irany == 2)
            {
                y -= lepes;
            }
            else if (irany == 3)
            {
                x -= lepes;
            }
        }
    }
    fclose(fp);
    fp = fopen("ki.txt", "w");
    fprintf(fp, "%d", x+y);
    fclose(fp);
    return 0;
}