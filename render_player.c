/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:29:10 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/25 19:15:49 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void player_position(t_cub *cub)
{
    // position in window
    cub->player.xInwindow = cub->pos_i * SZ + (SZ / 2);
    cub->player.yInwindow = cub->pos_j * SZ + (SZ / 2);
}

void	drowLine(t_cub *cub)
{
	double x0;
	double y0;
	double x1;
	double y1;
	double inx;
	double iny;
	int step;

	x0 = cub->player.xInwindow;
	y0 = cub->player.yInwindow;
    x1 = x0 + cos(cub->player.rotationangle) * 50;
    y1 = y0 + sin(cub->player.rotationangle) * 50;
    double i = 0;
    double j = 0;
	int x = x1 - x0;
	int y = y1 - y0;
	if (abs(x) > abs(y))
        step = abs(x);
    else
        step = abs(y);
	inx = x / step;
	iny = y / step;
	cub->v = 0; 
	while (cub->v < step)
	{
		own_mlx_pixel_put(cub, round(y0) , round(x0), 0xf5756c);
		x0 += inx;
		y0 += iny;
		cub->v++;
	}
}

void render_player(t_cub *cub, int rayon)
{
    double  i;
    double  degr;
    double  new_y;
    double  new_x;

    i = 0;
    while(i < rayon)
    {
        degr = 0;
        while(degr < 360)
        {
            new_x = i * cos(degr * M_PI / 180);
            new_y = i * sin(degr * M_PI / 180);
            own_mlx_pixel_put(cub, cub->player.yInwindow + new_y, cub->player.xInwindow + new_x, 0xfafafa);
            degr++;
        }
        i++;
    }
	drowLine(cub);
}


// void movePlayer(t_cub *cub)
// {
//     cub->player.rotationangle = M_PI / 2;
//     cub->player.rotation_speed = 2 * (M_PI / 180);
//     cub->player.move_speed = 3.0;
//     cub->player.rotationangle += cub->player.turn_direction * cub->player.rotation_speed;
// }