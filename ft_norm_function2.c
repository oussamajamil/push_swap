/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm_function2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:20:51 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/13 14:08:28 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_complete_ft_markup(int *cmp, int *cp, t_table *data)
{
	if (*cmp < data->key)
	{
		*cp = *cp + 1;
		*cmp = data->key;
	}
}

int	ft_sherch_markuphead_and_marque(t_data *a)
{
	int	cp;

	cp = ft_markup_head(a);
	ft_marke(a, cp);
	return (cp);
}

void	ft_complete_table_final(int *comp1, int *comp, int *comp_final, int i)
{
	if (comp1[i] < 0 && comp[i] < 0)
			comp_final[i] = (comp1[i] * -1) + (comp[i] * -1);
	else if (comp1[i] < 0 && comp[i] >= 0)
			comp_final[i] = (comp1[i] * -1) + (comp[i]);
	else if (comp1[i] >= 0 && comp[i] < 0)
			comp_final[i] = (comp1[i]) + (comp[i] * -1);
	else if (comp1[i] >= 0 && comp[i] >= 0)
			comp_final[i] = comp1[i] + comp[i];
}

void	ft_boucle_instriction2(t_intger *data, t_data *a, t_data *b)
{
	while (data->a < 0 && data->b < 0)
	{
		rrr(a, b);
		ft_putstr_fd("rrr\n", 1);
		data->a++;
		data->b++;
	}
	while (data->a == 0 && data->b < 0)
	{
		rrb(b);
		ft_putstr_fd("rrb\n", 1);
		data->b++;
	}
	while (data->a == 0 && data->b > 0)
	{
		rb(b);
		ft_putstr_fd("rb\n", 1);
		data->b--;
	}
	while (data->a < 0 && data->b == 0)
	{
		rra(a);
		ft_putstr_fd("rra\n", 1);
		data->a++;
	}
}

void	ft_short_b_to_a2(t_intger *data, t_data *a, t_data *b)
{
	ft_boucle_instriction1(data, a, b);
	ft_boucle_instriction2(data, a, b);
	while (data->a > 0 && data->b == 0)
	{
		ra(a);
		ft_putstr_fd("ra\n", 1);
		data->a--;
	}
	pa(a, b);
	ft_putstr_fd("pa\n", 1);
}
