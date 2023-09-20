#include "monty.h"

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
