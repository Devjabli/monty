#define _POSIX_C_SOURCE 200809L
#include "monty.h"


var_gl_t vl;

/**
 * main - entry point
 * @argc: counter of args
 * @argv: number of value
 *
 * Return: (0)
*/

int main(int ac, char *av[])
{
	FILE *fd;
	size_t size = sizeof(fd);

	if (ac == 1 || ac > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	vl.current_line = 1;
	vl.arg = NULL;
	vl.head = NULL;
	vl.fd = fd;
	vl.buffer = NULL;

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&vl.buffer, &size, fd) != -1)
	{
		tokenizer();
		vl.current_line++;
	}
	free_dlistint(vl.head);
	free(vl.buffer);
	fclose(vl.fd);
	return (0);
}
