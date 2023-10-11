/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:29:10 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/11 23:27:18 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void fillWindow(t_cub *cub) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            own_mlx_pixel_put(cub, x , y, 0xFFFFFF);
        }
    }
}

void    drawWall(t_cub *cub) {

//                          Actual Slice Height
//  Projected Slice Height= --------------------- * Distance to Projection Plane
//                          Distance to the Slice

    for (int x = 0; x < WIDTH; x++) {
        int distance = cub->rayData[x].dis_H < cub->rayData[x].dis_V ? cub->rayData[x].dis_H : cub->rayData[x].dis_V;
        int height = (HEIGHT / distance) * SCALE;
        int start = (HEIGHT / 2) - (height / 2);
        for (int y = 0; y < height; y++) {
            own_mlx_pixel_put(cub, x , y + start, 0xf5756c);
        }
    }
}

int	render(t_cub *cub)
{
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            own_mlx_pixel_put(cub, x , y , 0x000000);
        }
    }
	mlx_clear_window(cub->mlx, cub->mlx_window);
	
    // draw minimap
    // render_minimap(cub);
	// render_player(cub, SZ/4);
	CastRays(cub);

    drawWall(cub);

    mlx_put_image_to_window(cub->mlx, cub->mlx_window, cub->img.img, 0, 0);
	return(0);
}