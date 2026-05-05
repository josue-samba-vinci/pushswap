NAME		:= push_swap

PRINTF_DIR  := src/utils/printf
PRINTF_LIB  := $(PRINTF_DIR)/libftprintf.a

SRCS		:=	src/main.c \
				src/parser.c \
				src/flags.c \
				src/compute_disorder.c \
				src/operations/push.c \
				src/operations/reverse_rotate_a_b.c \
				src/operations/reverse_rotate.c \
				src/operations/rotate_a_b.c \
				src/operations/rotate.c \
				src/operations/swap_a_b.c \
				src/operations/swap.c \
				src/sorting/simple_sort.c \
				src/sorting/medium_sort.c \
				src/sorting/complex_sort.c \
				src/utils/ft_atoi.c \
				src/utils/ft_isdigit.c \
				src/utils/ft_lstadd_back.c \
				src/utils/ft_lstlast.c \
				src/utils/ft_lstnew.c \
				src/utils/ft_split.c \
				src/utils/stack_size.c \
				src/utils/ft_strncmp.c \
				src/utils/ft_memset.c \


OBJ			:= $(SRCS:.c=.o)
CFLAGS		:= -Wall -Wextra -Werror -I include

all: $(PRINTF_LIB) $(NAME)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

$(OBJ): %.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(PRINTF_LIB) -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C $(PRINTF_DIR) clean

fclean:
	rm -f $(OBJ) $(NAME)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
