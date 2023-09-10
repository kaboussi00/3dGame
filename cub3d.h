#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include <fcntl.h>
#include <math.h>
#include "get_next_line/get_next_line.h"

typedef struct s_cub
{
    int i;
    int j;
    int line;
    int len;
    int fd;
    char **map;
    char **text;
    int no;
    int so;
    int we;
    int ea;
    int f;
    int c;

}   t_cub;

char	**ft_split(char const *s, char c);
void	check_extension(char *str);
void	printerror_message(char *str);
void	ft_putstr(char *s);

#endif