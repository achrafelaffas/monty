#include "monty.h"


/**
 * pop_top - Adds a node to the stack.
 *
 * @node: Pointer to a pointer pointing to node the top node.
 * @line_number: Interger representing the line number of the opcode.
 */
void pop_top(stack_t **node, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;

	if (node == NULL || *node == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *node;
	*node = tmp->next;
	if (*node != NULL)
		(*node)->prev = NULL;
	free(tmp);
}

/**
 * swap_top - Swaps the top two elements of the stack.
 *
 * @node: Pointer to a pointer pointing to node the top node.
 * @line_number: Interger representing the line number of the opcode.
 */
void swap_top(stack_t **node, unsigned int line_number)
{
	stack_t *tmp;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*node)->next;
	(*node)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *node;
	tmp->next = *node;
	(*node)->prev = tmp;
	tmp->prev = NULL;
	*node = tmp;
}

/**
 * add_top - Adds the top two elements of the stack.
 *
 * @node: Pointer to a pointer pointing to top node.
 * @line_number: Interger representing the line number of the opcode.
 */
void add_top(stack_t **node, unsigned int line_number)
{
	int sum;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*node) = (*node)->next;
	sum = (*node)->n + (*node)->prev->n;
	(*node)->n = sum;
	free((*node)->prev);
	(*node)->prev = NULL;
}

/**
 * sub_top - subtracts the top two elements of the stack.
 * @node: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of the opcode.
 */
void sub_top(stack_t **node, unsigned int line_number)
{
	int sub;

	if (*node == NULL || (*node)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}


	(*node) = (*node)->next;
	sub = (*node)->n - (*node)->prev->n;
	(*node)->n = sub;
	free((*node)->prev);
	(*node)->prev = NULL;
}


/**
 * div_top - divides the top two elements of the stack.
 * @node: Pointer to a pointer pointing to top node.
 * @line_number: Interger representing the line number of the opcode.
 */
void div_top(stack_t **node, unsigned int line_number)
{
	int div;

	if (*node == NULL || (*node)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (*node == NULL || (*node)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*node) = (*node)->next;
	div = (*node)->n / (*node)->prev->n;
	(*node)->n = div;
	free((*node)->prev);
	(*node)->prev = NULL;
}
