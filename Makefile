# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 15:34:59 by rel-isma          #+#    #+#              #
#    Updated: 2023/10/28 21:31:17 by rel-isma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
INC = cub3d.h
LINK =  -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror  -fsanitize=address -g
CC = cc

SRCS = src/main.c src/parsing.c src/pars_check_char.c src/pars_check_opext.c src/pars_check_texture.c \
	src/pars_check_wall.c src/pars_press_map.c src/pars_my_map.c src/render_player.c \
	src/ren_minimap.c src/ren_player_drow.c src/ren_player_keys.c src/ren_player_move.c \
	src/raycasting.c src/ray_render_hor.c src/ray_render_ver.c src/ray_distance.c src/needs2.c src/needs3.c\
	src/ray_utils.c src/utils_split.c src/utils_00.c src/utils_01.c  src/parse_textures.c src/needs_prase_doors.c \
	src/get_next_line/get_next_line.c src/get_next_line/get_next_line_utils.c src/needs_draw.c src/init_textures.c

OBJS = $(SRCS:%.c=obj/%.o)

all: $(NAME)

obj/%.o: %.c $(INC) | obj
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;36mCompiling $<\033[0m\n"

obj:
	@mkdir  -p obj/src obj/src/get_next_line

$(NAME): $(OBJS)
	@printf "\033[0;32mLinking...\033[0m\n"
	@$(CC) $(CFLAGS) $(LINK) $(OBJS) -o $(NAME)
	@printf "\033[0;32m$(NAME) compilation completed.\033[0m\n"

clean:
	@printf "\033[0;31mCleaning object files...\033[0m\n"
	@rm -rf obj
	@printf "\033[0;32mObject files cleaned.\033[0m\n"

fclean: clean
	@printf "\033[0;31mCleaning executable...\033[0m\n"
	@rm -f $(NAME)
	@printf "\033[0;32mExecutable cleaned.\033[0m\n"

re: fclean all

.PHONY: all clean fclean re 

push:
	git add .
	git commit -m "fix: doors finsh"
	git push
