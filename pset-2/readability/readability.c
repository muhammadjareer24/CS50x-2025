#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    // Compute the Coleman-Liau index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade level
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        // Check if this is a letter
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    // Return the number of letters in text
    return letters;
}

int count_words(string text)
{

    int words = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        // Check if this is a word
        if (isspace(text[i]))
        {
            words++;
        }
    }
    // Return the number of words in text
    return words + 1;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        // Check if this is a sentence
        if ((text[i] == '.' || text[i] == '!' || text[i] == '?'))
        {
            sentences++;
        }
    }
    // Return the number of sentences in text
    return sentences;
}
