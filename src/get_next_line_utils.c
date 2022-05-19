/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:32:59 by pvaladar          #+#    #+#             */
/*   Updated: 2022/05/19 15:39:07 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_fill_line(char *buffer, char *line)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = line;
	line = malloc(sizeof(char) * (gnl_strlen(buffer) + gnl_strlen(line) + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (tmp && tmp[i])
	{
		line[i] = tmp[i];
		i++;
	}
	j = 0;
	while (buffer[j])
	{
		line[i++] = buffer[j];
		if (buffer[j++] == '\n')
			break ;
	}
	line[i] = '\0';
	if (tmp)
		free(tmp);
	return (line);
}

void	gnl_reffil_buffer(char *buff)
{
	int	i;
	int	j;

	j = -1;
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n' && j == -1)
			j = 0;
		else if (j >= 0)
		{
			buff[j] = buff[i];
			j++;
		}
		buff[i++] = 0;
	}
}

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

// From Libft library
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
