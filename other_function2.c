/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_function2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:52:08 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/07 12:57:15 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_reverse(t_data *data)
{
	t_table	*lst;

	lst = data->last;
	while (lst)
	{
		ft_putnbr_fd(lst->key, 1);
		ft_putchar_fd('\n', 1);
		lst = lst->prev;
	}
}

void	ft_delete_back_node(t_data *data)
{
	t_table	*tb;
	t_table	*lst;

	tb = data->structs;
	if (tb == NULL)
		return ;
	lst = data->last;
	data->last = lst->prev;
	lst->prev->next = NULL;
	data->size--;
	free(lst);
}

t_table	*insertdata(int x, int index, int pos)
{
	t_table	*data;

	data = malloc(sizeof(t_table));
	if (!data)
		return (NULL);
	data->key = x;
	data->next = NULL;
	data->prev = NULL;
	data->index = index;
	data->pos = pos;
	data->index_in_your_table = -1;
	return (data);
}

void	ft_check(t_data *a)
{
	int	cp;

	cp = ft_sherch_markuphead_and_marque(a);
	sa(a);
	if (cp < ft_markup_head(a))
	{
		ft_putstr_fd("sa\n", 1);
		ft_sherch_markuphead_and_marque(a);
	}
	else
		sa(a);
}

void	ft_sort_a(t_data *a, t_data *b)
{
	int		i;
	int		cp;
	t_table	*tmp;

	ft_check(a);
	cp = ft_nombre_push_b(a);
	tmp = a->structs;
	i = 0;
	while (i < cp && ft_nombre_push_b(a) > 0)
	{
		if (a->structs->pos == 0)
		{
			ft_push_a(a, b);
			i++;
		}
		else
		{
			rra(a);
			ft_putstr_fd("rra\n", 1);
			ft_check(a);
			i = 0;
			cp = ft_nombre_push_b(a);
			if (cp < ft_nombre_push_b(a))
				i = 0;
		}
	}
}
