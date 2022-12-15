#include "monty.h"

/**
 * freadln - read one line from a file pointer
 * @fp: file pointer to read from
 * Return: a line of null terminated string
 * on error return NULL
 */
char *freadln(FILE *fp)
{
	int i = 0, c;
	char buffer[BUF_SIZE];

	c = fgetc(fp);
	while (c != EOF)
	{
		if (c == '\n')
		{
			buffer[i] = '\0';
			return  (strdup(buffer));
		}
		buffer[i++] = c;
		c = fgetc(fp);
	}
	return (NULL);
}
