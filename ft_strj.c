/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 10:44:54 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/10 09:29:05 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_lenght(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_count_malloc(int size, char **strs, char *sep)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (i < size)
	{
		if (i == size - 1)
			r = r + ft_lenght(strs[i]);
		else
			r = r + ft_lenght(strs[i]) + ft_lenght(sep);
		i++;
	}
	return (r);
}

void	ft_create_strjoin(int size, char **strs, char *sep, char *p)
{
	int	a;
	int	i;
	int	k;

	i = -1;
	a = 0;
	while (++i < size)
	{
		k = -1;
		while (strs[i][++k] != '\0')
			p[a++] = strs[i][k];
		k = -1;
		if (i < size - 1)
		{
			while (sep[++k] != '\0')
				p[a++] = sep[k];
		}
	}
	p[a] = '\0';
}

char	*ft_strj(int size, char **strs, char *sep)
{
	int		i;
	int		a;
	char	*p;

	i = -1;
	a = 0;
	if (size == 0)
	{
		p = (char *) malloc(sizeof(char));
		if (!p)
			return (NULL);
		p[0] = 0;
		return (p);
	}
	p = (char *) malloc(sizeof(char *) * ft_count_malloc(size, strs, sep) + 1);
	if (!p)
		return (NULL);
	ft_create_strjoin(size, strs, sep, p);
	return (p);
}
