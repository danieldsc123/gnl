/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:46:42 by danielda          #+#    #+#             */
/*   Updated: 2024/11/23 21:00:18 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char		*copy;
	int			i;
	int			dest;

	i = 0;
	dest = 0;
	while (s[dest] != '\0')
	{
		dest++;
	}
	copy = (char *)malloc((dest + 1) * sizeof(char));
	if (!copy)
	{
		return (NULL);
	}
	while (i < dest)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*read_fd(int fd, char *stash)
{
	char		*buffer;
	char		*temp;
	long long	bytes_read;

	bytes_read = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(buffer), NULL);
	while (bytes_read != 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(stash), NULL);
		buffer[bytes_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
	}
	free (buffer);
	return (stash);
}

char	*get_current_line(char *stash)
{
	int		i;
	char	*string;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	string = ft_substr(stash, 0, i + ft_endl(stash));
	if (!string)
	{
		free (string);
		return (NULL);
	}
	return (string);
}

char	*string_to_add(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free (stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	i++;
	while (stash[i] != '\0')
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = (read_fd(fd, stash));
	if (!stash)
		return (NULL);
	line = get_current_line(stash);
	if (!line || !(*line))
	{
		free(stash);
		stash = (NULL);
		return (NULL);
	}
	stash = string_to_add(stash);
	if (!stash)
	{
		free(stash);
		stash = (NULL);
	}
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int	fd = open("test.txt", O_RDONLY);
	char	*a;

	while ((a = get_next_line(fd)))
	{
		printf("%s", a);
	}
	//printf("%s", get_next_line(fd));
	return (0);
}
*/
