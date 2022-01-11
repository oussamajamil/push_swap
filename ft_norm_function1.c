/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm_function1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:20:20 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/11 17:52:18 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_marke(t_data *data, int x)
{
	t_table	*markup_head;
	int		a;
	int		d;

	markup_head = ft_select_markup_head(data->structs, x);
	d = markup_head->key;
	a = d;
	markup_head->pos = 1;
	while (markup_head->next)
	{
		markup_head = markup_head->next;
		ft_short_function(&d, markup_head);
	}
	while (markup_head->prev)
		markup_head = markup_head->prev;
	while (markup_head->next)
	{
		if (markup_head->key == a)
			break ;
		ft_short_function(&d, markup_head);
		markup_head = markup_head->next;
	}
}

void	ft_norm_ft_check_sort(int *j, t_data *a, int *arr, int *i)
{
	if (*j >= a->size / 2)
	{
		arr[*i] = *j - a ->size;
		*i = *i + 1;
	}
	else
	{
		arr[*i] = *j;
		*i = *i + 1;
	}
}

void	ft_chechk_sort_a(t_data *a, t_data *b, int *arr)
{
	t_comp_a	data;
	int			j;
	int			i;

	ft_norm_check_sort_a1(&data, a, b, &i);
	while (data.tbb)
	{
		data.last = a->last;
		data.first = a->structs;
		j = 0;
		while (data.first)
		{
			if ((data.last->index > data.first->index
					&& (data.tbb->index < data.first->index
						|| data.tbb->index > data.last->index))
				|| (data.tbb->index > data.last->index
					&& data.tbb->index < data.first->index))
			{
				ft_norm_ft_check_sort(&j, a, arr, &i);
				break ;
			}
			ft_norm_check_sort_a2(&data, &j);
		}
		data.tbb = data.tbb->next;
	}
}

int	ft_table_final(int *comp1, int *comp, int *comp_final, int size)
{
	int	i;
	int	j;
	int	cp;

	i = -1;
	while (++i < size)
		ft_complete_table_final(comp1, comp, comp_final, i);
	i = -1;
	while (++i < size)
	{
		j = -1;
		cp = 0;
		while (++j < size)
		{
			if (comp_final[i] <= comp_final[j])
				cp ++;
		}
		if (cp == size)
			break ;
	}
	return (i);
}

void	ft_boucle_instriction1(t_intger *data, t_data *a, t_data *b)
{
	while (data->a > 0 && data->b < 0)
	{
		ra(a);
		rrb(b);
		ft_putstr_fd("ra\n", 1);
		ft_putstr_fd("rrb\n", 1);
		data->a --;
		data->b++;
	}
	while (data->a < 0 && data->b > 0)
	{
		rra(a);
		rb(b);
		ft_putstr_fd("rra\n", 1);
		ft_putstr_fd("rb\n", 1);
		data->a++;
		data->b--;
	}
	while (data->a > 0 && data->b > 0)
	{
		rr(a, b);
		ft_putstr_fd("rr\n", 1);
		data->a --;
		data->b--;
	}
}
