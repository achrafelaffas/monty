#include "monty.h"

/**
 * nop - Does nothing.
 *
 * @node: the top node.
 * @line: line number of the opcode.
 */
void nop(stack_t **node, unsigned int line)
{
	(void)node;
	(void)line;
}

/**
 * print_top - Prints the top node of the stack.
 *
 * @node: the top node.
 * @line: line number of the opcode.
 */
void print_top(stack_t **node, unsigned int line)
{
	(void)line;

	if (node == NULL || *node == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*node)->n);
}

/**
 * push_stack - Adds a node to the stack front.
 *
 * @node: the new node.
 * @line: line number of the opcode.
 */
void push_stack(stack_t **node, unsigned int line)
{
	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);

	(void)line;

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
 * @node: the head of the list to print
 * @line: line number of the opcode.
 */

void print_stack(stack_t **node, unsigned int line)
{
	stack_t *tempp = *node;

	(void)line;
	if (node == NULL)
		exit(EXIT_FAILURE);

	for (; tempp != NULL;)
	{
		printf("%d\n", tempp->n);
		tempp = tempp->next;
	}
}

/**
 * mul_top - divides the top two elements of the stack.
 * @node: Pointer to a pointer pointing to top node.
 * @line: line number of the opcode.
 */
void mul_top(stack_t **node, unsigned int line)
{
	int mull;

	if (*node == NULL || (*node)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	(*node) = (*node)->next;
	mull = (*node)->n * (*node)->prev->n;
	(*node)->n = mull;
	free((*node)->prev);
	(*node)->prev = NULL;
}
