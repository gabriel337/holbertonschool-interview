#include "lists.h"
#include <stdlib.h>

/**
 * *insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to the pointer of the head.
 * @number: the value the data will have.
 * Return: address of the new node.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmp = *head, *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	if (tmp == NULL || number <= tmp->n)
	{
		new->n = number;
		new->next = *head;
		*head = new;
		return (new);
	}
	while (number >= tmp->n)
	{
		if (tmp == NULL || tmp->next == NULL)
			return (NULL);
		if (tmp->next->n > number)
		{
			new->n = number;
			new->next = tmp->next;
			tmp->next = new;
			return (new);
		}
		if (tmp->next->next == NULL && tmp->next->n < number)
		{
			add_nodeint_end(&tmp, number);
		}
		tmp = tmp->next;
	}
	return (NULL);
}