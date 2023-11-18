#include "monty.h"

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
		m = n;
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
