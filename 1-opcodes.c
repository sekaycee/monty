#include "monty.h"

/**
 * _queue - set the format of the data to a queue (FIFO)
 * @doubly: head of the linked list
 * @cline: line number;
 */
void _queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	gvar.lifo = 0;
}

/**
 * _stack - set the format of the data to a stack (LIFO)
 * @doubly: head of the linked list
 * @cline: line number;
 */
void _stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	gvar.lifo = 1;
}

/**
 * _add - add the top two elements of the stack
 * @doubly: head of the linked list
 * @cline: line number;
 */
void _add(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;
	for (; aux; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_gvar();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _nop - do nothing
 * @doubly: head of the linked list
 * @cline: line number;
 */
void _nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}

/**
 * _sub - subtract the top two elements of the stack
 * @doubly: head of the linked list
 * @cline: line number;
 */
void _sub(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;
	for (; aux; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_gvar();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n -= (*doubly)->n;
	_pop(doubly, cline);
}
