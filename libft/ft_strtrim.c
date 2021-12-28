/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:32:39 by ojamil            #+#    #+#             */
/*   Updated: 2021/11/11 17:40:13 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_start(char const *s1, char const *set)
{
	int	i;
	int	status;

	while (*s1)
	{
		i = 0;
		status = 0;
		while (set[i])
		{
			if (set[i] == *s1 && status == 0)
			{
				s1++;
				status = 1;
			}
			i++;
		}
		if (status == 0)
			break ;
	}
	return ((char *)s1);
}

int	ft_end(char *s1, char const *set)
{
	int	i;
	int	status;
	int	l;

	l = ft_strlen (s1) - 1;
	while (l >= 0)
	{
		i = 0;
		status = 0;
		while (set[i])
		{
			if (set[i] == s1[l] && status == 0)
			{
				l--;
				status = 1;
			}
			i++;
		}
		if (status == 0)
			break ;
	}
	return (l + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*p;
	int		i;

	if (!s1 || !set)
		return (NULL);
	str = ft_start(s1, set);
	p = (char *) malloc (ft_end (str, set) + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < ft_end(str, set))
	{
		p[i] = str[i];
		i++;
	}
	p[i] = 0;
	return (p);
}
