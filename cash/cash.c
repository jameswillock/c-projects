#include <stdio.h>
#include <math.h>
#include <cs50.h>

int get_change(void);
int coins_for_change(int change);

int main()
{
    // Get change from user prompt
    int change = get_change();

    // Deduce number of coins from change
    int coins = coins_for_change(change);

    printf("%i\n", coins);

    return 0;
}

int get_change(void)
{
    float change = -1;

    // Prompt for non-negative input
    while (change < 0)
    {
        change = get_float("Change owed: ");
    }

    // Cents to dollars, floating point currency is bad!
    return (int)roundf(change * 100);
}

int coins_for_change(int change)
{
    int coins = 0;

    // Reduce change by n quarters
    while (change >= 25)
    {
        change -= 25;
        coins++;
    }

    // Reduce change by n dimes
    while (change >= 10)
    {
        change -= 10;
        coins++;
    }

    // Reduce change by n nickels
    while (change >= 5)
    {
        change -= 5;
        coins++;
    }

    // Reduce change by n pennies
    while (change >= 1)
    {
        change -= 1;
        coins++;
    }

    return coins;
}