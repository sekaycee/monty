#include "monty.h"

/**
 * _push - push an element to the stack
 * @doubly: head of the linked list
 * @cline: line number
 */
void _push(stack_t **doubly, unsigned int cline)
{
	int n, j;

	if (!gvar.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_gvar();
		exit(EXIT_FAILURE);
	}

	for (j = 0; vglo.arg[j] != '\0'; j++)
	{
		if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_gvar();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(gvar.arg);
	if (gvar.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
 * _pall - print all values on the stack
 * @doubly: head of the linked list
 * @cline: line numbers
 */
void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;
	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _pint - print the value at the top of the stack
 * @doubly: head of the linked list
 * @cline: line number
 */
void _pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (!*doubly)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "can't pint, stack empty\n");
		free_gvar();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 * _pop - remove the top element of the stack
 * @doubly: head of the linked list
 * @cline: line number
 */
void _pop(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;

	if (!doubly || !*doubly)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		free_gvar();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}

/**
 * _swap - swap the top two elements of the stack
 * @doubly: head of the linked list
 * @cline: line number
 */
void _swap(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;
	for (; aux; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		free_gvar();
		exit(EXIT_FAILURE);
	}

	aux = *doubly;
	*doubly = (*doubly)->next;
	aux->next = (*doubly)->next;
	aux->prev = *doubly;
	(*doubly)->next = aux;
	(*doubly)->prev = NULL;
}
