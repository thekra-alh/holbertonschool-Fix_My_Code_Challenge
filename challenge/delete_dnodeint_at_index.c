#include <stdlib.h>
#include "lists.h"

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *temp = *head;
    unsigned int i = 0;

    if (!head || !*head)
        return (-1);

    while (temp && i < index)
    {
        temp = temp->next;
        i++;
    }

    if (!temp)
        return (-1);

    /* Fix the links */
    if (temp->prev)
        temp->prev->next = temp->next;
    else
        *head = temp->next;

    if (temp->next)
        temp->next->prev = temp->prev;

    free(temp);
    return (1);
}
