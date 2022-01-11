/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 10:16:34 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/11 17:55:36 by ojamil           ###   ########.fr       */
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

int	main(int ac, char *av[])
{
	t_data		a;
	t_data		b;
	t_string	txt;

	a.structs = NULL;
	b.structs = NULL;
	if (ac >= 2)
	{
		txt.str = ft_strj(ac, av, " ");
		if (txt.str == NULL)
			exit(0);
		txt.s = ft_split(txt.str, ' ');
		free(txt.str);
		ft_check_nember(txt.s);
		ft_check_double(txt.s);
		txt.long_str = ft_nombre_mots(txt.s);
		txt.arr = malloc(sizeof(int) * txt.long_str - 1);
		ft_remplire_list(&a, txt.s, txt.arr);
		ft_free_str(txt.s);
		ft_check_tab_int(txt.arr, a.size, &a);
		ft_sort_int_tab(txt.arr, txt.long_str - 1);
		ft_remplir_index(&a, txt.arr, txt.long_str - 1);
		free(txt.arr);
		ft_sort_final(a, b);
	}
}
