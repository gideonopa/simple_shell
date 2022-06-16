#include "holberton.h"

/**
 * _strcat - concatenate two strings
 * @dest: char pointer the dest of the copied str
 * @src: const char pointer the source of str
 * Return: the dest
 */
char *_strcat(char *dest, const char *src)
{
	int x;
	int j;

	for (x = 0; dest[x] != '\0'; x++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[x] = src[j];
		x++;
	}

	dest[x] = '\0';
	return (dest);
}
/**
 * *_strcpy - Copies the string pointed to by src.
 * @dest: Type char pointer the dest of the copied str
 * @src: Type char pointer the source of str
 * Return: the dest.
 */
char *_strcpy(char *dest, char *src)
{

	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}
/**
 * _strcmp - Function that compares two strings.
 * @s1: type str compared
 * @s2: type str compared
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int x;

	for (x = 0; s1[x] == s2[x] && s1[x]; x++)
		;

	if (s1[x] > s2[x])
		return (1);
	if (s1[x] < s2[x])
		return (-1);
	return (0);
}
/**
 * _strchr - locates a character in a string,
 * @s: string.
 * @c: character.
 * Return: the pointer to the first occurrence of the character c.
 */
char *_strchr(char *s, char c)
{
	unsigned int x = 0;

	for (; *(s + x) != '\0'; x++)
		if (*(s + x) == c)
			return (s + x);
	if (*(s + x) == c)
		return (s + x);
	return ('\0');
}
/**
 * _strspn - gets the length of a prefix substring.
 * @s: initial segment.
 * @accept: accepted bytes.
 * Return: the number of accepted bytes.
 */
int _strspn(char *s, char *accept)
{
	int x, j, bool;

	for (x = 0; *(s + x) != '\0'; x++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + x) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (x);
}
