 #include "shell.h"

/**
 * remove_newline - removes newline character from string
 * @buffer: string
 *
 * Return: the pointer
 */
void *remove_newline(char *buffer)
{
buffer[strcspn(buffer, "\n")] = '\0';
return (buffer);
}

/**
 * execute_command - executes a command
 * @buffer: buffer with the command to execute
 * @argv: vactor ptr to ptr char
 * Return: void
 */
void execute_command(char *buffer, char **argv)
{
char *args[BUFFER_SIZE / 2];
pid_t pid = fork();
char *token, *path;
int i = 0;

if (pid < 0)
{
perror("fork() error");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
token = strtok(buffer, " ");
while (token != NULL)
{
args[i++] = token;
token = strtok(NULL, " ");
}
args[i] = NULL;

path = get_path(args[0]);
if (path != NULL)
{
if(execve(path, args, environ) == -1)/* args[0] */
   {
     perror(argv[0]);
     exit(EXIT_FAILURE);
   }
}
 else
   {
     printf("Command not founf: %s\n", args[0]);
   }
}
else
{
wait(NULL);
}
}
