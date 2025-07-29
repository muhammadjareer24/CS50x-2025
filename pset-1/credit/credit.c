#include <cs50.h>
#include <stdio.h>

int checksum(long number);
int get_starting_digits(long number, int digits);
int count_digits(long number);

int main(void)
{
    long card_number;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 0);

    if (checksum(card_number) % 10 == 0)
    {
        int digits = count_digits(card_number);
        int start = get_starting_digits(card_number, digits);

        if ((digits == 15) && (start == 34 || start == 37))
        {
            printf("AMEX\n");
        }
        else if ((digits == 16) && (start >= 51 && start <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((digits == 13 || digits == 16) && (start / 10 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int checksum(long number)
{
    int sum = 0;
    int position = 0;

    while (number > 0)
    {
        int digit = number % 10;

        if (position % 2 == 0)
        {
            sum += digit;
        }
        else
        {
            int product = digit * 2;

            sum += product / 10 + product % 10;
        }

        number /= 10;
        position++;
    }
    return sum;
}

int get_starting_digits(long number, int digits)
{
    while (digits > 2)
    {
        number /= 10;
        digits--;
    }
    return number;
}

int count_digits(long number)
{
    int count = 0;
    while (number > 0)
    {
        number /= 10;
        count++;
    }
    return count;
}
