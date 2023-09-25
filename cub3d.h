#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include <fcntl.h>
#include <math.h>
#include "get_next_line/get_next_line.h"

#define SZ 30

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_player
{
	double xInwindow;
	double yInwindow;
	double	turn_direction ; // (= 0) -1 if left, +1 if right
	double	walk_direction ; // (= 0) -1 if back, +1 if front
	double	rotationangle; //(= ) N ^, W <, E >, S.
	double	move_speed; //(3.0 speed of player in mini-map)
	double	rotation_speed; //(=3*(M_PI / 180))
}	t_player;

typedef struct s_cub
{
	int i;
	int j;
	int v;
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
	int up;
	int down;
	int right;
	int left;
	double x_new;
	double y_new;
    t_img img;
	t_player player;

}   t_cub;

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
void	initial_variable(t_cub *cub);


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

void 	own_mlx_pixel_put(t_cub *cub, int x, int y, int color);
void  	ft_put_color(t_cub *cub, int x, int y, int color);
int		render_minimap(t_cub *cub);
void	player_position(t_cub *cub);
void	render_player(t_cub *cub, int rayon);
int		keyMovePlayer(t_cub *cub, int code);
int		key_prs(int code, t_cub *cub);
int		key_releases(t_cub	*cub, int code);
int		myExit_prs(t_cub *cub);

#endif