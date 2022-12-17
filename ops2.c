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
	free_mem(*head);
	exit(EXIT_FAILURE);
}

/**
 * _sub - subtract the top element in the stack
 * from the second top element
 * @head: address of head of the stack
 * @linenumber: line number of the opcode
*/
void _sub(stack_t **head, unsigned int linenumber)
{
	if (*head && (*head)->next)
	{
		((*head)->next)->n -= (*head)->n;
		_pop(head, linenumber);
		return;
	}
	fprintf(stderr, "L%u: can't sub, stack too short\n", linenumber);
	free_mem(*head);
	exit(EXIT_FAILURE);
}

/**
 * _mul - multiply the two top elements in stack
 * @head: address of head of the stack
 * @linenumber: line number of the opcode
*/
void _mul(stack_t **head, unsigned int linenumber)
{
	if (*head && (*head)->next)
	{
		((*head)->next)->n *= (*head)->n;
		_pop(head, linenumber);
		return;
	}
	fprintf(stderr, "L%u: can't mul, stack too short\n", linenumber);
	free_mem(*head);
	exit(EXIT_FAILURE);
}

/**
 * _div - divide the second top element
 * in the stack by the top element
 * @head: address of head of the stack
 * @linenumber: line number of the opcode
*/
void _div(stack_t **head, unsigned int linenumber)
{
	if (*head && (*head)->next)
	{
		if ((*head)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", linenumber);
			free_mem(*head);
			exit(EXIT_FAILURE);
		}
		((*head)->next)->n /= (*head)->n;
		_pop(head, linenumber);
		return;
	}
	fprintf(stderr, "L%u: can't div, stack too short\n", linenumber);
	free_mem(*head);
	exit(EXIT_FAILURE);
}

/**
 * _mod - find the remainder of dividing
 * the second top element in the stack
 * by the top element
 * @head: address of head of the stack
 * @linenumber: line number of the opcode
*/
void _mod(stack_t **head, unsigned int linenumber)
{
	if (*head && (*head)->next)
	{
		if ((*head)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", linenumber);
			free_mem(*head);
			exit(EXIT_FAILURE);
		}
		((*head)->next)->n %= (*head)->n;
		_pop(head, linenumber);
		return;
	}
	fprintf(stderr, "L%u: can't mod, stack too short\n", linenumber);
	free_mem(*head);
	exit(EXIT_FAILURE);
}
