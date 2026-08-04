#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * close_file - closes a file descriptor
 * @fd: file descriptor to close
 *
 * Return: nothing
 */
static void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_content - copies data from one file descriptor to another
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @file_from: source file name
 * @file_to: destination file name
 *
 * Return: nothing
 */
static void copy_content(int fd_from, int fd_to,
	const char *file_from, const char *file_to)
{
	char buffer[1024];
	ssize_t bytes_read;
	ssize_t bytes_written;

	bytes_read = read(fd_from, buffer, 1024);
	while (bytes_read > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file_to);
			exit(99);
		}
		bytes_read = read(fd_from, buffer, 1024);
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", file_from);
		exit(98);
	}
}

/**
 * main - copies the content of one file to another
 * @ac: number of command-line arguments
 * @av: array of command-line arguments
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from;
	int fd_to;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", av[2]);
		close_file(fd_from);
		exit(99);
	}

	copy_content(fd_from, fd_to, av[1], av[2]);

	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
