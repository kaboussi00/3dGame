/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ren_player_drow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:52:09 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/12 20:49:23 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void player_position(t_cub *cub)
{
	// position in window
	cub->player.xInwindow = cub->pos_i * SZ + (SZ / 2);
	cub->player.yInwindow = cub->pos_j * SZ + (SZ / 2);
}

void render_player(t_cub *cub, int rayon)
{
	// drow circle
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
}

void	drowLine(t_cub *cub)
{
	//drow line
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
	double x = x1 - x0;
	double y = y1 - y0;
	if (fabs(x) > fabs(y))
		step = fabs(x);
	else
		step = fabs(y);
	inx = x / step;
	iny = y / step;
	cub->v = 0; 
	while (cub->v < step)
	{
		own_mlx_pixel_put(cub, (int)round(y0) , (int)round(x0), 0xf5756c);
		x0 += inx;
		y0 += iny;
		cub->v++;
	}
}