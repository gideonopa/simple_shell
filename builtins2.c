#include "shell.h"

/**
 * add_key - create a new environment variable
 * @vars: pointer to struct of variables
 *
 * Return: void
 */
void add_key(vars_t *vars)
{
	unsigned int x;
	char **newenv;

	for (x = 0; vars->env[x] != NULL; x++)
		;
	newenv = malloc(sizeof(char *) * (x + 2));
	if (newenv == NULL)
	{
		print_error(vars, NULL);
		vars->status = 127;
		new_exit(vars);
	}
	for (x = 0; vars->env[x] != NULL; x++)
		newenv[x] = vars->env[x];
	newenv[x] = add_value(vars->av[1], vars->av[2]);
	if (newenv[x] == NULL)
	{
		print_error(vars, NULL);
		free(vars->buffer);
		free(vars->commands);
		free(vars->av);
		free_env(vars->env);
		free(newenv);
		exit(127);
	}
	newenv[x + 1] = NULL;
	free(vars->env);
	vars->env = newenv;
}

/**
 * find_key - finds an environment variable
 * @env: array of environment variables
 * @key: environment variable to find
 *
 * Return: pointer to address of the environment variable
 */
char **find_key(char **env, char *key)
{
	unsigned int x, y, length;

	length = _strlen(key);
	for (x = 0; env[x] != NULL; x++)
	{
		for (y = 0; y < length; y++)
			if (key[y] != env[x][y])
				break;
		if (y == length && env[x][y] == '=')
			return (&env[x]);
	}
	return (NULL);
}

/**
 * add_value - create a new environment variable string
 * @key: variable name
 * @value: variable value
 *
 * Return: pointer to the new string;
 */
char *add_value(char *key, char *value)
{
	unsigned int len_1, len_2, x, y;
	char *new;

	len_1 = _strlen(key);
	len_2 = _strlen(value);
	new = malloc(sizeof(char) * (len_1 + len_2 + 2));
	if (new == NULL)
		return (NULL);
	for (x = 0; key[x] != '\0'; x++)
		new[x] = key[x];
	new[x] = '=';
	for (y = 0; value[y] != '\0'; y++)
		new[x + 1 + y] = value[y];
	new[x + 1 + y] = '\0';
	return (new);
}

/**
 * _atoi - converts a string into an integer
 * @str: string to convert
 *
 * Return: the integer value, or -1 if an error occurs
 */
int _atoi(char *str)
{
	unsigned int x, digits;
	int num = 0, num_test;

	num_test = INT_MAX;
	for (digits = 0; num_test != 0; digits++)
		num_test /= 10;
	for (x = 0; str[x] != '\0' && x < digits; x++)
	{
		num *= 10;
		if (str[x] < '0' || str[x] > '9')
			return (-1);
		if ((x == digits - 1) && (str[x] - '0' > INT_MAX % 10))
			return (-1);
		num += str[x] - '0';
		if ((x == digits - 2) && (str[x + 1] != '\0') && (num > INT_MAX / 10))
			return (-1);
	}
	if (x > digits)
		return (-1);
	return (num);
}
