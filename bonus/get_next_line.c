/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 09:48:42 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/14 13:37:59 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlens(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoins(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;
	int		l;

	i = -1;
	j = 0;
	result = NULL;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = 0;
	}
	l = ft_strlens(s1) + ft_strlens(s2);
	result = (char *)malloc(sizeof(char) * (l + 1));
	while (s1[++i])
		result[i] = s1[i];
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = 0;
	free(s1);
	return (result);
}

char	*ft_short_get_lines(char *buffer, char *line, int i)
{
	if (i == 1)
	{
		free(buffer);
		return (line);
	}
	if (i == 2)
	{
		if (buffer)
			free(buffer);
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_lines(int fd)
{
	char	*line;
	char	*buffer;
	int		a;

	line = NULL;
	buffer = (char *)malloc(sizeof(char) * 2);
	while (1)
	{
		a = read(fd, buffer, 1);
		if (a == -1)
			return (ft_short_get_lines(buffer, line, 2));
		if (a == 0)
			return (ft_short_get_lines(buffer, line, 1));
		buffer[1] = 0;
		if (buffer[0] == '\n')
		{
			line = ft_strjoins(line, buffer);
			return (ft_short_get_lines(buffer, line, 1));
		}
		line = ft_strjoins(line, buffer);
	}
	return (ft_short_get_lines(buffer, line, 1));
}

char	*get_next_lines(int fd)
{
	char	*result;

	result = NULL;
	if (fd < 0)
		return (NULL);
	result = get_lines(fd);
	return (result);
}
