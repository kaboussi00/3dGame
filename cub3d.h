/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:49:00 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/16 15:01:11 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

}   t_cub;

/////////////////
//...<utils>...//
/////////////////

void	printerror_message(char *str);
void	ft_putstr(char *s);
int     ft_strlen(char *str);
int     ft_atoi(char *str);
int	    ft_strcmp(const char *str1, const char *str2);
char	**ft_split(char const *s, char c);
int	    ft_str_line(const char *str);


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

#endif