<<<<<<< HEAD
#include "shell.h"
=======
 #include "shell.h"
>>>>>>> b9b50b40ea1c0688012c8e3a11aad9aef8b9c6c2

/**
 * remove_newline - removes newline character from string
 * @buffer: string
 *
 * Return: the pointer
 */
void *remove_newline(char *buffer)
{
	char *p;

	p = buffer;
	while (*p != '\0')
		p++;
	while (*p != '\n')
		p--;

	*p = '\0';
	return (buffer);
}

/**
 * execute_command - executes a command
 * @buffer: buffer with the command to execute
 * @argv: array of command line arguments
 * Return: void
 */
void execute_command(char *buffer, char **argv)
{
	char *args[BUFFER_SIZE / 2];
	pid_t pid;
	char *token, *path;
	int i;

	i = 0;
	token = strtok(buffer, " ");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	path = get_path(args[0]);

	if (!path)
	{
		printf("Command not found: %s\n", args[0]);
		return;
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork() error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
