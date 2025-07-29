#include <cs50.h>
#include <stdio.h>

void print_row(int i, int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);

    for (int i = 1; i <= n; i++)
    {
        print_row(i, n);
    }
}

void print_row(int i, int n)
{
    for (int spaces = 0; spaces < n - i; spaces++)
    {
        printf(" ");
    }

    for (int bricks = 0; bricks < i; bricks++)
    {
        printf("#");
    }
    printf("\n");
}
