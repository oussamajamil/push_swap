NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT_BIB = ./libft/libft.a

INCLUDE = push_swap.h

RM = rm -rf

all :
	@make clean -C libft
	@make -C libft
	@$(CC) $(CFLAGS) push_swap.c $(LIBFT_BIB) -o aaa

clean:
	@make clean -C libft

fclean:
	@make fclean -C libft
	@$(RM) ./aaa
