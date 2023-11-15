#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
			if (line[read - 1] == '\n')
				line[read = 1] = '\0';

			char *command = line;
			char *arguments[] = {command, NULL};

			if (execve(command, arguments, NULL) == -1)
				perror(argv[0]);

		}
	}
	free(line);
	return (0);
}