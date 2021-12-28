#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include <stdio.h>

typedef struct s_table
{
	int key;
	struct s_table *next;
	struct s_table *prev;
} t_table;

typedef struct s_data
{
	t_table *structs;
	t_table *last;
	int size;
}t_data;
#endif