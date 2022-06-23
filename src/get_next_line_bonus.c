/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:32:54 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/20 23:34:13 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Function takes the input string and copies into a new string
// all chars that are before the new line and null terminator string
char	*ft_before(const char *str)
{
	int		i;
	char	*ptr;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	ptr = malloc((i + 1 + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		ptr[i] = '\n';
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// Function takes the input string and copies in a new string
// all chars that are after the new line and null terminator string
char	*ft_after(char *str)
{
	int		n;
	int		i;
	char	*ptr;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		safe_free(str);
		return (NULL);
	}
	n = ft_strlen(str);
	ptr = malloc((n - i) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	n = 0;
	i++;
	while (str[i] != '\0')
		ptr[n++] = str[i++];
	ptr[n] = '\0';
	safe_free(str);
	return (ptr);
}

// Function checks if the charater NEW LINE is present within the
// passed string
// RETURNS '-1' in case the string pointer is defined
// RETURNS '1' in case '\n' is found
// RETURNS '0' in case '\n' is not found
int	ft_newline(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// Function attempts to retrieve all bytes from `fd` to `buffer` until
// EOF is reached
// In case there is an error reading the `fd` it is returned `GNL_ERROR`
// In case it is the first iteration allocate memory in the heap
// and create an emtpy string with null terminator `tmp`; (in the next
// loops `tmp` is assigned with the address of the recently joined `str`)
// Concatenate the `buffer` with the `tmp` variable
// Loop the above until a NEW LINE is found (or EOF is reached)
char	*ft_read(int fd, char *buffer, char *tmp, char *str)
{
	int		bytes_read;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (GNL_ERROR);
		buffer[bytes_read] = '\0';
		tmp = str;
		if (tmp == NULL)
		{
			tmp = malloc(sizeof(char));
			if (tmp == NULL)
				return (GNL_ERROR);
			tmp[0] = '\0';
		}
		str = ft_strjoin(tmp, buffer);
		safe_free(tmp);
		if (ft_newline(str) == GNL_NEWLINE || bytes_read == GNL_END_OF_FILE)
			break ;
	}
	safe_free(buffer);
	return (str);
}

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
/*
 * Information on `max open files per process` from previous release of macOS
 * opensource.apple.com/source/xnu/xnu-6153.141.1/bsd/sys/syslimits.h.auto.html
 */
char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*buffer;
	char		*line;
	char		*tmp;

	if (fd <= -1 || fd == STDOUT_FILENO || fd == STDERR_FILENO || fd >= OPEN_MAX
		|| read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
		return (GNL_ERROR);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (GNL_ERROR);
	tmp = NULL;
	str[fd] = ft_read(fd, buffer, tmp, str[fd]);
	if (str[fd] == NULL)
		return (GNL_ERROR);
	line = ft_before(str[fd]);
	str[fd] = ft_after(str[fd]);
	return (line);
}
