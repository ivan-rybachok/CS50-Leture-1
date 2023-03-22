#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_years(int start, int end);

int main(void)
{
    // Get size of population from the user
    int start = get_size();
    int end = get_size();

    // Print years
    print_years(start, end);
}

int get_size(void)
{
    //  Prompt for start size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
    return start;

    // Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while(end < start);
    return end;
}

void print_years(int start, int end)
{
    // Keep track of number of years
    int years = 0;

    // Update population until we reach threshold
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }
    // Print number of years
    printf("Years: %i\n", years);
}
