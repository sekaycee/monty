#include "monty.h"

global_t gvar;

/**
 * free_gvar - free the global variables
 */
void free_gvar(void)
{
	free_dlistint(gvar.head);
	free(gvar.buffer);
	fclose(gvar.fd);
}

/**
 * start_gvar - initialize the global variables
 * @fd: file descriptor
 */
void start_gvar(FILE *fd)
{
	gvar.lifo = 1;
	gvar.cont = 1;
	gvar.arg = NULL;
	gvar.head = NULL;
	gvar.fd = fd;
	gvar.buffer = NULL;
}

/**
 * check_input - check if file exists and can be opened
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (!fd)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_gvar(fd);
	nlines = getline(&gvar.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _strtoky(gvar.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcode(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", gvar.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_gvar();
				exit(EXIT_FAILURE);
			}
			gvar.arg = _strtoky(NULL, " \t\n");
			f(&gvar.head, gvar.cont);
		}
		nlines = getline(&gvar.buffer, &size, fd);
		gvar.cont++;
	}

	free_gvar();
	return (0);
}
