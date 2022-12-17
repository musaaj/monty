#include "monty.h"

/**
 * freadln - read one line from a file pointer
 * @fp: file pointer to read from
 * @buffer: char array to read to
 * Return: a line of null terminated string
 * on error return NULL
 */
char *freadln(FILE *fp, char buffer[])
{
	int i = 0, c;

	c = fgetc(fp);
	while (c != EOF)
	{
		if (c == '\n')
		{
			buffer[i] = '\0';
			return  (buffer);
		}
		buffer[i++] = c;
		c = fgetc(fp);
	}
	buffer[i] = '\0';
	if (strlen(buffer))
		return (buffer);
	return ("");
}
