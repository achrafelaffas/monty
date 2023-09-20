#include "monty.h"

stack_t *head;

/**
 * free_stack - function that frees a stack_t.
 *
 * Return: nothing
 */

void free_stack(void)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * pass_string - passes_string and calls the necesarry functions
 * @str: string to pass
 * @line_number: Interger representing the line number of of the opcode.
 * Return: nothing
 */

void pass_string(char *str, unsigned int line_number)
{
	char *value;
	char *opcode;

	value = strtok(str, "\n \t\r");
	opcode = value;
	if (opcode == NULL)
		return;

	value = strtok(NULL, "\n \t\r");


	find_function(opcode, value, line_number);
}

/**
 * read_file - reads monty byte file
 * @filename: file name to read
 * Returns: nothing
 */

void read_file(char *filename)
{
	FILE *fd;
	char *line_read;
	size_t buffer_size;
	unsigned int line_num;
	int len;

	fd = fopen(filename, "r");
	if (fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	line_read = NULL;
	for (line_num = 1; (len = getline(&line_read,
		&buffer_size, fd)) != -1 ; line_num++)
		pass_string(line_read, line_num);

	free(line_read);
	fclose(fd);
}


/**
 * main - entry point of the program
 * @argc: number of arguments passed
 * @argv: array of Strings of arguments
 * Return: integer
 */
int main(int argc, char **argv)
{

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(argv[1]);
	free_stack();
	return (EXIT_SUCCESS);
}

