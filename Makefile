NAME =  cub3d
SRCS = main.c draw_map.c utils.c key_hooks.c
CC = cc -Wall -Wextra -Werror -fsanitize=address
OBJS = ${SRCS:%.c=%.o}
libs = /Users/hlahwaou/Desktop/MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/hlahwaou/Desktop/homebrew/Cellar/glfw/3.3.8/lib/"
Headers = -I /Users/hlahwaou/Desktop/MLX42/include

all : $(NAME)
$(NAME) : $(OBJS) cub3d.h
	$(CC) $(OBJS) $(libs) libft/libft.a  -o $(NAME)
%.o : %.c cub3d.h
	$(CC) $< -c -o $@ $(Headers)
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean $(NAME)