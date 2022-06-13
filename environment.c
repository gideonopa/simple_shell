#include "shell.h"

/**
 * make_env - make the shell env from the env passed to main
 * @env: env passed to main
 *
 * Return: pointer to the new env
 */
char **make_env(char **env)
{
	char **newenv = NULL;
	size_t x;

	for (x = 0; env[x] != NULL; x++)
		;
	newenv = malloc(sizeof(char *) * (x + 1));
	if (newenv == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (x = 0; env[x] != NULL; x++)
		newenv[x] = _strdup(env[x]);
	newenv[x] = NULL;
	return (newenv);
}

/**
 * free_env - free the shell's env
 * @env: shell's env
 *
 * Return: void
 */
void free_env(char **env)
{
	unsigned int x;

	for (x = 0; env[x] != NULL; x++)
		free(env[x]);
	free(env);
}
