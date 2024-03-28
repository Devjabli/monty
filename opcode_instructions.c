#include "monty.h"

/**
 * func_push - pushing element to stack
 *
 * @head: pointer head of the linked list
 * @line_number: line number
 * Return: Void
 */
void func_push(stack_t **head, unsigned int line_number)
{
	int n, i = 0;

	if (!vl.arg)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "usage: push integer\n");
		free_dlistint(vl.head);
		free(vl.buffer);
		fclose(vl.fd);
		exit(EXIT_FAILURE);
	}

	while (vl.arg[i] != '\0')
	{
		if (!isdigit(vl.arg[i]) && vl.arg[i] != '-')
		{
			fprintf(stderr, "L%u: ", line_number);
			fprintf(stderr, "usage: push integer\n");
			free_dlistint(vl.head);
			free(vl.buffer);
			fclose(vl.fd);
			exit(EXIT_FAILURE);
		}
		i++;
	}

	n = atoi(vl.arg);
	add_dnodeint(head, n);
}

/**
 * func_pall - printing all numbers on stack
 *
 * @head: pointer head of the linked list
 * @line_number: line numbers
 * Return: Void
 */
void func_pall(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * func_pint - prints the single number at the top of stack
 *
 * @head: head of the linked list
 * @line_number: line number
 * Return: Void
 */
void func_pint(stack_t **head, unsigned int line_number)
{
	(void)line_number;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't pint, stack empty\n");
		free_dlistint(vl.head);
		free(vl.buffer);
		fclose(vl.fd);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * func_pop - removing top of element of the stack
 *
 * @head: pointer head of the linked list
 * @line_number: line number
 * Return: Void
 */
void func_pop(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_dlistint(vl.head);
		free(vl.buffer);
		fclose(vl.fd);
		exit(EXIT_FAILURE);
	}
	current = *head;
	*head = (*head)->next;
	free(current);
}

/**
 * func_swap - swaps the top two elements of the stack
 *
 * @head: head of the linked list
 * @cline: line number
 * Return: no return
 */
void func_swap(stack_t **head, unsigned int cline)
{
	int i = 0;
	stack_t *current = NULL;

	current = *head;

	while (current != NULL)
	{
		current = current->next;
		i++;
	}

	if (i < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", cline);
		free_dlistint(vl.head);
		free(vl.buffer);
		fclose(vl.fd);
		exit(EXIT_FAILURE);
	}

	current = *head;
	*head = (*head)->next;
	current->next = (*head)->next;
	current->prev = *head;
	(*head)->next = current;
	(*head)->prev = NULL;
}
