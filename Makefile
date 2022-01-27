NAME	=	cub3D
RM		=	rm -f
SRCS	=	src/validations/verify_args.c \
			src/validations/verify_map.c \
			src/validations/verify_textures.c\
			src/validations/verify_colors.c \
			src/validations/set_map.c \
			src/validations/verify_char.c \
			src/errors/error_message_handler.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			src/key_manager.c src/free.c \
			src/draw.c src/cub3d.c src/raycasting.c \
			src/image.c src/close.c src/camera.c \
			src/free_array.c
OBJS	=	$(SRCS:.c=.o)
ARGS	=	-Wall -Wextra -Werror
all		:	$(NAME)

$(NAME)	:	$(OBJS)
	make -C ./libft
	make -C ./minilibx
	gcc $(OBJS) -L./libft -L./minilibx/ -lmlx -lXext -lX11 -lm -lbsd ./minilibx/libmlx_Linux.a ./libft/libft.a -o $(NAME) $(ARGS)

clean	:
	make clean -C ./libft
	make clean -C ./minilibx
	rm -f $(OBJS)

fclean:	clean
	make fclean -C ./libft
	$(RM) $(NAME)

re	: clean all
