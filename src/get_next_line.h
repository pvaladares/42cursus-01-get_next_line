/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:33:01 by pvaladar          #+#    #+#             */
/*   Updated: 2022/05/19 15:33:41 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/*
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
*/
//# include <stdlib.h> // definition of size_t and NULL (e.g.: ft_memset)
# include <unistd.h> // used by read()
# include <stdlib.h> // definition of size_t and NULL (e.g.: ft_memset)
# include <errno.h> // definition of error codes (e.g.: ft_calloc)
# include <stdio.h>
//# include <limits.h> // OPEN_MAX

# include <fcntl.h>

char	*get_next_line(int fd);
char	*gnl_fill_line(char *buff, char *line);
void	gnl_reffil_buffer(char *buff);
size_t	gnl_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int		ft_is_string_printable(char *str);

//# define FD_MAX 10240
// Check the maximum number of open file descriptors:
//  "ulimit -Sn" to check what is the soft limit (e.g.: 10240)
//  "ulimit -Hn" to check what is the hard limit (e.g.: unlimited)
// More info:
// https://linuxcommand.org/lc3_man_pages/ulimith.html
// https://docs.oracle.com/cd/E19683-01/816-0210/6m6nb7mo3/index.html

#endif
