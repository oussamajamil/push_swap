/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:12:57 by ojamil            #+#    #+#             */
/*   Updated: 2021/11/11 10:14:23 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str1;
	char	*str2;

	str1 = (char *) dst;
	str2 = (char *) src;
	if (str2 == NULL && str1 == NULL)
		return (NULL);
	if (str1 < str2)
	{
		return (ft_memcpy(dst, src, len));
	}
	else
	{
		while (len > 0)
		{
			str1[len - 1] = str2[len - 1];
			len--;
		}
		return (str1);
	}
}
