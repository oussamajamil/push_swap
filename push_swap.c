/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 10:16:34 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/10 15:05:45 by ojamil           ###   ########.fr       */
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
	int comp;

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
	t_table *markup_head;
	int		a;
	int		d;

	markup_head = ft_select_markup_head(data->structs, x);
	d = markup_head->key;
	a = d;
	markup_head->pos = 1;
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
	int cp;

	cp = ft_markup_head(a);
	ft_marke(a, cp);
	return (cp);
}

void	ft_chechk_sort_a(t_data *a,t_data *b,int *arr)
{
	t_comp_a	data;
	int			j;
	int 		i;

	data.tba = a ->structs;
	data.tbb = b ->structs;
	j = 0;
	i = 0;

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
		i++;
	}
	i = -1;
	while (++i < size)
	{
		j = -1;
		cp = 0;
		while (++j < size)
		{
			if (comp_final[i] <= comp_final[j])
				cp ++;
		}
		if (cp == size)
			break ;
	}
	return (i);
}

void ft_push_b_to_a(t_data *a,t_data *b)
{
  int result_comp;
  int comp_final[b->size];
  int comp[b->size];
  int comp1[b->size];
  t_intger data;
  
  ft_chechk_sort_b(a,b,comp1);
  ft_chechk_sort_a(a,b,comp);
  result_comp = ft_table_final(comp1,comp,comp_final,b->size);
  data.a = comp[result_comp];
  data.b = comp1[result_comp];
  while (data.a > 0 && data.b<0)
  {
    ra(a);
    rrb(b);
    ft_putstr_fd("ra\n",1);
    ft_putstr_fd("rrb\n",1);
    data.a --;
    data.b++;
  }
  while (data.a< 0 && data.b > 0)
  {
    rra(a);
    rb(b);
    ft_putstr_fd("rra\n",1);
    ft_putstr_fd("rb\n",1);
    data.a++;
    data.b--;
  }
  while (data.a > 0 && data.b>0)
  {
    rr(a,b);
    ft_putstr_fd("rr\n",1);
    data.a --;
    data.b--;
  }
  while (data.a< 0 && data.b < 0)
  {
    rrr(a,b);
    ft_putstr_fd("rrr\n",1);
    data.a++;
    data.b++;
  }
  while (data.a == 0 && data.b < 0)
  {
    rrb(b);
    ft_putstr_fd("rrb\n",1);
    data.b++;
  }
  while (data.a == 0 && data.b > 0)
  {
    rb(b);
    ft_putstr_fd("rb\n",1);
    data.b--;
  }
  while (data.a < 0 && data.b == 0)
  {
    rra(a);
    ft_putstr_fd("rra\n",1);
    data.a++;
  }
  while (data.a > 0 && data.b == 0)
  {
    ra(a);
    ft_putstr_fd("ra\n",1);
    data.a--;
  }
  pa(a,b);
  ft_putstr_fd("pa\n",1);
}

int main(int ac, char *av[])
{
  t_data a;
  t_data b;
  t_string txt;

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
    ft_check_tab_int(txt.arr,a.size,&a);
    ft_sort_int_tab(txt.arr, txt.long_str - 1);
    ft_remplir_index(&a, txt.arr, txt.long_str - 1);
    free(txt.arr);
    ft_sort_final(a,b);
  }
}
