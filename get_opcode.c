#include "monty.h"

/**
 * get_opcode - select the correct opcode
 * @opc: opcode passed
 * Return: pointer to the function that executes the opcode
 */
void (*get_opcode(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t operate[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"queue", _queue},
		{"stack", _stack},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; operate[i].opcode; i++)
		if (_strcmp(operate[i].opcode, opc) == 0)
			break;

	return (operate[i].f);
}
