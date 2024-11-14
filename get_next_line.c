/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:46:42 by danielda          #+#    #+#             */
/*   Updated: 2024/11/14 17:20:09 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strchr(const char *s, int c)
{
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len1 + 1);
	ft_strlcat(result, s2, len1 + len2 + 1);
	return (result);
}

size_t	check_len(size_t len, size_t strlen, unsigned int start)
{
	if (len > strlen - start)
		len = strlen - start;
	return (len);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	len = check_len(len, ft_strlen(s), start);
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
char *ft_strjoin(char const *s1, char const *s2)
char *ft_strchr(const char *s, int c)
char *ft_strdup(const char *s)
size_t ft_strlen(const char *s)

int get_next_line(int fd, char **line)
{
	static char *remainder
	char buffer[BUFFER_SIZE + 1]
	char *temp
	int bytes_read

	if (fd < 0 || !line || buffer_size <= 0)
		return (-1);
	while ()
}
