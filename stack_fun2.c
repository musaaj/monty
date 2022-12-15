#include "monty.h"
/**
 * print_stack_all - prints elements of a stack_t object
 * @h: head node of a stack_t object
 * Return: size_t number of elements printed
 */
size_t print_stack_all(stack_t *h)
{
	stack_t *tmp;
	size_t i;

	if (!h)
		return (0);
	tmp = h;
	i = 0;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

/**
 * get_stack_len - find number of elements in a stack_t object
 * @h: head node of a stack_t object
 * Return: size_t number of elements in a stack_t object
 */
size_t get_stack_len(stack_t *h)
{
	size_t len;
	stack_t *tmp;

	len = 0;
	if (!h)
		return (0);
	tmp = h;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

/**
 * get_stack_by_index - get element of a stack_t object by index
 * @head: head node of the stack_t object
 * @index: index of the node to be gotten
 * Return: not at @index if it exist else NULL
 */
stack_t *get_stack_by_index(stack_t *head, unsigned int index)
{
	stack_t *tmp;
	unsigned int i;

	if (!head)
		return (NULL);
	tmp = head;
	i = 0;
	while (tmp)
	{
		if (i == index)
			return (tmp);
		tmp = tmp->next;
		i++;
	}
	return (NULL);
}
