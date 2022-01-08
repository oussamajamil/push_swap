/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:08:42 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/08 18:00:22 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *a)
{
	int	x;

	if (a->structs == NULL)
		return ;
	x = a->last->key;
	ft_add_head(a, x,a->last->index, a->last->pos);
	ft_delete_back_node(a);
}

void	ra(t_data *a)
{
	t_table	*dt;
	int		x;

	dt = a->structs;
	if (dt == NULL)
		return ;
	x = dt->key;
	ft_add_back(a, x,dt->index,dt->pos);
	ft_delete_first_node(a);
}

void	sa(t_data *a)
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

void	pa(t_data *a, t_data *b)
{
	int	x;

	if (b->structs)
	{
		x = b->structs->key;
		ft_add_head(a, x,b->structs->index,b->structs->pos);
		ft_delete_first_node(b);
	}
	else
		return ;
}
