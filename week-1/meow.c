#include <cs50.h>
#include <stdio.h>

int get_pos_int(void);
void meow(int n);

int main(void)
{
    int n = get_pos_int();
    meow(n);
}

int get_pos_int(void)
{
    int n;
    do
    {
        n = get_int("No. of times you want cat to meow? ");
    }
    while (n < 1);
    return n;
}

void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
