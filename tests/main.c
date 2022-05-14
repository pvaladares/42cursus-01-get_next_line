/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:49:26 by pvaladar          #+#    #+#             */
/*   Updated: 2022/05/14 01:39:29 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/get_next_line.h"
#include <fcntl.h> // Required by open()
#include <stdio.h> // printf()

// Prototype of open() shows that the return type is `int`, the same type
// as expected input by the get_next_line(int fd):
//     int
//     open(const char *path, int oflag, ...);
//
// Sample compilation syntax:
// $ cc -Wall -Werror -Wextra -D BUFFER_SIZE=100  *.c ../src/*.c -o gnl && ./gnl
int	main(int argc, char **argv)
{
	int	fd, i;

	(void)argv;
	if (argc != 2)
	{
		puts("Usage: $ gnl <file to read>");
	}
	fd = open("3linesASCII.txt", O_RDONLY);
	i = 1;
	printf("Line %d : [%s]\n", i++, get_next_line(fd));
//	printf("Line %d : {%s}\n", i++, get_next_line(fd));
//	printf("Line %d : {%s}\n", i++, get_next_line(fd));
	return (0);
}
