/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:05:30 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/13 18:23:41 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_tab_int(int *arr, int size, t_data *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				free(arr);
				ft_putstr_fd("error doubles", 1);
				ft_free_list(a);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

int	ft_sherche_pos0(t_data *a)
{
	t_table	*data;
	int		i;

	data = a -> structs;
	i = 0;
	while (i < a->size)
	{
		if (data->index == 0)
			break ;
		else
			data = data->next;
		i++;
	}
	if (i < a->size / 2)
		return (i);
	else
		return (i - a -> size);
}

void	ft_organize_list(t_data *a, int pos)
{
	t_table	*data;

	data = a ->structs;
	while (pos < 0)
	{
		rra(a);
		ft_putstr_fd("rra\n", 1);
		pos ++;
	}
	while (pos > 0)
	{
		ra(a);
		ft_putstr_fd("ra\n", 1);
		pos --;
	}
}

void	ft_sort_final(t_data a, t_data b)
{
	int	pos;

	ft_check(&a);
	ft_sort_a(&a, &b);
	ft_index_tab(&a);
	ft_index_tab(&b);
	while (b.size > 0)
	{
		ft_push_b_to_a(&a, &b);
		ft_index_tab(&b);
		ft_index_tab(&a);
	}
	pos = ft_sherche_pos0(&a);
	ft_organize_list(&a, pos);
	ft_print(&a);
	ft_free_list(&a);
	ft_free_list(&b);
}

int	ft_nombre_push_b(t_data *b)
{
	int		cp;
	t_table	*a;

	cp = 0;
	a = b->structs;
	while (a)
	{
		if (a->pos == 0)
			cp++;
		a = a->next;
	}
	return (cp);
}
