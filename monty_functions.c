#include "monty.h"

/**
 * nop - Does nothing.
 *
 * @node: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of the opcode.
 */
void nop(stack_t **node, unsigned int line_number)
{
	(void)node;
	(void)line_number;
}

/**
 * print_top - Prints the top node of the stack.
 *
 * @node: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of the opcode.
 */
void print_top(stack_t **node, unsigned int line_number)
{
	(void)line_number;

	if (node == NULL || *node == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*node)->n);
}

/**
 * push_stack - Adds a node to the stack front.
 *
 * @node: Pointer to the new node.
 * @line_number: Interger representing the line number of the opcode.
 */
void push_stack(stack_t **node, unsigned int line_number)
{
	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);

	(void)line_number;

	(*node)->prev = NULL;
	(*node)->next = head;
	head = (*node);
	if ((*node)->next != NULL)
		((*node)->next)->prev = (*node);
}

/**
 * print_stack - print a doubly linked lists content
 *
 *
 * @node: pointer to the head of the list to print
 * @line_number: Interger representing the line number of the opcode.
 */

void print_stack(stack_t **node, unsigned int line_number)
{
	stack_t *temp = *node;

	(void)line_number;
	if (node == NULL)
		exit(EXIT_FAILURE);

	for (; temp != NULL;)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * mul_top - divides the top two elements of the stack.
 * @node: Pointer to a pointer pointing to top node.
 * @line_number: Interger representing the line number of the opcode.
 */
void mul_top(stack_t **node, unsigned int line_number)
{
	int mul;

	if (*node == NULL || (*node)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*node) = (*node)->next;
	mul = (*node)->n * (*node)->prev->n;
	(*node)->n = mul;
	free((*node)->prev);
	(*node)->prev = NULL;
}

