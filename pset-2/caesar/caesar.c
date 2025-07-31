#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;
    }

    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]); // Convert argv[1] from a `string` to an `int`

    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    int len = strlen(plaintext);
    char ciphertext[len + 1];

    // For each character in the plaintext:
    for (int i = 0; i < len; i++)
    {

        // Rotate the character if it's a letter
        if (isalpha(plaintext[i]))
        {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = (plaintext[i] - base + key) % 26 + base;
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[len] = '\0';

    printf("ciphertext:  %s\n", ciphertext);
    return 0;
}

bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
