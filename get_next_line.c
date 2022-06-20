/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:32:54 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/20 11:33:50 by pvaladar         ###   ########.fr       */
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

char	*ft_before(char *str)
{
	int		i;
	char	*ptr;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	ptr = malloc((i + 2) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		ptr[i++] = '\n';
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_after(char *str)
{
	int		i;
	int		j;
	char	*ptr;

	if (str == NULL)
		return (NULL);
	j = 0;
	while (str[j] != '\n' && str[j] != '\0')
		j++;
	if (str[j] == '\0')
	{
		safe_free(str);
		return (NULL);
	}
	i = ft_strlen(str);
	ptr = malloc((i - j) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j++;
	while (str[j] != '\0')
		ptr[i++] = str[j++];
	ptr[i] = '\0';
	safe_free(str);
	return (ptr);
}

int	ft_newline(char *str)
{
	if (str == NULL)
		return (-1);
	while (*str != '\0')
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_read(int fd, char *buf, char *tmp, char *str)
{
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read != GNL_END_OF_FILE)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			safe_free(buf);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		tmp = str;
		if (tmp == NULL)
		{
			tmp = malloc(sizeof(char));
			tmp[0] = '\0';
		}
		str = ft_strjoin(tmp, buf);
		safe_free(tmp);
		if (ft_newline(str) == 1)
			break ;
	}
	safe_free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*line;
	char		*tmp;

	tmp = NULL;
	if (fd <= -1 || fd == STDOUT_FILENO || fd == STDERR_FILENO || fd >= OPEN_MAX
		|| read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	str = ft_read(fd, buf, tmp, str);
	if (str == NULL)
		return (NULL);
	line = ft_before(str);
	str = ft_after(str);
	return (line);
}

/*
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
}*/
