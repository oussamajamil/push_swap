/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:27:53 by ojamil            #+#    #+#             */
/*   Updated: 2021/11/10 19:53:55 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*str;
	unsigned char	cr;

	str = (char *)b;
	i = 0;
	cr = (unsigned char)c;
	while (i < len)
	{
		str[i] = cr;
		i++;
	}
	return (str);
}
