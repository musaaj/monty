#include "monty.h"

/**
 * _pchar - print the ascii char equivalent of the
 * top element in stack
 * @head: address of head of the stack
 * @linenumber: line number of the opcode
*/
void _pchar(stack_t **head, unsigned int linenumber)
{
	int c;

	if (*head)
	{
		c = (*head)->n;
		if (c < 0 || c > 127)
		{
			fprintf(stderr,
			"L%u: can't pchar, value out of range\n",
			linenumber);
			exit(EXIT_FAILURE);
		}
		putchar(c);
		putchar('\n');
		return;
	}
	fprintf(stderr, "L%u: can't pchar, stack empty", linenumber);
	exit(EXIT_FAILURE);
}

/**
 * _nop - does nothing
 * @head: address of head of the stack
 * @linenumber: line number of the opcode
*/
void _nop(stack_t **head, unsigned int linenumber)
{
	(void)head;
	(void)linenumber;
}
