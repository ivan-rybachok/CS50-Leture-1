# include <cs50.h>
# include <stdio.h>

int main(void)
{
    int height, row, space, column;
    do
    {
        height = get_int("Height: ");
    }
    while(height < 1 || height > 8);

    // first loop to loop the pyramid's height
    for (row = 0; row < height; row++)
    {
        // first inner loop loops to print spaces
        for(space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }
        // second inner loop loops to print hashes
        for(column = 0; column <= row; column++)
        {
            printf("#");
        }
        // adding space in between pyramids
        printf("  ");
        // looping the other side of the pyramid
        for(column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}