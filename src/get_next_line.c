/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:32:54 by pvaladar          #+#    #+#             */
/*   Updated: 2022/05/19 15:37:57 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Main function get the
// "Static variables (like global variables) are initialized as 0 if not 
//	initialized explicitly." from C99
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*line;

	if (fd < 0 || fd == 1 | fd == 2 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (NULL);
	line = NULL;
	while (1)
	{
		bytes_read = 1;
		if (buffer[0] == 0)
			bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
			line = gnl_fill_line(buffer, line);
		gnl_reffil_buffer(buffer);
		if (bytes_read == 0 || ft_strchr(line, '\n'))
			break ;
	}
	return (line);
}
