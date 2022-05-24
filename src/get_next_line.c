/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:32:54 by pvaladar          #+#    #+#             */
/*   Updated: 2022/05/24 15:52:48 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// Function name    | get_next_line
// Prototype        | char *get_next_line(int fd);
// Turn in files    | get_next_line.c, get_next_line_utils.c, get_next_line.h
// Parameters       | fd: The file descriptor to read from
// Return value     | Read line:  correct behavior
//					| NULL: there is nothing else to read, or an error occurred
// External functs. | read, malloc, free
// Description      | Write a function that returns a line read from a
//					| file descriptor
//
// Functions returns NULL if EOF is found (0 from read function) or if there
// is an error during runtime (-1 from read function)
// line variable is set to NULL so the pointer is defined it has to be returned
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*accumulator;
	//char		*accumulator;
	int			bytes_read;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd == 1 | fd == 2 || read(fd, 0, 0) == -1)
		return (NULL);
	//line = NULL;
	accumulator = ft_strdup("");
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		// EOF or Error reading fd
		if (bytes_read <= 0)//|| !ft_is_string_printable(buffer))
			break ;
		line = ft_strjoin(accumulator, buffer);
		//free(accumulator);
		//free(buffer);
		//if (ft_strchr(line, '\n'))
			line = ft_substr(buffer, 0, ft_strchr(buffer, '\n') - buffer);
		

		//printf("line[%s]\t\t\t\t\tbuffer[%s]\n", accumulator, buffer);
		//printf("line[%s] buffer[%s] accumulator[%s]\n", line, buffer, accumulator);
		//ft_strchr()
	}
	return (line);
}
