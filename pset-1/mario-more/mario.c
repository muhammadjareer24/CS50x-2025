#include <cs50.h>
#include <stdio.h>

void print_rows(int i, int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (int i = 1; i <= n; i++)
    {
        print_rows(i, n);
    }
}

void print_rows(int i, int n)
{
    for (int spaces = 0; spaces < n - i; spaces++)
    {
        printf(" ");
    }

    for (int bricks = 0; bricks < i; bricks++)
    {
        printf("#");
    }

    for (int spaces = 0; spaces < 2; spaces++)
    {
        printf(" ");
    }

    for (int bricks = 0; bricks < i; bricks++)
    {
        printf("#");
    }

    printf("\n");
}
