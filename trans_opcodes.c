#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: opcodes stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int n;

	if (*stack && ((*stack)->next || (*stack)->prev))
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		n = tmp->prev->n;
		tmp->prev->n = tmp->n;
		tmp->n = n;
	}
	else
		error_handler("L%d: can't swap, stack too short\n", line_number);
}

/**
 * rotl - rotates the stack to the top
 *		The top element of the stack becomes the last one,
 *		and the second top element of the stack becomes the first one
 * @stack: opcodes stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1, *tmp2;

	(void)line_number;
	if (*stack) /* works for 1 node as well */
	{
		for (tmp1 = *stack; tmp1->prev; tmp1 = tmp1->prev)
			continue;
		for (tmp2 = *stack; tmp2->next; tmp2 = tmp2->next)
			continue;
		tmp1->prev = tmp2;
		tmp2->next = tmp1;
		tmp2->prev->next = NULL;
		tmp2->prev = NULL;
	}
}

/**
 * rotr - rotates the stack to the bottom
 *	The last element of the stack becomes the top element of the stack
 * @stack: opcodes stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1, *tmp2;

	(void)line_number;
	if (*stack) /* works for 1 node as well */
	{
		for (tmp1 = *stack; tmp1->prev; tmp1 = tmp1->prev)
			continue;
		for (tmp2 = *stack; tmp2->next; tmp2 = tmp2->next)
			continue;
		tmp1->prev = tmp2;
		tmp2->next = tmp1;
		tmp1->next->prev = NULL;
		tmp1->next = NULL;
	}
}

/**
 * stack - sets the format of the data to a stack (LIFO).
 *		This is the default behavior of the program
 *		The front of the queue becomes the top of the stack
 * @stack: opcodes stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)*stack;
	(void)line_number;
	is_stack = 1;
}

/**
/bin/bash: line 1: q: command not found
 *		The top of the stack becomes the front of the queue
 * @stack: opcodes stack
 * @line_number: opcodes line number
 * Return: Nothing
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)*stack;/*  can destroy stack, w/ * or not ? , also for stack()*/
	(void)line_number;
	is_stack = 0;
}
