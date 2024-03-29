#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globals - struct global to share in functions within files
 * @arg: second tokenizer number inside line
 * @head: poiter doubly linked list
 * @current_line: current line
 * @buffer: first tokenizer opcode name inside line
 * @fd: file descriptor
 */
typedef struct var_gl
{
	char *arg;
	stack_t *head;
	unsigned int current_line;
	char *buffer;
	FILE *fd;
} var_gl_t;


extern var_gl_t vl;

void func_push(stack_t **head, unsigned int line_number);
void func_pall(stack_t **head, unsigned int line_number);
void func_pint(stack_t **head, unsigned int line_number);
void func_pop(stack_t **head, unsigned int line_number);
void func_swap(stack_t **head, unsigned int line_number);
void func_nop(stack_t **head, unsigned int line_number);
void func_add(stack_t **head, unsigned int line_number);
void func_sub(stack_t **head, unsigned int line_number);

/*get function*/
void (*func_opc(char *opfn))(stack_t **stack, unsigned int line_number);


stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);
int tokenizer(void);

#endif
