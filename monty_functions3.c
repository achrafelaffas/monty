#include "monty.h"

/**
 * mod_top - Finds the modulus of the top two elements of the stack.
 * @node: Pointer to the top node of the stack.
 * @line_number: Interger representing the line number of the opcode.
 */
void mod_top(stack_t **node, unsigned int line_number)
{
	int mod;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}


	if ((*node)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*node) = (*node)->next;
	mod = (*node)->n % (*node)->prev->n;
	(*node)->n = mod;
	free((*node)->prev);
	(*node)->prev = NULL;
}

/**
 * print_char - Prints the Ascii value.
 *
 *
 * @node: Double pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of the opcode.
 */
void print_char(stack_t **node, unsigned int line_number)
{
	int ch;

	if (node == NULL || *node == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	ch = (*node)->n;
	if (!isascii(ch))
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ch);
}

/**
 * print_string - Prints a string.
 *
 *
 * @node: Double pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of the opcode.
 */
void print_string(stack_t **node, unsigned int line_number)
{
	int ch;
	stack_t *tmp;
	(void)line_number;

	if (node == NULL || *node == NULL)
	{
		putchar('\n');
		return;
	}

	tmp = *node;
	while (tmp != NULL)
	{
		ch = tmp->n;
		if (!isascii(ch) || ch == 0)
			break;
		putchar(ch);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 *
 *
 * @node: Double pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of the opcode.
 */
void rotl(stack_t **node, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (*node == NULL || (*node)->next == NULL)
		return;

	tmp = *node;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *node;
	(*node)->prev = tmp;
	*node = (*node)->next;
	(*node)->prev->next = NULL;
	(*node)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 *
 *
 * @node: Double pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of the opcode.
 */
void rotr(stack_t **node, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (*node == NULL || (*node)->next == NULL)
		return;

	tmp = *node;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *node;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*node)->prev = tmp;
	(*node) = tmp;
}

