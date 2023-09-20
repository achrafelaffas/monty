#include "monty.h"

/**
 * create_node - creates nodes for doubly linked lists
 *
 * @value: Interger representing the number to be added to list
 * Return: new node
 */

stack_t *create_node(int value)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/**
 * print_push_error - returns error on push
 *
 * @line_number: Interger representing the line number of of the opcode.
 *
 */
void print_push_error(int line_number)
{
	dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * handle_push - handles the push opcode
 * @value: string to be checked
 * @line_number: Interger representing the line number of of the opcode.
 *
 */
void handle_push(char *value, unsigned int line_number)
{
	int i;

	if (value != NULL && value[0] == '-')
	{
		/* push pointer to the next character */
		value++;
	}

	if (value == NULL)
		print_push_error(line_number);

	for (i = 0; value[i] != '\0'; i++)
		if (isdigit(value[i]) == 0)
			print_push_error(line_number);
}

/**
 * find_function - finds the correct function to execute opcode
 *
 * @opcode: the instruction code
 * @value: value to add to linked list
 * @line_number: Interger representing the line number of of the opcode.
 *
 */
void find_function(char *opcode, char *value, unsigned int line_number)
{
	int i;
	stack_t *node;
	instruction_t funct_list[] = {
		{"push", push_stack}, {"pall", print_stack}, {"pint", print_top},
		{"nop", nop},
		{"pop", pop_top},
		{"swap", swap_top},
		{"div", div_top},
		{"sub", sub_top},
		{"mul", mul_top},
		{"add", add_top},
		{"mod", mod_top},
		{"pchar", print_char},
		{"pstr", print_string},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	if (opcode[0] == '#')
		return;
	if (strcmp(opcode, "push") == 0)
	{
		handle_push(value, line_number);
		node = create_node(atoi(value));
		for (i = 0; funct_list[i].opcode;  i++)
			if (strcmp(funct_list[i].opcode, opcode) == 0)
			{
				funct_list[i].f(&node, line_number);
				return;
			}
	}
	else
		for (i = 0; funct_list[i].opcode;  i++)
			if (strcmp(funct_list[i].opcode, opcode) == 0)
			{
				funct_list[i].f(&head, line_number);
				return;
			}
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

