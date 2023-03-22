#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    int n;
    do
    {
        n = get_int("Start size: ");
    } 
    while (s < 9);

    int e;
    do
    {
        e = get_int("End size: ");
    } 
    while (e < n);

    int y = 0;

    while (n < e) 
    {
        n = n + (n / 3) - (n / 4);
        y++;
    }

    printf("Years: %i\n", y);
    
}