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
	{
		fprintf(stderr, "L%u: usage: push integer\n", linenumber);
		exit(EXIT_FAILURE);
	}
	arg = atoi(data);
	s = push_stack(head, arg);
	if (!s)
	{
		fprintf(stderr, "Error: can't malloc\n");
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
