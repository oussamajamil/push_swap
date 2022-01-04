/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_function2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:52:08 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/04 14:24:25 by ojamil           ###   ########.fr       */
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
	return (data);
}
