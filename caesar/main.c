#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

char cipher(char character, int offset);

int main(int argc, char *argv[])
{
    // Exit early if argument count is incorrect
    if (argc != 2)
    {
        printf("Usage: ./caesar k");
        return 1;
    }

    // Store offset in integer variable
    const int offset = atoi(argv[1]);

    // Get string from user input
    string word = get_string("plaintext: ");

    printf("ciphertext: ");

    // Call cipher function for each input
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        printf("%c", cipher(word[i], offset));
    }

    printf("\n");

    return 0;
}

char cipher(char character, int offset)
{
    // Return character unchanged if not alphabetic
    if (!isalpha(character))
    {
        return character;
    }

    // Work from upper or lower case
    char base_character = isupper(character) ? 'A' : 'a';

    // Return ciphered character
    return (char)((((character - base_character) + offset) % 26) + base_character);
}

