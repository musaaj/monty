#include "monty.h"

/**
 * _add - add the two top elements in stack
 * @head: address of head of the stack
 * @linenumber: line number of the opcode
*/
void _add(stack_t **head, unsigned int linenumber)
{
	if (*head && (*head)->next)
	{
		((*head)->next)->n += (*head)->n;
		_pop(head, linenumber);
		return;
	}
	fprintf(stderr, "L%u: can't add, stack too short\n", linenumber);
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
