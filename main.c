#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
char *token;
int value;

token = strtok(NULL, " \n");
if (token == NULL)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

value = atoi(token);

stack_t *new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack != NULL)
(*stack)->prev = new_node;

*stack = new_node;
}


void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;

while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}


int main(void)
{
char *line = NULL;
size_t len = 0;
stack_t *stack = NULL;
unsigned int line_number = 0;

instruction_t instructions[] = {
{"push", push},
{"pall", pall},
{NULL, NULL}
};

while (getline(&line, &len, stdin) != -1)
{
line_number++;
char *opcode = strtok(line, " \n");
int found = 0;

if (opcode != NULL)
{
for (int i = 0; instructions[i].opcode != NULL; i++)
{
if (strcmp(opcode, instructions[i].opcode) == 0)
{
instructions[i].f(&stack, line_number);
found = 1;
break;
}
}

if (!found)
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
free(line);
exit(EXIT_FAILURE);
}
}
}

free(line);
exit(EXIT_SUCCESS);
}
