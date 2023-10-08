/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:25:50 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/08 14:43:26 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minilibx_opengl/mlx.h"
#include <fcntl.h>
#include <math.h>
#include "get_next_line/get_next_line.h"

#define SZ 30 
#define WIDTH 1000
#define HEIGHT 500
#define	STRIP_WIDTH 1
// #define	RAY_LENGTH 30
#define NUM_RAYS (WIDTH / STRIP_WIDTH) // number of rays to cast
#define FOV (60 * (M_PI / 180)) // filed of view angle in degress

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
	double 	xInwindow;
	double 	yInwindow;
	double	side_direction ; // (= 0) -1 if left, +1 if right
	double	turn_direction ; // (= 0) -1 if left, +1 if right
	double	walk_direction ; // (= 0) -1 if back, +1 if front
	double	rotationangle; //(= ) N ^, W <, E >, S.
	double	rayangle; //(= ) N ^, W <, E >, S.
	double	move_speed; //(3.0 speed of player in mini-map)
	double	rotation_speed; //(=3*(M_PI / 180))
	double	move_step;
	double	posXinmap;
	double	posYinmap;
}	t_player;

typedef struct s_ray
{
	double	x_hor;
	double	y_hor;
	double	angle;
	double	xIntercept_H;
	double	yIntercept_H;
	double	xIntercept_V;
	double	yIntercept_V;
	double	x_Step_H;
	double	y_Step_H;
	double	x_Step_V;
	double	y_Step_V;
	double	x_Wallhit;
	double	y_Wallhit;
	double	distance;
	double	rayUp;
	double	rayDown;
	double	rayLeft;
	double	rayRight;
	
}	t_ray;

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
	t_ray	*rayData;

}   t_cub;

/////////////////
//...<Utils>...//
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
//..<Parsing>..//
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
//<RenderM_map>//
/////////////////

void 	own_mlx_pixel_put(t_cub *cub, int x, int y, int color);
void  	ft_put_color(t_cub *cub, int x, int y, int color);
int		render_minimap(t_cub *cub);

//////////////////
//<RenderPlayer>//
//////////////////

void	render_player(t_cub *cub, int rayon);
void	player_position(t_cub *cub);
void	drowLine(t_cub *cub);
int		myExit_prs(t_cub *cub);
int		keyReleases(int code, t_cub *cub);
int		keyPress(int code, t_cub *cub);
double 	rotationAngle(t_cub *cub);
void	moveWalkPlayer(t_cub *cub);
void	moveSidePlayer(t_cub *cub);
int		render(t_cub *cub);

//////////////////
//.<Raycasting.>//
//////////////////

void CastRays(t_cub *cub);
#endif