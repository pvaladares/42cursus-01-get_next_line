/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:32:59 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/20 12:23:35 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Function retrieves the length of the string passed
// The string terminator is taken in consideration
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// This function concenates s1 and s2 strings into a new string
// Malloc is used to compute create the string
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// Function attempts to free the string in case its pointer is not NULL
// After freeing the pointer (breaking the link between pointer and pointee)
// The value of the pointer is set to NULL so it does not point to some 
// random value in memory if dereferenced
void	safe_free(char *str)
{
	if (str != NULL)
		free(str);
	str = NULL;
}

// Function checks whether or not the string is fully printable
// This is used to distinguish between non-text files, often called binary
int	ft_is_string_printable(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < ' ' || str[i] > '~')
			return (0);
		i++;
	}
	return (1);
}
