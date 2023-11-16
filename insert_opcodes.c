#include "monty.h"

int is_stack = 1;
char *num = NULL;

/**
 * push - pushes an element to the stack
 *		  print error msg & exit (status: EXIT_FAILURE) for non-integer or no arg
 * @stack: opcodes stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node, *tmp;

	node = malloc(sizeof(stack_t));
	if (node)
	{
		node->n = atoi(num); /* atoi - no to deal w/ overflows */
		if (!(node->n) && *num != '0'/* not int or no arg */)
			error_handler("L%d: usage: push integer\n", line_number);
		if (*stack)
		{
			if (is_stack)
			{
				node->next = NULL;
				for (tmp = *stack; tmp->next; tmp = tmp->next)
					continue;
				node->prev = tmp;
				tmp->next = node;
			}
			else
			{
				node->prev = NULL;
				for (tmp = *stack; tmp->next; tmp = tmp->next)
					continue;
				node->next = tmp;
				tmp->prev = node;
			}
		}
		else
		{
			node->prev = NULL;
			node->next = NULL;
			*stack = node;
		}
	}
	else
		error_handler("Error: malloc failed\n", line_number);
}

/**
 * pop - removes the top element of the stack
 *		 print error msg & exit (status: EXIT_FAILURE) if stack is empty
 * @stack: opcodes stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	/*need to implement is_stack gv*/
	if (*stack)
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		free(tmp);
	}
	else
		error_handler("L%d: can't pop an empty stack\n", line_number);
}

/**
 * nop - doesn’t do anything
 * @stack: opcodes stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
