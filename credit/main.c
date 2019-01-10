#include <stdio.h>
#include <cs50.h>

int long_long_length(long long number);
int valid_card_length(int length);
string card_kind(int first, int second);

int main()
{
    // Get card number from user input
    long long card_number = get_long_long("Number: ");

    // Get card length and create card numbers array
    int card_length = long_long_length(card_number);
    int card_numbers[card_length];

    // Default type to invalid
    string card_type = "INVALID";

    // Exit early if invalid card length
    if (!valid_card_length(card_length))
    {
        printf("%s\n", card_type);
        return 0;
    }

    // Iterate over card and add products
    int digits = 0;
    int singled_product = 0;
    int doubled_product = 0;
    int should_double = 0;

    while (card_number != 0)
    {

        // Get last digit of card number
        int digit = (int)(card_number % 10);

        // Assign digit into card numbers array position
        card_numbers[card_length - digits - 1] = digit;

        // Double digit if necessary, then split and add to product
        if (should_double)
        {
            int doubled = digit * 2;

            while (doubled != 0)
            {
                doubled_product += doubled % 10;
                doubled /= 10;
            }

            should_double = 0;
        }
        else
        {
            singled_product += digit;
            should_double = 1;
        }

        card_number /= 10;
        digits++;
    }

    // Exit early if final digit of added products is non-zero
    if ((singled_product + doubled_product) % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Print card type
    string kind = card_kind(card_numbers[0], card_numbers[1]);
    printf("%s\n", kind);

    return 0;
}

int long_long_length(long long number)
{
    // Iterate over digits in long and return count
    int length = 0;

    while (number > 0)
    {
        number /= 10;
        length++;
    }

    return length;
}

int valid_card_length(int length)
{
    // Only return truthy if length is 13, 15 or 16
    if (length == 13 || length == 15 || length == 16)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string card_kind(int first, int second)
{
    // Default to invalid card type
    string type = "INVALID";

    // If 34 or 36, then AMEX
    if (first == 3 && (second == 4 || second == 7))
    {
        type = "AMEX";
    }

    // If 51, 52, 53, 54 or 55, then MASTERCARD
    if (first == 5 && second >= 1 && second <= 5)
    {
        type = "MASTERCARD";
    }

    // If 4, then VISA
    if (first == 4)
    {
        type = "VISA";
    }

    return type;
}