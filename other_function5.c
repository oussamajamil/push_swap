/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_function5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:05:26 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/05 10:19:37 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_short_function(int *d, t_table *markup_head)
{
	if (*d < markup_head->key)
	{
		markup_head->pos = 1;
		*d = markup_head ->key;
	}
	else
		markup_head->pos = 0;
}

t_table	*ft_select_markup_head(t_table *data, int y)
{
	int	cp;
	int	x;
	int	index;

	cp = 0;
	index = -1;
	while (data->next)
	{
		if (index == -1)
		{
			x = ft_markup(data, data->key);
			if (y == x)
			{
				index = 0 ;
				return (data);
			}
		}
		data = data->next;
	}
	x = ft_markup(data, data->key);
	if (y == x)
		return (data);
	while (data->prev)
		data = data->prev;
	return (data);
}

int ft_nombre_mots(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;;
	}
	return (i);
}
