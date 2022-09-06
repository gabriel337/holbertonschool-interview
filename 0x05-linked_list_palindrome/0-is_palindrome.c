#include "lists.h"
/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 if is not palindrome, 1 if it is
 **/
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head;
    listint_t *fast = slow->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == NULL || fast == NULL)
            return (0);
    }
    if (fast != NULL)
        slow = slow->next;
    while (slow && (*head))
    {
        if (slow->n != (*head)->n)
        {
            return (1);
        }
        else
        {
            *head = (*head)->next;
        }
    }
    return (0);
}
