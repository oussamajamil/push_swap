/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:47:40 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/14 13:55:20 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_norm(void)
{
	ft_putstr_fd("Error", 1);
	exit(0);
}

void	ft_execut_function(char *line, t_data *a, t_data *b)
{
	if (ft_strcmp(line, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(line, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b);
	else
		ft_norm();
}

int	ft_check_sort_table(t_data *a)
{
	t_table	*tmp1;
	t_table	*tmp2;
	int		i;

	tmp1 = a ->structs;
	i = 0;
	while (tmp1)
	{
		if (!tmp1->next)
			break ;
		tmp2 = tmp1->next;
		if (tmp1->key < tmp2->key)
			tmp1 = tmp1->next;
		else
			return (-1);
	}
	return (0);
}

void	ft_checker(t_data *a, t_data *b)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_lines(0);
		while (line != NULL)
		{
			ft_execut_function(line, a, b);
			line = get_next_lines(0);
		}
		if (ft_check_sort_table(a) == 0)
			ft_putstr_fd("\033[0;32mOK\n", 1);
		else
			ft_putstr_fd("\033[0;31mKO\n", 1);
		ft_free_list(a);
		exit(0);
	}
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
		ft_checker(&a, &b);
	}
}
