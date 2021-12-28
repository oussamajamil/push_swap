/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:47:47 by ojamil            #+#    #+#             */
/*   Updated: 2021/11/12 09:43:10 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	results;
	size_t	i;

	len_src = ft_strlen(src);
	len_dst = ft_strlen (dst);
	results = 0;
	i = 0;
	if (dstsize > len_dst)
		results = len_dst + len_src;
	else
		return (len_src + dstsize);
	while (src[i] && dstsize - len_dst - 1 > 0)
	{
		dst[len_dst] = src[i];
		len_dst++;
		i++;
	}
	dst[len_dst] = 0;
	return (results);
}
