#include "monty.h"

/**
 * main - Monty interpreter main routine
 * @argc: args count
 * @argv: args vector
 * Return: Exit status
 */
int main(int argc, char **argv)
{
	stack_t *stack;/* try to use ** */
	char *error;
	FILE *stream;
	size_t n;
	char *instruction;
	unsigned int l;/* line_number */

	if (argc == 2)
	{
		if (access(argv[1]/* pathname */, F_OK | R_OK))
		{
			error = malloc(25 * sizeof(char));
			sprintf(error, "Error: Can't open file %s\n", argv[1]);
			write(STDERR_FILENO, error, strlen(error));
			exit(EXIT_FAILURE);
		}
		else
		{
			stack = NULL;
			stream = fopen(argv[1], "r");
			getline(&instruction, &n, stream);
			for (l = 1; !feof(stream); l++)
			{
				run(&stack, instruction, l);
				getline(&instruction, &n, stream);
			}
			fclose(stream);
			free_stack(&stack);
			return (EXIT_SUCCESS);
		}
	}
	else
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
}

/**
 * run - runs the bytecode (instruction)
 * @stack: opcodes stack
 * @instruction: monty instruction
 * @l: line number
 * Return: Nothing
 */
void run(stack_t **stack, char *instruction, unsigned int l)
{
	char *opcode, *error;
	void (*f)(stack_t **, unsigned int);

	opcode = strtok(instruction, " \n");
	if (opcode)
	{
		/* Comment handler */
		/* A line is treated as a comment when the first non-space character is # */
		if (*opcode == '#')
			return;
		/* get opcode function */
		f = opcode_handler(opcode);
		/* get data for push opcode */
		num = strtok(NULL, " \n");
		/* call opcode function */
		if (f)
			f(stack, l);
		else
		{
			error = malloc(26 * sizeof(char));
			sprintf(error, "L%d: unknown instruction %s\n", l, opcode);
			write(STDERR_FILENO, error, strlen(error));
			exit(EXIT_FAILURE);
		}
	}
}
