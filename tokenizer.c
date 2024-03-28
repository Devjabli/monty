#include "monty.h"

/**
 * tokenizer - function tokenizing lines and return opcode and args
 * Return: Void
*/

void *tokenizer()
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
			free_dlistint(vl.head);
			free(vl.buffer);
			fclose(vl.fd);
			exit(EXIT_FAILURE);
		}
		vl.arg = strtok(NULL, " \t\n");
		f(&vl.head, vl.current_line);
	}
}
