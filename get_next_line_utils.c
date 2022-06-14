/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:32:59 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/14 10:39:38 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_and_free(char *str)
{
	int	i;

	i = 0;
	if (*str)
	{
		while (str[i])
			str[i++] = '\0';
		free(str);
	}
	str = NULL;
}

char	*gnl_fill_line(char *buffer, char *line)
{
	char	*tmp;
	char	*new_line;
	int		i;
	int		j;

	tmp = line;
	new_line = malloc(sizeof(line) * (gnl_strlen(buffer) + gnl_strlen(line) + 1));
	if (new_line == NULL)
		return (NULL);
	i = 0;
	while (tmp && tmp[i])
	{
		new_line[i] = tmp[i];
		i++;
	}
	j = 0;
	while (buffer[j])
	{
		new_line[i++] = buffer[j];
		if (buffer[j++] == '\n')
			break ;
	}
	new_line[i] = '\0';
	if (tmp)
		free(tmp);
	return (new_line);
}

// Function 
void	gnl_reffil_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	//
	printf("Buffer before : %s\n", buffer);
	while (buffer[i])
	{
		if (buffer[i] == '\n' && j == -1)
			j = 0;
		else if (j >= 0)
		{
			buffer[j] = buffer[i];
			j++;
		}
		buffer[i++] = 0;
	}
	//
	printf("Buffer after : %s\n", buffer);
}

// Function based on regular ft_strlen but modified to acommodate
// the special behaviour case of '\n' char for this project
// Examples:
// gnl_strlen("Hello") = 5
// gnl_strlen("Hello\n") = 6
// gnl_strlen("Hello\n1234567890") = 6
size_t	gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

// Function checks whether or not the string is fully printable
// This is used to distinguish between non-text files, often called binary
int	ft_is_string_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < ' ' || str[i] > '~')
			return (0);
		i++;
	}
	return (1);
}

// Function returns the first occurrence of a char within a string
char	*ft_strchr(const char *s, int c)
{
	if ((unsigned char)c == '\0')
	{
		while (*s)
			s++;
		return ((char *) s);
	}
	while (*s)
	{
		if ((unsigned char)c == *s)
			return ((char *) s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*aux;

	aux = (char *)malloc(ft_strlen(s1) + 1);
	if (!aux)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memcpy(aux, s1, ft_strlen(s1) + 1);
	return (aux);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*dest;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	i = 0;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (s[i] && i < len)
	{
		dest[i] = s[i + start];
		i++;
	}
	dest[i] = 0;
	return (dest);
}