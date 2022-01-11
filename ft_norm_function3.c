/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm_function3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:50:36 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/11 17:53:05 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_norm_check_sort_a1(t_comp_a *data, t_data *a, t_data *b, int *i)
{
	*i = 0;
	data->tba = a ->structs;
	data->tbb = b ->structs;
}

void	ft_norm_check_sort_a2(t_comp_a *data, int *i)
{
	*i = *i + 1;
	data->last = data->first;
	data->first = data->first->next;
}

int	ft_markup(t_table *data, int x)
{
	int	cp;
	int	comp;

	cp = 1;
	comp = x;
	while (data->next)
	{
		data = data->next;
		ft_complete_ft_markup(&comp, &cp, data);
	}
	while (data->prev)
		data = data->prev;
	while (data->next && data->key != x)
	{
		ft_complete_ft_markup(&comp, &cp, data);
		data = data->next;
	}
	return (cp);
}
