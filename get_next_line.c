/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:46:42 by danielda          #+#    #+#             */
/*   Updated: 2024/11/20 16:51:43 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*read_fd(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
	bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			if (bayts_read == 0)
				return (stash);
			return (NULL);
		}
	buffer[bytes_read] = '\0';
	stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
		return (stash);
	}
}

int	get_current_line(char *stash)
{
	int		i;
	char	*string;

	if (!stash[i] || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	i++;
	string = ft_substr(stash, 0, i + ft_endl(stash));
	return (string);
}

char	*string_to_add(char *stash)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	string = malloc(sizeof(char) * (ft_strlen(stash) - i));
	if (!string)
		return (NULL);
	while (stash[++i])
		string[j++] = stash[i];
	string[j] = '\0';
	free(stash);
	return (string);
}

int	get_next_line(int fd, char **line)
{
	static char	*stash;
	char		*temp;
	int			bytes_read;

	if (fd < 0 || !line || buffer_size <= 0)
		return (-1);
	stash = (read(fd, buffer, buffer_size) < 0)
		if (!stash)
		return (-1);
	line = get_current_line(stash)
		if (!(*line))
		return (-1);
	stash = string_to_add(stash);
	if (!stash)
		return (0);
	return (-1);
}
