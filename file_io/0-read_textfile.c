#include "main.h"

/**
 * read_textfile - reads a text file and prints it to standard output
 * @filename: name of the file to read
 * @letters: maximum number of characters to read
 *
 * Return: number of characters printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t bytes_read;
	ssize_t bytes_written;

	if (filename == NULL || letters == 0)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	bytes_read = read(fd, buffer, letters);
	if (bytes_read <= 0)
	{
		close(fd);
		free(buffer);
		return (0);
	}

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	close(fd);
	free(buffer);

	if (bytes_written != bytes_read)
		return (0);

	return (bytes_written);
}
