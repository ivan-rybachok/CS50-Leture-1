#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        // prompt user for height number
        height = get_int("Height: ");
    }
    // making sure the number is between 1-8
    while (height <= 0 || height > 8);

    // creating a variable to store number
    int n = 0;
    for (int i = 0; i < height; i++)
    {
        // upside down loop for the empty string
        for(int j = height - 1; j > i; j--)
        {
            printf(" ");
        }

        // updating the stored number
        n++;
        // using the  stored number in a loop to print out hashes from 1 to height number
        for(int k = 0; k < n; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}