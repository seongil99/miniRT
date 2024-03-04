CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -Lmlx -lmlx -framework OpenGL -framework Appkit
LIBFT_FLAGS	= -Llibft -lft

NAME		= miniRT

SRCS		= main.c \

OBJS		= $(SRCS:.c=.o)

B_SRCS		= main_bonus.c \

B_OBJS		= $(B_SRCS:.c=.o)

LIBFT_DIR	= ./libft
LIBFT_NAME	= libft.a

all: $(NAME)
$(NAME): LAST_ALL
bonus: LAST_BONUS

LAST_ALL: $(OBJS)
	rm -f LAST_BONUS
	make all -sC $(LIBFT_DIR)
	$(CC) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -lm -o $(NAME)
	touch $@

LAST_BONUS: $(B_OBJS)
	rm -f LAST_ALL
	make all -sC $(LIBFT_DIR)
	$(CC) $(B_OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -lm -o $(NAME)
	touch $@

$(OBJS): minirt.h
$(B_OBJS): minirt_bonus.h

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -Ilibft -I. -c $< -o $@

clean:
	make fclean -sC $(LIBFT_DIR)
	rm -f $(OBJS) $(B_OBJS) LAST_ALL LAST_BONUS

fclean:
	make fclean -sC $(LIBFT_DIR)
	rm -f $(NAME) $(OBJS) $(B_OBJS) LAST_ALL LAST_BONUS

re: fclean all

.PHONY: all bonus clean fclean re
