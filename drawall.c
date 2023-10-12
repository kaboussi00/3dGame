/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:06:07 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/12 12:30:27 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void drawceil(t_cub *cub)
{
    int skyColor = 0x87CEEB; 
        for (int x = 0; x < WIDTH; x++)
        {
         for (int y = 0; y < HEIGHT / 2; y++)
         {
            own_mlx_pixel_put(cub, x, y, skyColor);
         }
     }
}

void drawfloor(t_cub *cub)
{
    int earthcolor = 0x81ff76;

    for (int x = 0; x < WIDTH; x++)
    {
         for (int y = HEIGHT / 2; y < HEIGHT; y++)
        {
            own_mlx_pixel_put(cub, x, y, earthcolor);
        }
    }
}