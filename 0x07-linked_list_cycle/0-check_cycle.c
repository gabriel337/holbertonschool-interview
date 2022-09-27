#include "lists.h"

/**
 * check_cycle - Checks if a cycle exists within a singly linked list
 * @list: singly list to check
 * Return: 0 if 
 */
int check_cycle(listint_t *list)
{
    listint_t *c, *h;

    c = h = list;
    while (c && h && h->next)
    {
        c = c->next;
        h = h->next->next;
        if (c == h)
            return (1);
    }
    return (0);
}