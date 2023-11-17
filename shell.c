#include "main.h"

/**
 * main - function that print a prompt
 *
 * @ac: length of argument
 * @argv: argument vector
 *
 *
 * Return: Always 0
 */

int main(int ac, char *argv[])
{
	char *line = NULL;
	size_t n = 0;
	ssize_t read;
	(void)ac;

	while (1)
	{
		printf("#CISFUN$ ");
		read = getline(&line, &n, stdin);
		if (read == -1)
		{
			perror(argv[0]);
			break;
		}
		else if (read > 1)
		{
			char *command = line;
			char **arguments;

			if (line[read - 1] == '\n')
				line[read - 1] = '\0';
			arguments = malloc(2 * sizeof(char *));

			if (arguments == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
		       arguments[0] = command;
		       arguments[1] = NULL;

			if (execve(command, arguments, NULL) == -1)
				perror(argv[0]);
			free(arguments);
		}
	}
	free(line);
	return (0);
}
