#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE /*getline was giving a implicit declaration error*/

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

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


extern int is_stack;
extern char *num;

void stack_init(stack_t **);
void run(stack_t **, char *, unsigned int);
void free_stack(stack_t **);

void (*opcode_handler(const char *opcode))(stack_t **, unsigned int);
void error_handler(char *, unsigned int);

int is_number(char *);
/*----------------------- Opcodes -------------------------*/
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);

void add(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
/* 'div' already defined in stdlib */
void div2(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);

void swap(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);
void stack(stack_t **, unsigned int);
void queue(stack_t **, unsigned int);

void push(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);

#endif /* MONTY_H */
