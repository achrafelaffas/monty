#include "monty.h"

/**
 * print_top
 *
 * @node:
 * @line:
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
 * push_stack
 *
 * @node:
 * @line:
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
 * print_stack
 *
 *
 * @node:
 * @line:
 */

void print_stack(stack_t **node, unsigned int line)
{
	stack_t *temp = *node;

	(void)line;
	if (node == NULL)
		exit(EXIT_FAILURE);

	for (; temp != NULL;)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * mul_top
 * @node:
 * @line:
 */
void mul_top(stack_t **node, unsigned int line)
{
	int mul;

	if (*node == NULL || (*node)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	(*node) = (*node)->next;
	mul = (*node)->n * (*node)->prev->n;
	(*node)->n = mul;
	free((*node)->prev);
	(*node)->prev = NULL;
}

/**
 * nop
 *
 * @node:
 * @line:
 */
void nop(stack_t **node, unsigned int line)
{
	(void)node;
	(void)line;
}
