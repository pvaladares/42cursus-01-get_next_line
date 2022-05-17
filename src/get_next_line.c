/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:32:54 by pvaladar          #+#    #+#             */
/*   Updated: 2022/05/17 17:16:59 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Info about read() => $ man 2 read
//
// READ(2)                      System Calls Manual                     READ(2)
//
// NAME
//      read – read input
//
// LIBRARY
//      Standard C Library (libc, -lc)
//
// SYNOPSIS
//      #include <sys/types.h>
//      #include <sys/uio.h>
//      #include <unistd.h>
//
//      ssize_t
//      read(int fildes, void *buf, size_t nbyte);
//
// DESCRIPTION
//      read() attempts to read nbyte bytes of data from the object referenced 
//      by the descriptor fildes into the buffer pointed to by buf. 
//
//      On objects capable of seeking, the read() starts at a position given by
//      the pointer associated with fildes (see lseek(2)).
//      Upon return from read(), the pointer is incremented by the number of 
//      bytes actually read.
//
//      Objects that are not capable of seeking always read from the current 
//      position.  
//      The value of the pointer associated with such an object is undefined.
//
//      Upon successful completion, read() return the number of bytes actually
//      read and placed in the buffer.
//      The system guarantees to read the number of bytes requested if the 
//      descriptor references a normal file that has that many bytes left 
//      before the end-of-file, but in no other case.
//
//      read() will fail if the parameter nbyte exceeds INT_MAX, 
//      and they do not attempt a partial read.
//
// RETURN VALUES
//      If successful, the number of bytes actually read is returned.  
//      Upon reading end-of-file, zero is returned.  
//      Otherwise, a -1 is returned and the global variable errno is set to 
//      indicate the error.
//
// File descriptors reading:	http://www.bottomupcs.com/file_descriptors.xhtml
//
// Function will have the BUFFER_SIZE defined during compilation
// From subject: 
//	$ cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	//char		*line;

	if (read(fd, 0, 0) == -1 || BUFFER_SIZE == 0 || fd > FD_MAX)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	return (buffer);
}
