#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stddef.h>
#define BUF_SIZE 10240
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *freadln(FILE *, char buffer[]);
void interprate(char *line, stack_t **, unsigned int line_number);
void interprater(char *filename);
void set_ins(char *opcode, void (*f)(stack_t **, unsigned int), unsigned int idx);
void _init_(void);
void _execute(char *opcode, stack_t **s, unsigned int linenumber);

/*Util functions*/
unsigned int isnumber(char *s);
void free_ins(instruction_t *ops[]);
void cleanup(const char *msg, stack_t *s, unsigned int lnnumber);
void free_mem(stack_t *s);

/*stack functions*/
stack_t *push_stack(stack_t **head, int n);
stack_t *append_stack(stack_t **head, int n);
int delete_stack(stack_t **head, unsigned int index);
void free_stack(stack_t *head);
size_t print_stack_all(stack_t *h);
size_t get_stack_len(stack_t *h);
stack_t *get_stack_by_index(stack_t *head, unsigned int index);

/*instructions functions*/
void _push(stack_t **head, unsigned int linenumber);
void _pall(stack_t **head, unsigned int linenumber);
void _pint(stack_t **head, unsigned int linenumber);
void _pop(stack_t **head, unsigned int linenumber);
void _swap(stack_t **head, unsigned int linenumber);
void _add(stack_t **head, unsigned int linenumber);
void _nop(stack_t **head, unsigned int linenumber);
void _sub(stack_t **head, unsigned int linenumber);
void _div(stack_t **head, unsigned int linenumber);
void _mod(stack_t **head, unsigned int linenumber);
void _mul(stack_t **head, unsigned int linenumber);
void _pchar(stack_t **head, unsigned int linenumber);

extern instruction_t *op[200];
#endif
