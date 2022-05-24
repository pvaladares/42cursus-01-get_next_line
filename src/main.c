/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:49:26 by pvaladar          #+#    #+#             */
/*   Updated: 2022/05/24 14:02:38 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/get_next_line.h"
#include <fcntl.h> // open()
#include <stdio.h> // printf()
//#include <limits.h>

// Prototype of open() shows that the return type is `int`, the same type
// as expected input by the get_next_line(int fd):
//     int
//     open(const char *path, int oflag, ...);
//
// Sample compilation syntax:
// $ cc -Wall -Werror -Wextra -D BUFFER_SIZE=42  *.c  ../tests/main.c -o gnl
// https://www.osc.edu/resources/getting_started/howto/howto_use_address_sanitizer
int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	(void)argc;
	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	i = 1;

	printf("fd [%d] | Line [%d] | Content [%s]\n", fd, i++, get_next_line(fd));
	//printf("fd [%d] | Line [%d] | Content [%s]\n", fd, i++, get_next_line(fd));
	//printf("fd [%d] | Line [%d] | Content [%s]\n", fd, i++, get_next_line(fd));
	//printf("fd [%d] | Line [%d] | Content [%s]\n", fd, i++, get_next_line(fd));
	return (0);
}
