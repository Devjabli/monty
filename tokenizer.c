#include "monty.h"

/**
 * tokenizer - function tokenizing lines and return opcode and args
 * Return: (0);
 */

int tokenizer(void)
{
	void (*f)(stack_t **stack, unsigned int line_number);
	char *str[2];

	str[0] = strtok(vl.buffer, " \t\n");
	if (str[0] && str[0][0] != '#')
	{
		f = func_opc(str[0]);
		if (!f)
		{
			fprintf(stderr, "L%u: ", vl.current_line);
			fprintf(stderr, "unknown instruction %s\n", str[0]);
			fclose(vl.fd);
			exit(EXIT_FAILURE);
		}
		vl.arg = strtok(NULL, " \t\n");
		f(&vl.head, vl.current_line);
	}
	return (0);
}


/**
 * func_mul - multiplying two element on the top of the stack
 *
 * @head: pointer head of the linked list
 * @line_number: line number;
 * Return: no return
 */

void func_mul(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_dlistint(vl.head);
		fclose(vl.fd);
		exit(EXIT_FAILURE);
	}

	current = (*head)->next;
	current->next->n *= (*head)->n;

	free(*head);

	*head = current;
	(*head)->prev = NULL;
}
