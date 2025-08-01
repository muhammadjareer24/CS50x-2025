#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Ali", "Jareer", "Qasim"};
    string numbers[] = {"+92-344-8889990", "+92-314-2018064", "+92-343-8229995"};

    string name = get_string("Name: ");

    for (int i = 0; i < 3; i++)
    {
        if(strcmp(names[i], name) == 0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not Found\n");
}
