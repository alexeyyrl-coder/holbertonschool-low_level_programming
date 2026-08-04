#include "main.h"

/**
 * write_all_text - writes an entire string to a file descriptor
 * @fd: file descriptor
 * @text_content: NULL-terminated string to write
 *
 * Return: 1 on success, -1 on failure
 */
static int write_all_text(int fd, char *text_content)
{
	ssize_t written;
	size_t len;
	size_t total;

	if (text_content == NULL)
		return (1);

	len = 0;
	while (text_content[len] != '\0')
		len++;

	total = 0;
	while (total < len)
	{
		written = write(fd, text_content + total, len - total);
		if (written <= 0)
			return (-1);

		total += written;
	}

	return (1);
}

/**
 * append_text_to_file - appends text to an existing file
 * @filename: name of the file
 * @text_content: NULL-terminated string to append
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int result;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	result = write_all_text(fd, text_content);

	if (close(fd) == -1)
		return (-1);

	return (result);
}
