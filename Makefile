CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
MLX_FLAGS	= -Lmlx -lmlx -framework OpenGL -framework Appkit

LIBFT_FLAGS	= -Llibft -lft
LIBFT_DIR	= ./libft
LIBFT_NAME	= libft.a

NAME		= miniRT

SRCS_DIR	= ./src

MAIN_SRC	= main.c \
			minirt.c

PARSING_DIR	= $(addprefix $(SRCS_DIR)/,parsing)
PARSING_SRC = ft_atof.c \
			ft_atoi2.c \
			is_comma.c \
			is_dot.c \
			is_double.c \
			parse_ambient.c \
			parse_camera.c \
			parse_color.c \
			parse_crd.c \
			parse_cylinder.c \
			parse_light.c \
			parse_nvec.c \
			parse_plain.c \
			parse_sphere.c \
			read_rt_file.c \
			split_size.c

PRINT_DIR	= $(addprefix $(SRCS_DIR)/,print)
PRINT_SRC	= print.c

SCENE_DIR	= $(addprefix $(SRCS_DIR)/,scene)
SCENE_SRC	= canvas.c \
			object_create.c \
			scene.c

TRACE_DIR	= $(addprefix $(SRCS_DIR)/,trace)

HIT_DIR		= $(addprefix $(TRACE_DIR)/,hit)
HIT_SRC		= hit_plain.c \
			hit_sphere.c \
			hit.c \
			normal.c

RAY_DIR		= $(addprefix $(TRACE_DIR)/,ray)
RAY_SRC		= phong_lighting.c \
			ray.c

UTILS_DIR	= $(addprefix $(SRCS_DIR)/,utils)
UTILS_SRC	= exit_err.c \
			ft_calloc2.c \
			ft_split2.c \
			object_utils.c \
			vec3_utils.c

SRCS		= $(addprefix $(SRCS_DIR)/,$(MAIN_SRC)) \
			$(addprefix $(PARSING_DIR)/,$(PARSING_SRC)) \
			$(addprefix $(PRINT_DIR)/,$(PRINT_SRC)) \
			$(addprefix $(SCENE_DIR)/,$(SCENE_SRC)) \
			$(addprefix $(HIT_DIR)/,$(HIT_SRC)) \
			$(addprefix $(RAY_DIR)/,$(RAY_SRC)) \
			$(addprefix $(UTILS_DIR)/,$(UTILS_SRC))
OBJS		= $(SRCS:.c=.o)

INCLUDE_DIR	= ./includes
INCLUDE_SRC	= minirt.h \
			parsing.h \
			print.h \
			scene.h \
			structures.h \
			trace.h \
			utils.h
INCLUDES = $(addprefix $(INCLUDE_DIR)/,$(INCLUDE_SRC))

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

$(OBJS): $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -I$(LIBFT_DIR) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	make fclean -sC $(LIBFT_DIR)
	rm -f $(OBJS) $(B_OBJS) LAST_ALL LAST_BONUS

fclean:
	make fclean -sC $(LIBFT_DIR)
	rm -f $(NAME) $(OBJS) $(B_OBJS) LAST_ALL LAST_BONUS

re: fclean all

.PHONY: all bonus clean fclean re
