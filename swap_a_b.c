/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:41:47 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/11 15:22:21 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_data *a, t_data *b)
{
	sa (a);
	sa (b);
}

void	rr(t_data *a, t_data *b)
{
	ra (a);
	rb (b);
}

void	rrr(t_data *a, t_data *b)
{
	rra(a);
	rrb(b);
}

void	ft_index_tab(t_data *b)
{
	t_table	*data;
	int		cp;

	data = b->structs;
	if (b->size == 0)
		return ;
	cp = 0;
	while (data->next)
	{
		data->index_in_your_table = cp;
		cp++;
		data = data->next;
	}
	data->index_in_your_table = cp;
}

void	ft_chechk_sort_b(t_data *a, t_data *b, int *arr)
{
	t_table	*dtb;
	int		cp;
	int		i;

	(void)a;
	dtb = b->structs;
	cp = 0;
	i = 0;
	while (dtb)
	{
		if (dtb->index_in_your_table < b->size / 2)
			cp = dtb->index_in_your_table;
		else
			cp = dtb->index_in_your_table - b->size ;
		arr[i] = cp;
		i++;
		dtb = dtb ->next;
	}
}
