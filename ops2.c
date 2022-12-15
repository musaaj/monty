#include "monty.h"

/**
 * _add - add the two top elements in stack
 * @head: address of head of the stack
 * @linenumber: line number of the opcode
*/
void _add(stack_t **head, unsigned int linenumber)
{
	((*head)->next)->n += (*head)->n;
	_pop(head, linenumber);
}
