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
    int o;
    int p;
    int line;
    int len;
    int fd;
    int space;
    int wall;
    char **all_map;
    char **text;
    char **map;
    char **copie_map;
    int no;
    int so;
    int we;
    int ea;
    int f;
    int c;
    int pos_i;
    int pos_j;

}   t_cub;

typedef struct s_data
{
	int		x;
	int		y;
}	t_data;

/////////////////
//...<utils>...//
/////////////////

void	printerror_message(char *str);
void	ft_putstr(char *s);
int     ft_strlen(char *str);
int     ft_atoi(char *str);
int	    ft_strcmp(const char *str1, const char *str2);
char	**ft_split(char const *s, char c);
int	    ft_str_line(char *str);
char	**ft_free(char **p);


/////////////////
//..<parsing>..//
/////////////////

void	check_extension(char *str);
void	check_opening(char *file);
void    count_map(t_cub *cub, char *file);
void    press_map(t_cub *cub, char *file);
void	check_duplicate(t_cub	*cub, char *str);
void	duplicate(t_cub	*cub);
void	check_color(char *str);
void	check_texture_color(t_cub *cub);
void    copy_map(t_cub *cub);
int	    charge_1(t_cub *cub, t_data p);
void	check_walls(t_cub *cub);
void	check_char(t_cub	*cub);
void	check_not_char(t_cub *cub);

#endif