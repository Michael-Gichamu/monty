#include "monty.h"

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: a pointer to the newly allocated string, or NULL if allocation fails
 */
char *_strdup(char *str)
{
	char *dup_str;
	int len, i;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len] != '\0')
		len++;
	dup_str = malloc(sizeof(char) * (len + 1));

	if (dup_str == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		dup_str[i] = str[i];

	return (dup_str);
}

