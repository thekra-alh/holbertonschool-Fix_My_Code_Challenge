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

    while (current != NULL && i < index)
    {
        current = current->next;
        i++;
    }

    if (current == NULL)
        return (-1);

    /* If deleting the first node */
    if (current->prev == NULL)
    {
        *head = current->next;
        if (current->next != NULL)
            current->next->prev = NULL;
    }
    else
    {
        /* THIS IS THE KEY FIX - update next pointer, not prev */
        current->prev->next = current->next;
        if (current->next != NULL)
            current->next->prev = current->prev;
    }

    free(current);
    return (1);
}
