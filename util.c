#include "monty.h"

/**
 * isnumber - check whether a string consist of
 * only digits
 * @s: string
 * Return: 1 if @s consist of only digits else 0
*/
unsigned int isnumber(char *s)
{
	unsigned int i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (!isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * free_ins - free the opcode array
 * @ops: opcode array
*/
void free_ins(instruction_t *ops[])
{
	unsigned int i = 0;

	while (ops[i] != NULL)
	{
		free((ops[i])->opcode);
		free(ops[i]);
		i++;
	}
}

/**
 * cleanup - free allocated memory, display error msg and exit
 * @msg: error message to display
 * @s: address of stack
 * @lnnumber: line number of opcode where the error occure
*/
void cleanup(const char *msg, stack_t *s, unsigned int lnnumber)
{
	fprintf(stderr, msg, lnnumber);
	free_mem(s);
	exit(EXIT_FAILURE);
}

/**
 * free_mem - free allocated memory
 * @s: address of stack
*/
void free_mem(stack_t *s)
{
	free_stack(s);
	free_ins(op);
}
