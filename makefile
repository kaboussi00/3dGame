NAME = 	cub3d
INC = cubd.h
SRCS = parsing.c\
	main.c\
	split.c\
	utils00.c\
	utils01.c\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\
	my_map.c\
	check_op_ext.c\
	check_texture.c\
	press_map.c\
	check_char.c\
	check_wall.c\


OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

RM = rm -f

CFLAGS = -Wall -Wextra -Werror 
# -fsanitize=address -g

CC = cc

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c $(INC)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean:clean
	$(RM) $(NAME) $(NAME_B)

re: fclean all