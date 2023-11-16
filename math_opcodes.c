#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: opcodes stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack && ((*stack)->next || (*stack)->prev))
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->prev->n += tmp->n;
		tmp->prev->next = NULL;
		free(tmp);
	}
	else
		error_handler("L%d: can't add, stack too short\n", line_number);
}

/**
 * sub - subtracts the top element of the stack
 *		from the second top element of the stack
 * @stack: opcodes stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack && ((*stack)->next || (*stack)->prev))
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->prev->n -= tmp->n;
		tmp->prev->next = NULL;
		free(tmp);
	}
	else
		error_handler("L%d: can't sub, stack too short\n", line_number);
}

/**
 * mul - multiplies the second top element of the stack
 *		with the top element of the stack
 * @stack: opcodes stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack && ((*stack)->next || (*stack)->prev))
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->prev->n *= tmp->n;
		tmp->prev->next = NULL;
		free(tmp);
	}
	else
		error_handler("L%d: can't mul, stack too short\n", line_number);
}

/**
 * div2 - divides the second top element of the stack
 *		by the top element of the stack
 * @stack: opcodes stack
 * @line_number: stack line number
 * Return: Nothing
 */
void div2(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack && ((*stack)->next || (*stack)->prev))
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		if (tmp->n)
		{
			tmp->prev->n /= tmp->n;
			tmp->prev->next = NULL;
			free(tmp);
		}
		else
			error_handler("L%d: division by zero\n", line_number);
	}
	else
		error_handler("L%d: can't div, stack too short\n", line_number);
}

/**
 * mod - computes the rest of division of second top element of stack
 *		by the top element of the stack
 * @stack: opcodes stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack && ((*stack)->next || (*stack)->prev))
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		if (tmp->n)
		{
			tmp->prev->n %= tmp->n;
			tmp->prev->next = NULL;
			free(tmp);
		}
		else
			error_handler("L%d: division by zero\n", line_number);
	}
	else
		error_handler("L%d: can't mod, stack too short\n", line_number);
}
