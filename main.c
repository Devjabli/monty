#include "monty.h"

var_gl_t vl;

/**
 * main - entry point
 * @argc: counter of args
 * @argv: number of value
 *
 * Return: (0)
*/

int main(int argc, char *argv[])
{
	FILE *fd;
	size_t size = sizeof(fd);

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	vl.current_line = 1;
	vl.arg = NULL;
	vl.head = NULL;
	vl.fd = fd;
	vl.buffer = NULL;

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
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
