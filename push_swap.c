/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 10:16:34 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/04 15:07:35 by ojamil           ###   ########.fr       */
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

int	ft_markup(t_table *data, int x)
{
	int	cp;
	int	comp;

	cp = 1;
	comp = x;
	while (data->next)
	{
		data = data->next;
		ft_complete_ft_markup(&comp, &cp, data);
	}
	while (data->prev)
		data = data->prev;
	while (data->next && data->key != x)
	{
		ft_complete_ft_markup(&comp, &cp, data);
		data = data->next;
	}
	return (cp);
}

void	ft_marke(t_data *data, int x)
{
	t_table	*markup_head;
	int		a;
	int		d;

	markup_head = ft_select_markup_head(data->structs, x);
	d = markup_head->key;
	a = d;
	markup_head->pos = 1;
	printf("-------markup head :%d--------\n",d);
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

int ft_sherch_maruphead_and_marque(t_data *a)
{
	int cp;

	cp = ft_markup_head(a);
	ft_marke(a, cp);
	return(cp);
}

void	ft_check(t_data *a)
{
	int cp;
	cp = ft_sherch_maruphead_and_marque(a);
	sa(a);
	if (cp < ft_markup_head(a))
	{
		ft_putstr_fd("sa\n",1);
		ft_sherch_maruphead_and_marque(a);
	}
	else
		sa(a);
}

int ft_nombre_push_b(t_data *b)
{
	int cp;
	t_table *a;

	cp = 0;
	a = b->structs;
	while (a->next)
	{
		if (a->pos == 0)
			cp++;
		a = a->next;
	}
	if (a->pos == 0)
			cp++;
	while (a->prev)
		a = a->prev;
	return(cp);
}

void ft_sort_a(t_data *a, t_data *b)
{
	int i;
	int cp;
	t_table *tmp;

	ft_check(a);
	cp = ft_nombre_push_b(a);
	tmp = a->structs;
	i = 0;
	while (i < cp && ft_nombre_push_b(a)> 0)
	{
		if (a->structs->pos == 0)
		{
			ft_push_b(a,b);
			i++;
		}
		else
		{
			rra(a);
			ft_putstr_fd("rra\n",1);
			ft_check(a);
			i = 0;
			cp =ft_nombre_push_b(a);
			if (cp < ft_nombre_push_b(a))
			{
				i = 0;
			}
		}
	}
	
}

int	main(int ac, char *av[])
{
	t_data	a;
	t_data	b;
	char	*str;
	char	**s;
	int		*arr;

	a.structs = NULL;
	b.structs = NULL;
	if (ac >= 2)
	{
		str = ft_strj(ac, av, " ");
		if (!str)
			exit(0);
		s = ft_split(str, ' ');
		free(str);
		ft_check_nember(s);
		ft_check_double(s);
		arr = malloc(sizeof(int) * ac - 1);
		ft_remplire_list(&a, s, arr);
		ft_sort_int_tab(arr, ac - 1);
		ft_remplir_index(&a, arr, ac - 1);
		free(arr);
		ft_check(&a);
		ft_sort_a(&a,&b);
		ft_print(&a);
		ft_print(&b);
	}
}
