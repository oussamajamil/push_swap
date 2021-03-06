/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_function1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:51:45 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/13 14:08:09 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_table	*ft_add_head(t_data *table, int x, int index, int pos)
{
	t_table	*dt;

	dt = insertdata (x, index, pos);
	if (!dt)
		return (NULL);
	if (table->structs)
	{
		table->structs->prev = dt;
		dt->next = table->structs;
	}
	else
	{
		table->size = 0;
		table->last = dt;
	}
	table->structs = dt;
	table->size++;
	return (table->structs);
}

t_table	*ft_add_back(t_data *table, int x, int index, int pos)
{
	t_table	*data;
	t_table	*last;

	data = insertdata(x, index, pos);
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

void	ft_print(t_data *data)
{
	t_table	*tmp;
	int		i;

	tmp = data->structs;
	i = 0;
	while (tmp)
	{
		ft_putnbr_fd(tmp->key, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
	ft_putstr_fd("---------------------------------\n", 1);
}

void	ft_delete_first_node(t_data *data)
{
	t_table	*dt;

	if (data->structs)
	{
		dt = data->structs;
		if (dt->next != NULL)
			dt->next->prev = NULL;
		data->structs = dt->next;
		data->size--;
		free(dt);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
