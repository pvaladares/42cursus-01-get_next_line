/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:32:54 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/14 17:27:45 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Function name    | get_next_line
// Prototype        | char *get_next_line(int fd);
// Turn in files    | get_next_line.c, get_next_line_utils.c, get_next_line.h
// Parameters       | fd: The file descriptor to read from
// Return value     | Read line: correct behavior
//					| NULL: there is nothing else to read, or an error occurred
// External functs. | read, malloc, free
// Description      | Write a function that returns a line read from a
//					| file descriptor
//
// Functions returns NULL if EOF is found (0 from read function) or if there
// is an error during runtime (-1 from read function)
// line variable is set to NULL so the pointer is defined it has to be returned
/*
 * Information on `max open files per process` from previous release of macOS
 * opensource.apple.com/source/xnu/xnu-6153.141.1/bsd/sys/syslimits.h.auto.html
 */
// Chained list contents:
// https://elearning.intra.42.fr/notions/c-piscine-c-12/subnotions
// https://www.youtube.com/playlist?list=PLVQYiy6xNUxwmUOmyYSaI6gD1UyfF9MSj
char	*get_next_line(int fd)
{
	static t_buffer	buffer;
	char			*line;
	int				result;

	if (fd <= -1 || fd == STDOUT_FILENO || fd == STDERR_FILENO || fd >= OPEN_MAX
		|| read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
		return (GNL_ERROR);
	line = NULL;
	if (buffer.data == NULL)
	{
		buffer.data = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer.data == NULL)
			return (GNL_ERROR);
		//buffer.start = NULL;
	}
	result = GNL_NO_NEWLINE;
	while (result == GNL_NO_NEWLINE)
		result = read(fd, buffer.data, BUFFER_SIZE);
		//result = append_next_chunk(fd, line, &buffer);
	if (result == GNL_END_OF_FILE || result == -1)
		//clear_buffer(&(buffers.data));
	return (buffer.data);
}

#include <fcntl.h> // open()
#include <stdio.h> // printf()
#include <string.h>

// Prototype of open() shows that the return type is `int`, the same type
// as expected input by the get_next_line(int fd):
//     int
//     open(const char *path, int oflag, ...);
//
// Sample compilation syntax:
// $ cc -Wall -Werror -Wextra -D BUFFER_SIZE=42  *.c  -o gnl
// osc.edu/resources/getting_started/howto/howto_use_address_sanitizer
int	main(int argc, char **argv)
{
	int	fd;
	int	i;
	char hello[] = "123";

	(void)argc;
	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	i = 1;
	printf("FD_SETSIZE = [%d]\n", FD_SETSIZE);
	printf("OPEN_MAX = [%d]\n", OPEN_MAX);

	printf("fd [%d] | Line [%d] | Content [%s]\n", fd, i++, get_next_line(fd));
	//printf("fd [%d] | Line [%d] | Content [%s]\n", fd, i++, get_next_line(fd));
	//printf("fd [%d] | Line [%d] | Content [%s]\n", fd, i++, get_next_line(fd));
	//printf("fd [%d] | Line [%d] | Content [%s]\n", fd, i++, get_next_line(fd));
	printf("Sizeof [%s] = [%lu] | strlen = [%lu]\n", hello, sizeof(hello), strlen(hello));
	return (0);
}
