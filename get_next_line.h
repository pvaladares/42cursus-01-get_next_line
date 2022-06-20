/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:33:01 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/20 12:24:03 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ======================== PROTECTION AGAINST MULTIPLE INCLUSIONS

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// ======================== INCLUDES

# include <unistd.h> // used by read(), STDOUT_FILENO, STDERR_FILENO
# include <stdlib.h> // definition of size_t and NULL (e.g.: ft_memset)
# include <errno.h> // definition of error codes (e.g.: ft_calloc)
# include <limits.h> // definition of OPEN_MAX
# include <stdio.h> // for testing

// ======================== DEFINITIONS
/*
 * In case BUFFER_SIZE is 0 the get_next_line function will have NO buffer
 * space to make the calculaion, so the function will do nothing!
 * Since it makes no sense, it is filtered out in the preliminary checks
 * of the function. If the user does not set the BUFFER_SIZE at compilation
 * stage, we define it with default value, also used for testing purposes
 */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# define GNL_ERROR NULL
# define GNL_BINARY_FILE NULL
# define GNL_END_OF_FILE 0
# define GNL_LINE_READ 1
# define GNL_NO_NEWLINE 2

// ======================== PROTOTYPES

// get_next_line.c
char	*get_next_line(int fd);

// get_next_line_utils.c
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	safe_free(char *str);
int		ft_is_string_printable(char const *str);

#endif
