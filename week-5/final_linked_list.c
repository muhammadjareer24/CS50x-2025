#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    // Start with an empty list
    node *list = NULL;

    // Build list with 3 numbers from user input
    for (int i = 0; i < 3; i++)
    {
        // Allocate memory for a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }

        // Get user input and initialize the new node
        n->number = get_int("Number: ");
        n->next = NULL;

        // Insert the node into the correct sorted position

        // Case 1: list is empty
        if (list == NULL)
        {
            list = n;
        }
        // Case 2: insert at beginning
        else if (n->number < list->number)
        {
            n->next = list;
            list = n;
        }
        // Case 3: insert in middle or end
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // Insert at end
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }

                // Insert between nodes
                if (n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    // Print the sorted list
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Free memory
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    return 0;
}
