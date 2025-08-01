#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {1, 40, 100, 30, 90, 1, 50};

    int n = get_int("Number: ");

    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found %i\n", n);
            return 0;
        }
    }
    printf("Could Not Found %i\n", n);
    return 1;
}
