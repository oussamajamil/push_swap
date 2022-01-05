/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otherfunction3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:45:53 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/05 18:56:11 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				temp = tab[j];
				tab[j] = tab[i];
				tab[i] = temp;
			}
			j++;
		}
		i++;
	}
}

int	ft_check_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (-1);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

void	ft_check_nember(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_check_str(str[i]) == -1)
		{
			ft_putstr_fd("error de paramette", 1);
			ft_free_str(str);
			exit(0);
		}
		i++;
	}
}

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_check_double(char **s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		j = i + 1;
		if (s[j] == '\0')
			break ;
		while (s[j])
		{
			if (ft_strcmp(s[i], s[j]) == 0)
			{
				ft_putstr_fd("error doubles", 1);
				ft_free_str(s);
				exit(0);
			}
			j++;
		}
		i++;
	}
}
