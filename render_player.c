/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:29:10 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/12 20:49:29 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void fillWindow(t_cub *cub)
{
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            own_mlx_pixel_put(cub, x , y, 0x000000);
        }
    }
}



void drawWall(t_cub *cub)
{
    for (int x = 0; x < WIDTH; x++)
    {
        double alpha = normalizingAngle(cub->rayData[x].angle - cub->player.rotationangle);
        double distance = cub->rayData[x].dis_H < cub->rayData[x].dis_V ? cub->rayData[x].dis_H : cub->rayData[x].dis_V;
        double new_dis = distance * cos(alpha);
        double height = ((HEIGHT / new_dis) * SCALE);
        int start = (HEIGHT / 2) - (height / 2);
        int end = start + height;
         if (end > HEIGHT)
            end = HEIGHT;
        if (start < 0)
            start = 0;
        int wallColor = 0x9a7760;
        ///// draw floor and ceil////// 
        for (int y = end; y < HEIGHT; y++)
            own_mlx_pixel_put(cub, x, y, 0x85bb65);
        for (int y = 0; y <= start; y++)
            own_mlx_pixel_put(cub, x, y, 0x87CEEB);
        ///// draw wall
        for (int y = start; y < end; y++) {
            own_mlx_pixel_put(cub, x, y, wallColor);
        }
    }
}

int	render(t_cub *cub)
{
    fillWindow(cub);
	mlx_clear_window(cub->mlx, cub->mlx_window);
	CastRays(cub);
    drawWall(cub);
    // render_minimap(cub);
	// render_player(cub, SZ/4);
    mlx_put_image_to_window(cub->mlx, cub->mlx_window, cub->img.img, 0, 0);
	return(0);
}