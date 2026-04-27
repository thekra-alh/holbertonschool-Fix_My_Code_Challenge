#include <stdlib.h>
#include "lists.h"

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    current = *head;
    i = 0;

    /* Find the node to delete */
    while (current != NULL && i < index)
    {
        current = current->next;
        i++;
    }

    /* If index doesn't exist */
    if (current == NULL)
        return (-1);

    /* If deleting the first node */
    if (current->prev == NULL)
    {
        *head = current->next;
        if (current->next != NULL)
            current->next->prev = NULL;
    }
    /* If deleting the last node */
    else if (current->next == NULL)
    {
        current->prev->next = NULL;
    }
    /* If deleting a node in the middle */
    else
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    free(current);
    return (1);
}
