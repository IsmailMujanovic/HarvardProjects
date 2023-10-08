#include <stdio.h>

int main(void)
{
    int start, end;
    do
    {
        printf("Start size: ");
        scanf("%d", &start);
    } while (start < 9);
    do
    {
        printf("End size: ");
        scanf("%d", &end);
    } while (end < start);

    int born, died, increase;

    int years = 0;
    while (start < end)
    {
        born = start/3;
        died = start/4;
        increase = born - died;
        start += increase;
        years++;
    }
    printf("Years: %i", years);
}