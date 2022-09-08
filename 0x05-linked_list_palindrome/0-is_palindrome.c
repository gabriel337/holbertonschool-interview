#include "lists.h"
/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 if is not palindrome, 1 if it is
 **/
int is_palindrome(listint_t **head)
{
    listint_t *slow;
    listint_t *fast = *head;

    if (*head == NULL || (*head)-> next == NULL)
        return(1);

    while (fast->next)
        fast = fast->next;
    slow = *head;
    while (fast >= slow)
    {
        if (slow->n == fast->n)
        {
            slow = slow->next;
            fast -= 2;
        }
        else
        {
            return(0);
        }
    }
    return (1);
}
