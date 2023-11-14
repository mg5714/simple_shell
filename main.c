#include "shell.h"
#include <stddef.h>

/**
 * main - entry point.
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	size_t buff_size = BUFFER_SIZE;
	char buffer[BUFFER_SIZE];
	/*char *cmd;*/

	_prompt();
	while (1)
	{
		read_line(buffer, buff_size);
		remove_newline(buffer);
		/*cmd = "command ece";*/
		/*get_path(cmd);*/
		check_builtins(buffer);
		execute_command(buffer, argv);

		_prompt();
	}
	if (argc)
	{}
	return (0);
}
