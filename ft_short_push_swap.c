/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_push_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:02:41 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/12 12:03:46 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_int_ft_push_b_to_a(int *a, int *b, int *c, int i)
{
	if (i == 2)
		free(a);
	else if (i == 3)
	{
		free(b);
		free(a);
	}
	if (i == 4)
	{
		free(b);
		free(a);
		free(c);
		return ;
	}
	exit (0);
}

void	ft_push_b_to_a(t_data *a, t_data *b)
{
	int			result_comp;
	int			*comp_final;
	int			*comp;
	int			*comp1;
	t_intger	data;

	comp_final = NULL;
	comp = NULL;
	comp1 = NULL;
	comp1 = malloc(sizeof(int) * b->size);
	if (!comp1)
		ft_free_int_ft_push_b_to_a(comp1, comp, comp_final, 1);
	comp = malloc(sizeof(int) * b->size);
	if (!comp)
		ft_free_int_ft_push_b_to_a(comp1, comp, comp_final, 2);
	comp_final = malloc(sizeof(int) * b->size);
	if (!comp_final)
		ft_free_int_ft_push_b_to_a(comp1, comp, comp_final, 3);
	ft_chechk_sort_b(a, b, comp1);
	ft_chechk_sort_a(a, b, comp);
	result_comp = ft_table_final(comp1, comp, comp_final, b->size);
	data.a = comp[result_comp];
	data.b = comp1[result_comp];
	ft_free_int_ft_push_b_to_a(comp1, comp, comp_final, 4);
	ft_short_b_to_a2(&data, a, b);
}
