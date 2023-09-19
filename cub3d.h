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
	int wall;
	char **all_map;
	char **text;
	char **map;
	char **copie;
	int no;
	int so;
	int we;
	int ea;
	int f;
	int c;
	int pos_i;
	int pos_j;
	void *mlx;
	void *mlx_window;

}   t_cub;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

/////////////////
//...<utils>...//
/////////////////


void	printerror_message(char *str);
void	ft_putstr(char *s);
int     ft_strlen(char *str);
int     ft_atoi(char *str);
int	    ft_strcmp(const char *str1, const char *str2);
char	*ft_strjoin(char *s1, char *s2);
int	    ft_str_line(char *str);
char	**ft_free(char **p);
char	**ft_split(char const *s, char c);


/////////////////
//..<parsing>..//
/////////////////


void    parse(t_cub *cub, char *file);
void	check_extension(char *str);
void	check_opening(char *file);
void    count_map(t_cub *cub, char *file);
void    press_map(t_cub *cub, char *file);
void	check_duplicate(t_cub	*cub, char *str);
void	duplicate(t_cub	*cub);
void	check_color(char *str);
void	check_texture_color(t_cub *cub);
void    new_map(t_cub *cub);
char	*charge_space(char c, int len);
void	check_char(t_cub	*cub);
void	check_not_char(t_cub *cub);
void    copie_with_spaces(t_cub *cub);
void	check_wall(t_cub *cub);

/////////////////
//....<mlx>....//
/////////////////

void own_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif