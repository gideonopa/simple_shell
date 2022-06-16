#include "shell.h"


/**
 * tokenize - tokenizes a buffer with a delimiter
 * @buffer: buffer to tokenize
 * @delimiter: delimiter to tokenize along
 *
 * Return: pointer to an array of pointers to the tokens
 */

char **tokenize(char *buffer, char *delimiter)
{
	char **tokens = NULL;
	size_t x = 0, m_count = 10;

	if (buffer == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * m_count);
	if (tokens == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	while ((tokens[x] = new_strtok(buffer, delimiter)) != NULL)
	{
		x++;
		if (x == m_count)
		{
			tokens = _realloc(tokens, &m_count);
			if (tokens == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		buffer = NULL;
	}
	return (tokens);
}
