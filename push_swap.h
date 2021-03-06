/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:10:45 by ojamil            #+#    #+#             */
/*   Updated: 2022/01/13 15:18:50 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_table
{
	int				key;
	struct s_table	*next;
	struct s_table	*prev;
	int				index;
	int				pos;
	int				index_in_your_table;
}	t_table;

typedef struct s_data
{
	t_table	*structs;
	t_table	*last;
	int		size;
}	t_data;

typedef struct s_string
{
	char	*str;
	char	**s;
	int		long_str;
	int		*arr;
}	t_string;

typedef struct s_comp_a
{
	t_table	*tba;
	t_table	*tbb;
	t_table	*last;
	t_table	*first;
}	t_comp_a;

typedef struct s_intger
{
	int	a;
	int	b;
}	t_intger;

void	pb(t_data *a, t_data *b);
void	pa(t_data *a, t_data *b);
void	sa(t_data *a);
void	sb(t_data *a);
void	ra(t_data *a);
void	rb(t_data *a);
void	rra(t_data *a);
void	rrb(t_data *a);
void	rrr(t_data *a, t_data *b);
t_table	*insertdata(int x, int index, int pos);
t_table	*ft_add_head(t_data *table, int x, int index, int pos);
t_table	*ft_add_back(t_data *table, int x, int index, int pos);
void	ss(t_data *a, t_data *b);
void	rr(t_data *a, t_data *b);
void	ft_print(t_data *data);
void	ft_delete_first_node(t_data *data);
void	ft_delete_back_node(t_data *data);
void	ft_print_reverse(t_data *data);
void	ft_print_reverse(t_data *data);
void	ft_delete_back_node(t_data *data);
char	*ft_strj(int size, char **strs, char *sep);
int		ft_strcmp(char *s1, char *s2);
void	ft_sort_int_tab(int *tab, int size);
int		ft_check_str(char *str);
void	ft_check_nember(char **str);
void	ft_check_double(char **s);
void	ft_free_list(t_data *dt);
void	ft_remplire_list(t_data *a, char **str, int *arr);
int		ft_markup_head(t_data *dt);
void	ft_remplir_index(t_data *dt, int *arr, int ac);
int		ft_markup(t_table *data, int x);
void	ft_marke(t_data *data, int x);
t_table	*ft_select_markup_head(t_table *data, int y);
void	ft_short_function(int *d, t_table *markup_head);
void	ft_free_str(char **str);
void	ft_check(t_data *a);
int		ft_nombre_push_b(t_data *b);
int		ft_sherch_markuphead_and_marque(t_data *a);
void	ft_sort_a(t_data *a, t_data *b);
int		ft_nombre_mots(char **str);
void	ft_push_b_to_a(t_data *a, t_data *b);
void	ft_chechk_sort_b(t_data *a, t_data *b, int *arr);
void	ft_index_tab(t_data *b);
void	ft_check_tab_int(int *arr, int size, t_data *a);
void	ft_organize_list(t_data *a, int pos);
void	ft_sort_final(t_data a, t_data b);
void	ft_complete_ft_markup(int *cmp, int *cp, t_table *data);
void	ft_chechk_sort_a(t_data *a, t_data *b, int *arr);
int		ft_table_final(int *comp1, int *comp, int *comp_final, int size);
void	ft_complete_ft_markup(int *cmp, int *cp, t_table *data);
void	ft_complete_table_final(int *comp1, int *comp, int *comp_final, int i);
void	ft_boucle_instriction2(t_intger *data, t_data *a, t_data *b);
void	ft_short_b_to_a2(t_intger *data, t_data *a, t_data *b);
void	ft_boucle_instriction1(t_intger *data, t_data *a, t_data *b);
void	ft_norm_check_sort_a1(t_comp_a *data, t_data *a, t_data *b, int *i);
void	ft_norm_check_sort_a2(t_comp_a *data, int *i);
int		ft_strlens(char *s);
char	*ft_strjoins(char *s1, char *s2);
char	*get_lines(int fd);
char	*get_next_lines(int fd);
#endif
