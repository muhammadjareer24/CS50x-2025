#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} person;

int main(void)
{
    // string names[] = {"Ali", "Jareer", "Qasim"};
    // string numbers[] = {"+92-344-8889990", "+92-314-2018064", "+92-343-8229995"};

    person people[3];

    people[0].name = "Ali";
    people[0].number = "+92-344-8889990";

    people[1].name = "Jareer";
    people[1].number = "+92-314-2018064";

    people[2].name = "Qasim";
    people[2].number = "+92-343-8229995";

    string name = get_string("Name: ");

    for(int i = 0; i <3 ; i++)
    {
        if(strcmp(people[i].name, name) == 0)
        {
            printf("Found %s/n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
