#include "monty.h"
#include <string.h>

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on succes
 */
int main(int argc, char *argv[])
{
	char buffer[1023];
	char *content;
	FILE *file;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bus.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, sizeof(buffer), file))
	{
		content = _strdup(buffer);
		bus.content = content;
		counter++;
		execute(content, &stack, counter, file);
		free(content);
	}

	free_stack(stack);
	fclose(file);

	return (0);
}

