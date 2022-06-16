#include "shell.h"

/**
 * _realloc - reallocates a pointer to double the space
 * @ptr: pointer to the old array
 * @size: pointer to numb of elements in the old array
 *
 * Return: pointer to the new array
 */
char **_realloc(char **ptr, size_t *size)
{
	char **new;
	size_t x;

	new = malloc(sizeof(char *) * ((*size) + 10));
	if (new == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (x = 0; x < (*size); x++)
	{
		new[x] = ptr[x];
	}
	*size += 10;
	free(ptr);
	return (new);
}
