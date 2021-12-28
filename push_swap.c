/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 10:16:34 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/28 17:52:18 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_controller_arg(int argc, char *argv[])
{
	int i;
	int j;

	i = 0;
	if (argc > 1)
	{
		while (++i < argc)
		{
			j = -1;
			while (argv[i][++j])
			{
				if (ft_isdigit(argv[i][j]) == 0)
					return (-1);
			}
		}
		return (0);
	}
	else
		return (-1);
}
t_table *InsertData(int x)
{
	t_table *data;

	data = malloc(sizeof(t_table));
	if (!data)
		return (NULL);
	data->key = x;
	data->next = NULL;
	data->prev = NULL;
	return (data);
}

t_table *ft_add_back(t_data *table, int x)
{
	t_table *data;
	t_table *last;
	data = InsertData(x);
	if (!data)
		return (NULL);
	if (table->structs)
	{
		last = table->last;
		last->next = data;
		data->prev = last;
	}
	else
	{
		table->size = 0;
		table->structs = data;
	}
	table->last = data;
	table->size++;
	return (table->structs);
}

void ft_print(t_data *data)
{
	t_table *tmp;

	tmp = data->structs;
	while (tmp)
	{
		printf("%d\n", tmp->key);
		tmp = tmp->next;
	}
}

void ft_print_reverse(t_data *data)
{
	while (lst)
	{
		printf("%d\n", lst->key);
		lst = lst->prev;
		write(1, "here\n", 5);
	}
}

int main()
{
	t_data data;
	data.structs = NULL;
	ft_add_back(&data, 1);
	ft_add_back(&data, 2);
	ft_add_back(&data, 5);
	ft_add_back(&data, 7);
	ft_add_back(&data, 10);
	ft_print(&data);
	ft_print_reverse(&data);
}
// write(1,"here\n", 5);