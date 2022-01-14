/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_function4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:35:09 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/14 13:17:35 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_list(t_data *dt)
{
	t_table	*tmp;
	t_table	*lst;

	if (!dt)
		return ;
	lst = dt ->structs;
	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

void	ft_remplire_list(t_data *a, char **str, int *arr)
{
	int			i;
	int			j;
	long long	n;

	i = 1;
	j = 0;
	while (str[i])
	{
		n = ft_atoi(str[i]);
		if (n < -2147483648 || n > 2147483647)
		{
			ft_free_list(a);
			free(arr);
			ft_putstr_fd("Error", 1);
			exit(0);
		}
		ft_add_back(a, n, -1, -1);
		arr[j] = n;
		j++;
		i++;
	}
}

int	ft_markup_head(t_data *dt)
{
	t_table	*data;
	int		cp;
	int		x;

	data = dt->structs;
	cp = 0;
	while (data->next)
	{
		x = ft_markup(data, data->key);
		if (cp < x)
			cp = x;
		data = data->next;
	}
	x = ft_markup(data, data->key);
	if (cp < x)
		cp = x;
	while (data->prev)
	{
		data = data->prev;
	}
	return (cp);
}

void	ft_complete_remplir_index(t_table *head, int *arr, int *a, int *i)
{
	if (head->key == arr[*i] && *a == 0)
	{
		*a = 1;
		head->index = *i;
	}
}

void	ft_remplir_index(t_data *dt, int *arr, int ac)
{
	int		i;
	t_table	*head;
	int		a;

	i = -1;
	head = dt->structs;
	while (++i < ac)
	{
		a = 0;
		while (head->next)
		{
			ft_complete_remplir_index(head, arr, &a, &i);
			head = head->next;
		}
		while (head->prev)
		{
			ft_complete_remplir_index(head, arr, &a, &i);
			head = head->prev;
		}
	}
}
