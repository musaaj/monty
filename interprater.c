#include "monty.h"
instruction_t *op[200];

/**
 * interprater - driver for the program
 * @filename: name of file to interprate
*/
void interprater(char *filename)
{
	char *line;
	FILE *fp;
	unsigned int linenumber = 1;
	stack_t *stack = NULL;

	fp = fopen(filename, "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Cant't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	line = freadln(fp);
	while (line)
	{
		interprate(line, &stack, linenumber);
		free(line);
		line = freadln(fp);
		linenumber++;
	}
	fclose(fp);
	free_stack(stack);
}

/**
 * interprate - interprates a line of instruction
 * @line: the line the interprate
 * @stack: address of stack
 * @linenumber: line number of @line
*/
void interprate(char *line, stack_t **stack, unsigned int linenumber)
{
	char *optcode;

	optcode = strtok(line, " \t\n");
	if (optcode)
	{
		_execute(optcode, stack, linenumber);
	}
}

/**
 * set_ins - set function for a giving opcode
 * @opcode: opcode to set
 * @f: function to set
 * @idx: index to put @f in
*/
void set_ins(char *opcode, void (*f)(stack_t **, unsigned int),
unsigned int idx)
{
	instruction_t *ins;

	ins = malloc(sizeof(instruction_t));
	if (!ins)
	{
		fprintf(stderr, "Error: cant't malloc\n");
		exit(EXIT_FAILURE);
	}
	ins->f = f;
	ins->opcode = strdup(opcode);
	op[idx] = ins;
}

/**
 * _init_ - initiate opcode functions
*/
void _init_(void)
{
	int idx = 0;

	set_ins("push", &_push, idx++);
	set_ins("pall", &_pall, idx++);
	set_ins("pint", &_pint, idx++);
	set_ins("pop", &_pop, idx++);
	set_ins("swap", &_swap, idx++);
	set_ins("add", &_add, idx++);
	set_ins("sub", &_sub, idx++);
	set_ins("nop", &_nop, idx++);
	set_ins("mul", &_mul, idx++);
	set_ins("div", &_div, idx++);
	set_ins("mod", &_mod, idx++);
	op[idx] = NULL;
}

/**
 * _execute - execute an opcode function
 * @opcode: instruction to execute
 * @s: address of stack
 * @linenumber: line number of the opcode
*/
void _execute(char *opcode, stack_t **s, unsigned int linenumber)
{
	unsigned int i = 0;

	while (op[i] != NULL)
	{
		if ((strcmp(opcode, (op[i])->opcode)) == 0)
		{
			(op[i])->f(s, linenumber);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", linenumber, opcode);
	exit(EXIT_FAILURE);
}
