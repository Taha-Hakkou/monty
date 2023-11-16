#include "monty.h"

int is_stack = 1;
char *num = NULL;

/**
 * is_number - checks if a string is a number
 * @n: stringified number
 * Return: 1 if is number, 0 otherwise
 */
int is_number(char *n)
{
	int i = 0;
	char *m;

	if (n && *n)
	{
		if (n[i] == '+' || n[i] == '-')
			m = n + 1;
		for (; m[i]; i++)
			if (m[i] < '0' || m[i] > '9')
				return (0);
		/*
		 * if (n[0] == '-')
		*{min = itoa(INT_MIN);
		*	if (strlen(min) < strlen(n))
		*		return (0);
		*	else if (strlen(min) > strlen(n))
		*		return (1);
		*	for (i = 0; min[i]; i++)
		*		if (min[i] < n[i])
		*			return (0);
		*}else
		*{
		*	max = itoa(INT_MAX);
		*	if (strlen(max) < strlen(m))
		*		return (0);
		*	else if (strlen(max) > strlen(m))
		*		return (1);
		*	for (i = 0; max[i]; i++)
		*		if (max[i] < m[i])
		*			return (0);}
		*/
		return (1);
	}
	return (0);
}

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
		if (!is_number(num))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		node->n = atoi(num);
		if (*stack)
		{
			if (is_stack)
			{
				node->next = NULL;
				for (tmp = *stack; tmp->next; tmp = tmp->next)
					continue;
				node->prev = tmp;
				tmp->next = node;
			} else
			{
				node->prev = NULL;
				for (tmp = *stack; tmp->next; tmp = tmp->next)
					continue;
				node->next = tmp;
				tmp->prev = node;
			}
		} else
		{
			node->prev = NULL;
			node->next = NULL;
			*stack = node;
		}
	} else
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
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
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
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

/**
 * free_stack - frees a stack
 * @stack: stack to free
 * Return: Nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp;

	if (*stack)
	{
		tmp = *stack;
		while (tmp->prev)
			tmp = tmp->prev;
		while (tmp->next)
		{
			tmp = tmp->next;
			free(tmp->prev);
		}
		free(tmp);
		*stack = NULL;
	}
}
