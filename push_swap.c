/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 10:16:34 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/07 14:32:39 by ojamil           ###   ########.fr       */
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

int	ft_sherch_markuphead_and_marque(t_data *a)
{
	int	cp;

	cp = ft_markup_head(a);
	ft_marke(a, cp);
	return (cp);
}

int	ft_nombre_push_b(t_data *b)
{
	int		cp;
	t_table	*a;

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
	return (cp);
}

void 	ft_chechk_sort_b(t_data *a,t_data *b,int *arr)
{
	t_table	*dta;
	t_table	*dtb;
	int	cp;
	int i;

	dta = a->structs;
	dtb = b->structs;
	cp = 0; 
	i = 0;
	free(arr);
	if (b->size == 0)
		exit(0);
	arr =malloc(sizeof(int) * b->size);
	if (!arr)
		exit(0);
	while (dtb)
	{
		if (dtb->index_in_your_table < b->size / 2)
			cp = dtb->index_in_your_table;
		else
			cp = dtb->index_in_your_table - b->size ;
		arr[i] = cp;
		i++;
		if (!dtb->next)
			break;
		dtb = dtb ->next;
	}	
}

void 	ft_chechk_sort_a(t_data *a,t_data *b,int *arr)
{
	t_comp_a data;
	int	j;
	int i;
	
	data.tba = a ->structs;
	data.tbb = b ->structs;
	j = 0;
	i = 0;
	free(arr);
	arr = malloc(sizeof(int) * b->size);
	if (!data.tbb)
	{
		free(arr);
		exit(0);
	}
	else
	{
		if (data.tbb)
		{
			while (data.tbb)
			{
				data.last = a->last;
				data.first = a->structs;
				j = 0;
				while (data.first)
				{
					if ((data.last->index > data.first->index && 
					(data.tbb->index < data.first->index || data.tbb->index > data.last->index))
					 || (data.tbb->index > data.last->index && data.tbb->index < data.first->index))
					{
						// printf("last %d\n",data.last->index);
						// printf("first %d\n",data.first->index);
						// printf("current %d\n",data.tbb->index);
						if (j > a->size / 2)
						{
							arr[i] = j - a ->size;
							i++;
							break;
						}
						else
						{
							arr[i] = j;
							i++;
							break;
						}
					}
						data.last = data.first;
						data.first = data.first->next;
						j++;
				}
				data.tbb = data.tbb->next;
			}
		}
	}
}

void	ft_index_tab(t_data *b)
{
	t_table *data;
	int		cp;

	data = b->structs;
	if (!data)
		return ;
	cp = 0;
	while (data->next)
	{
		data->index_in_your_table = cp;
		cp++;
		data = data->next;
	}
	data->index_in_your_table = cp;
}

void ft_check_tab_int(int *arr,int size,t_data *a)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				free(arr);
				ft_putstr_fd("error doubles",1);
				ft_free_list(a);
				exit(0);
			}
			j++;
		}
		i++;
	}
	
}
int	ft_table_final(int *comp1,int *comp,int *comp_final,int size)
{
	int i;
	int j;
	int cp;
	
	i = 0;
	while (i < size)
	{
		if (comp1[i] < 0 && comp[i] < 0)
			comp_final[i] = (comp1[i] * -1) + (comp[i] * -1);
		else if (comp1[i] < 0 && comp[i] >= 0)
			comp_final[i] = (comp1[i] * -1) + (comp[i]);
		else if (comp1[i] >= 0 && comp[i] < 0)
			comp_final[i] = (comp1[i]) + (comp[i] * -1);
		else if (comp1[i] >= 0 && comp[i] >= 0)
			comp_final[i] = comp1[i] + comp[i];
		printf("%d ------***-- *%d---*****%d\n",comp_final[i],comp1[i],comp[i]);
		i++;
	}
	i = -1;
	cp = 0;
	while (++i < size)
	{
		j = -1;
		cp = 0;
		while (++j < size)
		{
			if (comp_final[i] <= comp_final[j])
			 	cp ++;
		}
		if (cp == size - 1)
			break ;
	}
	return (i - 1);
}

