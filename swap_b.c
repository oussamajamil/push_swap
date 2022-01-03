/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:08:58 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/03 11:21:19 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_data *a)
{
	t_table	*dt;
	int		x;

	dt = a->structs;
	if (dt == NULL)
		return ;
	x = dt->key;
	ft_delete_first_node(a);
	ft_add_back(a, x);
}

void	sb(t_data *a)
{
	t_table	*tab;
	t_table	*next;

	tab = a->structs;
	if (tab == NULL || tab->next == NULL)
		return ;
	next = a->structs->next;
	if (tab->next != NULL)
	{
		next->prev = NULL;
		if (a->size > 2)
		{
			next->next->prev = tab;
			tab->next = next->next;
		}
		else
		{
			next->next = NULL;
			tab->next = NULL;
		}
		tab->prev = next;
		next->next = tab;
		a->structs = next;
	}
}

void	ft_push_b(t_data *a, t_data *b)
{
	int	x;

	if (a->structs)
	{
		x = a->structs->key;
		ft_add_head(b, x);
		ft_delete_first_node(a);
	}
	else
		return ;
}
