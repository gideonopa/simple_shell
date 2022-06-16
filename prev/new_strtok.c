#include "shell.h"

/**
 * check_match - checks if a character matches any in a string
 * @c: character to check
 * @str: string to check
 *
 * Return: 1 if match, 0 if not
 */
unsigned int check_match(char c, const char *str)
{
	unsigned int x;

	for (x = 0; str[x] != '\0'; x++)
	{
		if (c == str[x])
			return (1);
	}
	return (0);
}

/**
 * new_strtok - custom strtok
 * @str: string to tokenize
 * @delim: delimiter to tokenize against
 *
 * Return: pointer to the next token or NULL
 */
char *new_strtok(char *str, const char *delim)
{
	static char *start_token;
	static char *new_token;
	unsigned int x;

	if (str != NULL)
		new_token = str;
	start_token = new_token;
	if (start_token == NULL)
		return (NULL);
	for (x = 0; new_token[x] != '\0'; x++)
	{
		if (check_match(new_token[x], delim) == 0)
			break;
	}
	if (new_token[x] == '\0' || new_token[x] == '#')
	{
		new_token = NULL;
		return (NULL);
	}

	start_token = new_token + x;
	new_token = start_token;
	for (x = 0; new_token[x] != '\0'; x++)
	{
		if (check_match(new_token[x], delim) == 1)
			break;
	}
	if (new_token[x] == '\0')
		new_token = NULL;
	else
	{
		new_token[x] = '\0';
		new_token = new_token + x + 1;
		if (*new_token == '\0')
			new_token = NULL;
	}
	return (start_token);
}
