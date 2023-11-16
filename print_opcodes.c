#include "monty.h"

/**
 * pall - prints all the values on the stack,
 *			starting from the top of the stack
 *		  If the stack is empty, don’t print anything
 * @stack: opcodes stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number; /*unused*/
	if (*stack)
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		while (tmp->prev)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->prev;
		}
		printf("%d\n", tmp->n); /*try to reduce instructions*/
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line
 *		  If stack is empty, print error message & exit (status: EXIT_FAILURE)
 * @stack: opcodes stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack)
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		printf("%d\n", tmp->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 *		   char = ascii representation
 *		   print error msg & exit (EXIT_FAILURE) for non-valid ascii or empty stack
 * @stack: opcodes stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack)
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		if (tmp->n >= 0 && tmp->n < 128)
			printf("%c\n", tmp->n);
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - prints the string starting at the top of the stack,
 *			followed by a new line
 *		  string stops if stack is over, null-byte, or non-valid ascii
 * @stack: opcodes stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (*stack)
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		while (tmp->prev && tmp->n > 0 && tmp->n < 128)
		{
			printf("%c", tmp->n);
			tmp = tmp->prev;
		}
	}
	printf("\n");
}
