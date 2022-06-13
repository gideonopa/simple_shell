#include "shell.h"

/**
 * print_error - prints error messages to std error
 * @vars: pointer to structure of variables
 * @msg: message to print
 *
 * Return: void
 */

void print_error(vars_t *vars, char *msg)
{
	char *count;

	_puts2(vars->argv[0]);
	_puts2(": ");
	count = _uitoa(vars->count);
	_puts2(count);
	free(count);
	_puts2(": ");
	_puts2(vars->av[0]);
	if (msg)
	{
		_puts2(msg);
	}
	else
		perror("");
}


/**
 * _puts2 - prints a str to std error
 * @str: str to print
 *
 * Return: void
 */

void _puts2(char *str)
{
	ssize_t numb, len1;

	numb = _strlen(str);
	len1 = write(STDERR_FILENO, str, numb);
	if (len1 != numb)
	{
		perror("Fatal Error");
		exit(1);
	}

}


/**
 * _uitoa - converts an unsigned int to a str
 * @count: unsigned int to convert
 *
 * Return: pointer to the converted str
 */

char *_uitoa(unsigned int count)
{
	char *numstr;
	unsigned int tmp, digits;

	tmp = count;
	for (digits = 0; tmp != 0; digits++)
		tmp /= 10;
	numstr = malloc(sizeof(char) * (digits + 1));
	if (numstr == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}
	numstr[digits] = '\0';
	for (--digits; count; --digits)
	{
		numstr[digits] = (count % 10) + '0';
		count /= 10;
	}
	return (numstr);
}
