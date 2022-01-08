/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 10:16:34 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/08 18:15:15 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_complete_ft_markup(int *cmp, int *cp, t_table *data)
{
  if (*cmp < data->key)
  {
    *cp = *cp + 1;
    *cmp = data->key;
  }
}

int ft_markup(t_table *data, int x)
{
  int cp;
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

void ft_marke(t_data *data, int x)
{
  t_table *markup_head;
  int a;
  int d;

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

int ft_sherch_markuphead_and_marque(t_data *a)
{
  int cp;

  cp = ft_markup_head(a);
  ft_marke(a, cp);
  return (cp);
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
  return (cp);
}

void ft_chechk_sort_b(t_data *a,t_data *b,int *arr)
{
  t_table *dtb;
  int cp;
  int i;
  
  (void)a;
  dtb = b->structs;
  cp = 0;
  i = 0;
  // free(arr);
  if (b->size == 0)
    exit(0);
  // arr =malloc(sizeof(int) * b->size);
  if (!arr)
    exit(0);
  if (b->size == 1)
  {
    arr[0] = 0;
    return ;
  }
  while (dtb)
  {
    if (dtb->index_in_your_table < b->size / 2)
      cp = dtb->index_in_your_table;
    else
      cp = dtb->index_in_your_table - b->size ;
    arr[i] = cp;
    i++;
    dtb = dtb ->next;
  }
}

void ft_chechk_sort_a(t_data *a,t_data *b,int *arr)
{
  t_comp_a data;
  int j;
  int i;
  
  data.tba = a ->structs;
  data.tbb = b ->structs;
  j = 0;
  i = 0;
  // // free(arr);
  // // arr = malloc(sizeof(int) * b->size);
  // if (!data.tbb)
  // {
  //   //free(arr);
  //   exit(0);
  // }
  // else
  // {
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
// }

void ft_index_tab(t_data *b)
{
  t_table *data;
  int cp;

  data = b->structs;
  if (b->size == 0)
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
int ft_table_final(int *comp1,int *comp,int *comp_final,int size)
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
    if (cp == size)
      break ;
  }
  return (i);
}

void ft_push_b_to_a(t_data *a,t_data *b)
{
  int result_comp;
  int comp_final[b->size];
  t_intger data;
  int i;
  int comp[b->size];
  int comp1[b->size];
  
  i = 0;;
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

void ft_push_a_b_final(t_data *a,t_data *b)
{
  ft_push_b_to_a(a,b);
}

int ft_sherche_pos0(t_data *a)
{
	t_table *data;
	int	i;

	data = a -> structs;
	i = 0;
	while(i < a->size)
	{
		if(data->index == 0)
		{
			break;
		}
		else
			data = data->next;
		i++;
	}
  if (i < a->size / 2)
    return(i);
  else
    return(i - a->size);
}

void ft_organize_list(t_data *a , int pos)
{
  t_table *data;

  data = a ->structs;

  while (pos < 0)
  {
      rra(a);
      ft_putstr_fd("rra\n",1);
      pos ++;
  }
  while (pos > 0)
  {
    ra(a);
    ft_putstr_fd("ra\n",1);
    pos --;
  }
}

int main(int ac, char *av[])
{
  t_data a;
  t_data b;
  t_string txt;
  int pos;

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
    ft_check(&a);
    ft_sort_a(&a,&b);
    ft_index_tab(&a);
    ft_index_tab(&b);
    if (b .size > 0)
    {
      while (b.size > 0)
      {
        ft_push_a_b_final(&a,&b);
        ft_index_tab(&b);
        ft_index_tab(&a);
      }
    }
    pos = ft_sherche_pos0(&a);
    ft_organize_list(&a,pos);
    // ft_print(&a);
  }
}