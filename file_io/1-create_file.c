#include "main.h"

/**
 * create_file - creates a file and writes text into it
 * @filename: name of the file to create
 * @text_content: NULL-terminated string to write
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	size_t len;
	ssize_t written;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
	{
		if (close(fd) == -1)
			return (-1);
		return (1);
	}

	len = 0;
	while (text_content[len] != '\0')
		len++;

	written = write(fd, text_content, len);
	if (written != (ssize_t)len)
	{
		close(fd);
		return (-1);
	}

	if (close(fd) == -1)
		return (-1);

	return (1);
}
