#include <stdio.h>
#include <cs50.h>

int get_height(void);
void print_row(int row, int height);

int main(void)
{
    // Get height from user input
    int height = get_height();

    // Print rows for height
    for (int i = 0; i < height; i++)
    {
        print_row(i + 1, height);
    }
}

int get_height(void)
{
    int input = -1;

    // Ensure height is more than 0 and less than 24
    while (input < 0 || input > 23)
    {
        printf("Height: ");
        input = get_int();
    }
    return input;
}

void print_row(int row, int height)
{
    int offset = height - row;

    for (int i = 0; i < offset; i++)
    {
        printf(" ");
    }

    printf("#");

    for (int i = 0; i < row; i++)
    {
        printf("#");
    }

    if (row != height)
    {
        printf("\n");
    }
}
