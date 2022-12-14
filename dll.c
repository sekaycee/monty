#include "monty.h"

/**
 *add_dnodeint_end - add a node at end of the doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tmp, *aux;

	if (!head)
		return (0);

	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_gvar();
		exit(EXIT_FAILURE);
	}

	tmp->n = n;
	/* first time ch3ck */
	if (!*head)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}

	aux = *head;
	while (aux->next)
		aux = aux->next;
	tmp->next = aux->next;
	tmp->prev = aux;
	aux->next = tmp;
	return (aux->next);
}

/**
 *add_dnodeint - add a node at start of the doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *tmp;

	if (!head)
		return (0);

	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_gvar();
		exit(EXIT_FAILURE);
	}

	tmp->n = n;
	/* first time ch3ck */
	if (!*head)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	(*head)->prev = tmp;
	tmp->next = (*head);
	tmp->prev = NULL;
	*head = tmp;
	return (*head);
}

/**
 * free_dlistint - free the doubly linked list
 * @head: head of the list
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head))
	{
		head = head->next;
		free(tmp);
	}
}
