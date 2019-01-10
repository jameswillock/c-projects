#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

char cipher(char character, char key);

int main(int argc, char *argv[])
{
    // Exit early if too few or too many arguments sent
    if (argc != 2)
    {
        printf("Usage: ./vigenere k");
        return 1;
    }

    string keycode = argv[1];

    // Check the keycode argument is entirely alphanumeric
    for (int i = 0, length = strlen(keycode); i < length; i++)
    {
        if (!isalpha(keycode[i]))
        {
            printf("Usage: ./vigenere k");
            return 1;
        }
    }

    // Retrieve string to cipher from user input
    string word = get_string("plaintext: ");
    printf("ciphertext: ");

    // Store index of keycode for ciphering
    int keycode_position = 0;

    for (int i = 0, length = strlen(word); i < length; i++)
    {
        // Move onto next character if not alphanumeric
        if (!isalpha(word[i]))
        {
            printf("%c", word[i]);
            continue;
        }

        printf("%c", cipher(word[i], keycode[keycode_position]));

        // Set keycode index back to zero if end of string
        if (keycode_position > strlen(keycode) - 2)
        {
            keycode_position = 0;
        }
        else
        {
            keycode_position = keycode_position + 1;
        }
    }

    printf("\n");

    return 0;
}

char cipher(char character, char key)
{
    int initial_place = character - (isupper(character) ? 'A' : 'a');
    int move_by = (key - (isupper(key) ? 'A' : 'a')) % 26;
    return (char)((initial_place + move_by) % 26 + (isupper(character) ? 'A' : 'a'));
}