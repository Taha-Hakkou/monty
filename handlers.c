#include "monty.h"

/**
 * opcode_handler - handles opcodes
 * @opcode: opcode to handle
 * Return: Nothing
 */
void (*opcode_handler(const char *opcode))(stack_t **, unsigned int)
{
	instruction_t instructions[] = {
		{"pall", pall},
		{"pint", pint},
		{"pchar", pchar},
		{"pstr", pstr},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", div2},/*div in stdlib*/
		{"mod", mod},
		{"swap", swap},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{"push", push},
		{"pop", pop},
		{"nop", nop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode; i++)
		if (!strcmp(opcode, instructions[i].opcode))
			return (instructions[i].f);
	return (NULL);
}

/**
 * error_handler - handles error messages
 * @error_message: message to display
 * @line_number: error line number
 * Return: Nothing
 */
void error_handler(char *error_message, unsigned int line_number)
{
	char *error;

	error = malloc(64 * sizeof(char));
	sprintf(error, error_message, line_number);
	write(STDERR_FILENO, error, strlen(error));
	exit(EXIT_FAILURE);
}
