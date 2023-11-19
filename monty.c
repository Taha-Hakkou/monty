#include "monty.h"

/**
 * main - Monty interpreter main routine
 * @argc: args count
 * @argv: args vector
 * Return: Exit status
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;/* try to use ** */
	FILE *stream;
	size_t n;
	char *instruction;
	unsigned int l;/* line_number */

	if (argc == 2)
	{
		if (access(argv[1]/* pathname */, F_OK | R_OK))
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			/*stack_init(&stack);*/
			stream = fopen(argv[1], "r");
			getline(&instruction, &n, stream);
			for (l = 1; !feof(stream); l++)
			{
				run(&stack, instruction, l);
				getline(&instruction, &n, stream);
			}
			fclose(stream);
			printf("0\n"); /* instead of stack initialization */
			free_stack(&stack);
			return (EXIT_SUCCESS);
		}
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
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
	char *opcode;
	void (*f)(stack_t **, unsigned int);

	opcode = strtok(instruction, " \n\t");
	if (opcode)
	{
		/* Comment handler */
		/* A line is treated as a comment when the first non-space character is # */
		if (*opcode == '#')
			return;
		/* get opcode function */
		f = opcode_handler(opcode);
		/* get data for push opcode */
		num = strtok(NULL, " \n\t");
		/* call opcode function */
		if (f)
			f(stack, l);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", l, opcode);
			exit(EXIT_FAILURE);
		}
	}
}
