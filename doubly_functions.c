#include "monty.h"

/**
 *add_dnodeint - add a note at the begining of the doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_dlistint(vl.head);
		free(vl.buffer);
		fclose(vl.fd);
		exit(EXIT_FAILURE);
	}

	if (!head || !temp)
		return (temp ? free(temp), NULL : NULL);
	temp->n = n;
	temp->prev = NULL;
	if (!*head)
	{
		*head = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		*head = temp;
	}
	return (temp);
}

/**
 * free_dlistint - frees the doubly linked list
 *
 * @head: the pointer head of list
 * Return: Void
 */
void free_dlistint(stack_t *head)
{
	stack_t *current;

	while ((current = head) != NULL)
	{
		head = head->next;
		free(current);
	}
}
