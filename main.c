#include "monty.h"

/**
 * main - main driver of our program
 * @argc: number of arguments passed to our program
 * @argv: array of arguments passed to our program
 * Return: 0 on success else exit with EXIT_FAILURE
*/
int main(int argc, char *argv[])
{
	_init_();
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	interprater(argv[1]);
	return (0);
}
