#include "monty.h"

/**
 * func_opc - choose the right one for excute
 *
 * @opc: opcode func
 *
 * Return: function pointer
 */
void (*func_opc(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", func_push},
		{"pall", func_pall},
		{"pint", func_pint},
		{"pop", func_pop},
		{"swap", func_swap},
		{NULL, NULL}};
	int i = 0;

	while (instruct[i].opcode)
	{
		if (strcmp(instruct[i].opcode, opc) == 0)
			break;
		i++;
	}

	return (instruct[i].f);
}
