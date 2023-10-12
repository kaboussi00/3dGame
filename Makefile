NAME = 	cub3d
INC = cubd.h
SRCS = main.c\
	parsing.c\
	pars_check_char.c\
	pars_check_opext.c\
	pars_check_texture.c\
	pars_check_wall.c\
	pars_press_map.c\
	pars_my_map.c\
	render_player.c\
	ren_minimap.c\
	ren_player_drow.c\
	ren_player_keys.c\
	ren_player_move.c\
	raycasting.c\
	ray_render_hor.c\
	ray_render_ver.c\
	ray_distance.c\
	ray_utils.c\
	utils_split.c\
	utils_00.c\
	utils_01.c\
	drawall.c\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

RM = rm -f

# MLX_DIR = minilibx-linux
MLX_DIR = minilibx_opengl

CFLAGS_LNX = -Wall -Wextra -Werror -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lm

# CFLAGS_LNX = -Wall -Wextra -Werror -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# -fsanitize=address -g

# $(CC) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(OBJ) -o $(NAME)

CC = cc

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(OBJS) $(CFLAGS_LNX) -o $(NAME)

%.o:%.c $(INC)
	$(CC) $(CFLAGS_LNX) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean:clean
	$(RM) $(NAME) $(NAME_B)

re: fclean all