#include "monty.h"

/**
 * _push - push data to stack_t
 * @head: stack_t
 * @linenumber: int
 */
void _push(stack_t **head, unsigned int linenumber)
{
	char *data;
	int arg;
	stack_t *s;

	data = strtok(NULL, " \t\n");

	if (!isnumber(data))
		cleanup("L%u:usage: push integer\n", *head, linenumber);
	arg = atoi(data);
	s = push_stack(head, arg);
	if (!s)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_mem(*head);
		exit(EXIT_FAILURE);
	}
}

/**
 * _pall - print contents of stack one element par line
 * @head: address of head of the stack
 * @linenumber: line number of the opcode
*/
void _pall(stack_t **head, unsigned int linenumber)
{
	print_stack_all(*head);
	(void)linenumber;
}

/**
 * _pint - print the top element in stack
 * @head: address of head of the stack
 * @linenumber: line number of the opcode
*/
void _pint(stack_t **head, unsigned int linenumber)
{
	if (*head == NULL)
		cleanup("L%u:can't pint, stack empty\n", *head, linenumber);
	printf("%d\n", (*head)->n);
}

/**
 * _pop - remove the top element in stack
 * @head: address of head of the stack
 * @linenumber: line number of the opcode
*/
void _pop(stack_t **head, unsigned int linenumber)
{
	if (*head == NULL)
		cleanup("L%u: can't pop an empty stack\n", *head, linenumber);
	delete_stack(head, 0);
}

/**
 * _swap - swap the two top elements in stack
 * @head: address of head of the stack
 * @linenumber: line number of the opcode
*/
void _swap(stack_t **head, unsigned int linenumber)
{
	int tmp;

	if (!(*head) || !(*head)->next)
		cleanup("L%u: can't swap, stack too short\n", *head, linenumber);
	tmp = (*head)->n;
	(*head)->n = ((*head)->next)->n;
	((*head)->next)->n = tmp;
}
