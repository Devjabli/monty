#include "monty.h"

/**
 * func_opc - choose the right one for excute
 *
 * @opfn: opcode func
 *
 * Return: function pointer
 */

void (*func_opc(char *opfn))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct_op[] = {
		{"push", func_push},
		{"pall", func_pall},
		{"pint", func_pint},
		{"pop", func_pop},
		{"swap", func_swap},
		{"add", func_add},
		{"nop", func_nop},
		{"sub", func_sub},
		{"div", func_div},
		{"mul", func_mul},
		{NULL, NULL}};

	int i = 0;
	int found = 0;

	while (instruct_op[i].opcode && !found)
	{
		switch (strcmp(instruct_op[i].opcode, opfn))
		{
		case 0:
			found = 1;
			break;
		default:
			i++;
			break;
		}
	}
	return (found ? instruct_op[i].f : NULL);
}

/**
 * func_nop - return nothing
 * @head: head of the linked list
 * @line_number: line number
 *
 * Return: return nothing
 */

void func_nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

/**
 * func_add - adding two element on the top of the stack
 *
 * @head: pointer head of the linked list
 * @line_number: line number;
 * Return: no return
 */

void func_add(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = (*head)->next;
	current->n += (*head)->n;

	free(*head);

	*head = current;
	(*head)->prev = NULL;
}

/**
 * func_sub - subing two element on the top of the stack
 *
 * @head: pointer head of the linked list
 * @line_number: line number;
 * Return: no return
 */

void func_sub(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = (*head)->next;
	current->n -= (*head)->n;

	free(*head);

	*head = current;
	(*head)->prev = NULL;
}

/**
 * func_div - divading two element on the top of the stack
 *
 * @head: pointer head of the linked list
 * @line_number: line number;
 * Return: no return
 */

void func_div(stack_t **head, unsigned int line_number)
{
	stack_t *current = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_dlistint(vl.head);
		free(vl.buffer);
		fclose(vl.fd);
		exit(EXIT_FAILURE);
	}

	current = (*head)->next;
	current->n /= (*head)->n;

	free(*head);

	*head = current;
	(*head)->prev = NULL;
}
