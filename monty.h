#ifndef MONTY_HEADER
#define MONTY_HEADER
#define _GNU_SOURCE

#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

void nop(stack_t **node, unsigned int line_number);
void push_stack(stack_t **node, unsigned int line_number);
void find_function(char *opcode, char *value, unsigned int line_number);
void print_stack(stack_t **node, unsigned int line_number);
void print_top(stack_t **node, unsigned int line_number);
void pop_top(stack_t **node, unsigned int line_number);
void swap_top(stack_t **nodze, unsigned int line_number);
void pass_string(char *str, unsigned int line_number);
void free_stack(void);
void pass_string(char *str, unsigned int line_number);
void add_top(stack_t **node, unsigned int line_number);
void sub_top(stack_t **node, unsigned int line_number);
void div_top(stack_t **node, unsigned int line_number);
void mul_top(stack_t **node, unsigned int line_number);
void mod_top(stack_t **node, unsigned int line_number);
void print_char(stack_t **node, unsigned int line_number);
void print_string(stack_t **node, unsigned int line_number);
void rotl(stack_t **node, unsigned int line_number);
void rotr(stack_t **node, unsigned int line_number);

#endif
