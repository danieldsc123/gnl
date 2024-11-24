/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:05:05 by danielda          #+#    #+#             */
/*   Updated: 2024/11/22 19:36:12 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_endl(char	*buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		return (1);
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while ((*s != '\0') && (*s != (char)c))
	{
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return ((char *) NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str_return;
	int		length;
	int		i;
	int		j;

	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	str_return = NULL;
	str_return = malloc(length * sizeof(char));
	if (!str_return)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str_return[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str_return[i++] = s2[j++];
	str_return[i] = 0;
	return (str_return);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	if (!s)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}
