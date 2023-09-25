/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:29:10 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/25 17:47:24 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void player_position(t_cub *cub)
{
    // position in window
    cub->player.xInwindow = cub->pos_i * SZ + (SZ / 2);
    cub->player.xInwindow = cub->pos_i * SZ + (SZ / 2);
}

// void drow_line(t_cub *cub)
// {
	// puts("s");
	// cub->i = cub->pos_i;
	// cub->j = cub->pos_j;
	// cub->x = cub->x + cos(cub->player.rotationangle) * 30;
    // cub->y = cub->y + sin(cub->player.rotationangle) * 30;
// }


// extern double round(double n)
// {
// 	//
// 	if (n - n < 0,5)
// 		return (n);
// 	return (n+1);
// }

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
    //
    x1 = x0 + cos(cub->player.rotationangle) * 30;
    y1 = y0 + sin(cub->player.rotationangle) * 30;
    // printf("{after ; p_i ; %d p_j ; %d}\n", cub->pos_i,cub->pos_j );
    double i = 0;
    double j = 0;
	int x = x1 - x0;
	int y = y1 - y0;
    printf("{//// ; i ; %d j ; %d}\n", cub->i,cub->j );
    //
	if (abs(x) > abs(y))
        step = abs(x);
    else
        step = abs(y);
    //
	inx = x / step;
	iny = y / step;
    //
	cub->v = 0; 
	while (cub->v < step)
	{
        // puts("here1");
		own_mlx_pixel_put(cub, round(x0) , round(y0), 0xf5756c);
        // puts("here2");
		// cub->player.xInwindow += inx;
		// cub->player.yInwindow += iny;
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
            own_mlx_pixel_put(cub, cub->pos_j + new_y, cub->pos_i + new_x, 0xf5756c);
            degr++;
        }
        i++;
    }
    puts("111111111");
	drowLine(cub);
}
