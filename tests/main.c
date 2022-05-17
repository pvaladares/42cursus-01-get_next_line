/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:49:26 by pvaladar          #+#    #+#             */
/*   Updated: 2022/05/17 17:15:13 by pvaladar         ###   ########.fr       */
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
// $ cc -Wall -Werror -Wextra -D BUFFER_SIZE=42  *.c  ../tests/main.c -o gnl
int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	//(void)argv;
	(void)argc;
	/*
	if (argc == 1)
		puts("STDIN : ");
	else if (argc == 2)
	{
		puts("FILE :");
		return (0);
	}
	else
	{
		puts("Usage: $ gnl <file to read>");
		return (0);
	}
	*/
	//if (argc == 1)
	//		fd = open(0, O_RDONLY);
	//else
	fd = open(argv[1], O_RDONLY);
	i = 1;
	printf("fd [%d] | Line [%d] | Content [%s]\n", fd, i++, get_next_line(fd));
	printf("fd [%d] | Line [%d] | Content [%s]\n", fd, i++, get_next_line(fd));
	printf("fd [%d] | Line [%d] | Content [%s]\n", fd, i++, get_next_line(fd));
	return (0);
}