void ft_push_b_to_a(t_data *a,t_data *b,int *comp1,int *comp)
{
	int result_comp;
	int *comp_final;
	int i;
	t_intger data;
	(void)a;
	ft_chechk_sort_b(a,b,comp1);
	ft_chechk_sort_a(a,b,comp);
	ft_print(a);
	ft_print(b);
	comp_final = malloc(sizeof(int) * b->size);
	result_comp = ft_table_final(comp1,comp,comp_final,b->size);
	i = 0;
	while (i < b->size)
	{
		printf("%d*****************%d************%d**************%d\n",comp_final[i],comp1[i],comp[i],result_comp);
		i++;
	}
	
	data.a1 = comp1[result_comp];
	data.a2 = comp[result_comp];
	// printf("%d ******---*****---*******--**%d\n",data.a1,data.a2);
	while (data.a1 > 0 && data.a2>0)
	{
		rr(a,b);
		ft_putstr_fd("rr\n",1);
		data.a1 --;
		data.a2--;
	}
	while (data.a1 < 0 && data.a2 < 0)
	{
		rrr(a,b);
		ft_putstr_fd("rrr\n",1);
		data.a1++;
		data.a2++;
	}
	while (data.a1 == 0 && data.a2 < 0)
	{
		rra(a);
		ft_putstr_fd("rra\n",1);
		data.a2++;
	}
	while (data.a1 == 0 && data.a2 > 0)
	{
		ra(a);
		ft_putstr_fd("ra\n",1);
		data.a2--;
	}
	while (data.a1 < 0 && data.a2 == 0)
	{
		rrb(b);
		ft_putstr_fd("rrb\n",1);
		data.a1++;
	}
	while (data.a1 > 0 && data.a2 == 0)
	{
		rb(b);
		ft_putstr_fd("rb\n",1);
		data.a1--;
	}
	ft_push_b(a,b);
	ft_putstr_fd("pb\n",1);
	// // free(comp_final);
}

void	ft_push_a_b_final(t_data *a,t_data *b)
{
	int i;
	int *comp1;
	int *comp;
	int *comp_final;

	i = 0;
	comp_final = NULL;
	comp = malloc(sizeof(int) * b->size);
	comp1 = malloc(sizeof(int) * b->size);
	ft_push_b_to_a(a,b,comp1,comp);
	free(comp1);
	free(comp);
}

int	main(int ac, char *av[])
{
	t_data	a;
	t_data	b;
	t_string txt;
	int i;
	
	i = 0;
	a.structs = NULL;
	b.structs = NULL;
	if (ac >= 2)
	{
		txt.str = ft_strj(ac, av, " ");
		if (!txt.str)
			exit(0);
		txt.s = ft_split(txt.str, ' ');
		free(txt.str);
		ft_check_nember(txt.s);
		ft_check_double(txt.s);
		txt.long_str = ft_nombre_mots(txt.s);
		txt.arr = malloc(sizeof(int) * txt.long_str - 1);
		ft_remplire_list(&a, txt.s, txt.arr);
		ft_free_str(txt.s);
		ft_check_tab_int(txt.arr,a.size,&a);
		ft_sort_int_tab(txt.arr, txt.long_str - 1);
		ft_remplir_index(&a, txt.arr, txt.long_str - 1);
		free(txt.arr);
		ft_check(&a);
		ft_sort_a(&a,&b);
		ft_index_tab(&b);
		ft_index_tab(&a);
		if (b .size > 0)
		{
			while (b.size > 0)
			{
				ft_push_a_b_final(&a,&b);
				ft_index_tab(&b);
				ft_index_tab(&a);
			}
		}
		ft_print(&a);
		ft_print(&b);
	}
}
