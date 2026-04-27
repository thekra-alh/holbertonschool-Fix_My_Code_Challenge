#include <stdlib.h>
#include "lists.h"

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new = malloc(sizeof(dlistint_t));
    dlistint_t *last = *head;

    if (!new)
        return (NULL);

    new->n = n;
    new->next = NULL;

    if (!*head)
    {
        new->prev = NULL;
        *head = new;
        return (new);
    }

    while (last->next)
        last = last->next;

    last->next = new;
    new->prev = last;

    return (new);
}
