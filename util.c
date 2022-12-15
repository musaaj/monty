#include "monty.h"

/**
 * isnumber - check whether a string can be consist of
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
	while (s[i])
	{
		if (!isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
