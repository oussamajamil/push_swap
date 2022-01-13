/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 10:16:34 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/13 13:47:41 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
