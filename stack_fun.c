#include "monty.h"

/**
 * push_stack - add a new node at the beginning of a
* stack_t object
* @head: address of address of first element in a
* stack_t object
* @n: value of the node to be added
* Return: stack_t newly added node
 */
stack_t *push_stack(stack_t **head, int n)
{
	stack_t *new_node;

	if (!head)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_mem(*head);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	if (*head)
		(*head)->prev = new_node;
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}
/**
 * append_stack - add new element at the end of a stack_t object
 * @head: address of pointer to the head element of a stack_t object
 * @n: value of the new node
 * Return: pointer to the new node
 */
stack_t *append_stack(stack_t **head, int n)
{
	stack_t *new_node, *tmp;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!(*head))
	{
		*head = new_node;
		return (new_node);
	}
	tmp = *head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	new_node->prev = tmp;
	tmp->next = new_node;
	return (new_node);
}
/**
 * delete_stack - delete an element of a stack_t object
 * @head: pointer to the first node of a stack_t object
 * @index: index of the element to be removed
 * Return: 1 on success else 0
 */
int delete_stack(stack_t **head, unsigned int index)
{
	unsigned int i = 0;
	stack_t *tmp, *dtmp;

	if (index == 0)
	{
		if (*head)
		{
			tmp = *head;
			*head = tmp->next;
			if (*head)
				(*head)->prev = NULL;
			free(tmp);
			return (1);
		}
	}
	dtmp = *head;
	while (dtmp != NULL)
	{
		if (i == index)
		{
			tmp = dtmp;
			(dtmp->prev)->next = tmp->next;
			if (tmp->next)
				(tmp->next)->prev = dtmp->prev;
			free(tmp);
			return (1);
		}
		i++;
		dtmp = dtmp->next;
	}
	return (-1);
}
/**
 * free_stack - release a stack_t object
 * @head: head element of a stack_t object
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	if (!head)
		return;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
