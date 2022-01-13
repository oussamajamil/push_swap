NAME = push_swap
NAME_BONUS = checker_bonus

INCLUDE = so_long.h
LIBFT_BIB = ./libft/libft.a

CC = gcc

EXCUTE = main.c

EXCUTE_BONUS = ./bonus/checker.c

EXCUTE = push_swap.c

CFLAGS = -Wall -Wextra -Werror

INCLUDE = push_swap.h

SRC = 	swap_a.c\
	    swap_b.c\
		other_function1.c\
		other_function2.c\
		otherfunction3.c\
		other_function4.c\
		other_function5.c\
		ft_strj.c\
		swap_a_b.c\
		test.c\
		ft_norm_function1.c\
		ft_norm_function2.c\
		ft_norm_function3.c\
		ft_short_push_swap.c \
		./bonus/get_next_line.c

OBJECTS = $(SRC:.c=.o)

$(NAME) : $(OBJECTS) $(INCLUDE)
	@make clean -C libft
	@make -C libft
	@$(CC) $(CFLAGS) $(EXCUTE) $(OBJECTS) $(LIBFT_BIB) -o $@

all :$(NAME)

$(NAME_BONUS) : $(OBJECTS) $(INCLUDE)
	@make  clean -C libft
	@make  -C libft
	@$(CC) $(CFLAGS) $(EXCUTE_BONUS) $(OBJECTS) $(LIBFT_BIB) -o ./bonus/$@

bonus :$(NAME_BONUS)

%.o : %.c *.h
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo  "\033[0;40m compiler...."

clean :
	@make clean -C libft
	@rm -rf $(OBJECTS)

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME) 
	@rm -rf ./bonus/$(NAME_BONUS)

re : fclean all