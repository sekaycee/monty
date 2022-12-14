#include "monty.h"

/**
 * _rotl - rotate the bottom and second to the top elements
 * @doubly: head of the linked list
 * @cline: line number;
 */
void _rotl(stack_t **doubly, unsigned int cline)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)cline;

	if (!*doubly || !(*doubly)->next)
		return;

	aux1 = (*doubly)->next;
	aux2 = *doubly;
	for (; aux2->next; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *doubly;
	(*doubly)->next = NULL;
	(*doubly)->prev = aux2;
	*doubly = aux1;
}

/**
 * _rotr - reverse the stack
 * @doubly: head of the linked list
 * @cline: line number
 */
void _rotr(stack_t **doubly, unsigned int cline)
{
	stack_t *aux = NULL;
	(void)cline;

	if (!*doubly || !(*doubly)->next)
		return;

	aux = *doubly;
	for (; aux->next; aux = aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *doubly;
	aux->prev = NULL;
	(*doubly)->prev = aux;
	*doubly = aux;
}
