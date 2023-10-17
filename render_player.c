/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:29:10 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/17 10:43:29 by rel-isma         ###   ########.fr       */
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
        double distance;
        int textureIndex = 0;

        // Determine whether the ray hit a vertical or horizontal wall
        if (cub->rayData[x].dis_H < cub->rayData[x].dis_V) {
             distance = cub->rayData[x].dis_H;
             cub->rayData[x].vertical = 0;
            //  textureIndex = cub->rayData[x].rayRight ? 1 : 3; // Texture index for horizontal wall
        } else {
            distance = cub->rayData[x].dis_V;
            cub->rayData[x].vertical = 1;
            // textureIndex = cub->rayData[x].rayUp ? 2 : 0; // Texture index for vertical wall
        }

        // Calculate projected wall height
        double new_dis = distance * cos(alpha);
        double height = (HEIGHT / new_dis) * SCALE;
        int start = (HEIGHT / 2) - (height / 2);
        int end = start + height;

        // Ensure the start and end points are within screen bounds
        if (end > HEIGHT) end = HEIGHT;
        if (start < 0) start = 0;

        // Draw floor and ceiling
        for (int y = end; y < HEIGHT; y++)
            own_mlx_pixel_put(cub, x, y, 0x85bb65);
        for (int y = 0; y <= start; y++)
            own_mlx_pixel_put(cub, x, y, 0x87CEEB);

        // Draw wall texture
        double textureStep = 64.0 / height; // the steps bach ktloopi (heitght = 256 ==> step = 0.25 ==> )
        double texturePos = 0;

        for (int y = start; y < end; y++)
        {
            // int texY = (int)texturePos;
            
            // Get the texture color based on texture index and texture coordinates
            unsigned int color;
            if (cub->rayData[x].vertical) {
                int texX = (int)cub->rayData[x].y_ver % 64;
                color = cub->east_table[(int)(texturePos) * 64 + texX];
            } else {
                int texX = (int)cub->rayData[x].x_hor % 64;
                color = cub->east_table[(int)(texturePos) * 64 + texX];
            }
            texturePos += textureStep;

            own_mlx_pixel_put(cub, x, y, color);
        }
    }
}

// void drawWall(t_cub *cub)
// {
//     double  xoffset;

//     for (int x = 0; x < WIDTH; x++)
//     {
//         double alpha = normalizingAngle(cub->rayData[x].angle - cub->player.rotationangle);
//         double distance;
//         if (cub->rayData[x].dis_H < cub->rayData[x].dis_V) {
//              distance = cub->rayData[x].dis_H;
//              cub->rayData[x].vertical = 0;
//         }
//         else
//         {
//             distance = cub->rayData[x].dis_H;
//             cub->rayData[x].vertical = 1;
//         }
//         distance = cub->rayData[x].dis_H < cub->rayData[x].dis_V ? cub->rayData[x].dis_H : cub->rayData[x].dis_V;

//         double new_dis = distance * cos(alpha);
//         double height = ((HEIGHT / new_dis) * SCALE);
//         int start = (HEIGHT / 2) - (height / 2);
//         int end = start + height;
//         if (end > HEIGHT)
//             end = HEIGHT;
//         if (start < 0)
//             start = 0;

//         // draw floor and ceiling
//         for (int y = end; y < HEIGHT; y++)
//             own_mlx_pixel_put(cub, x, y, 0x85bb65);
//         for (int y = 0; y <= start; y++)
//             own_mlx_pixel_put(cub, x, y, 0x87CEEB);

//         // draw wall with texture
//         int index = 0;

//         if (cub->rayData[x].vertical)
//             xoffset = fmod(cub->rayData[x].y_ver, 64) + 0.01; // Add a small offset
//         else
//             xoffset = fmod(cub->rayData[x].x_hor, 64) + 0.01; // Add a small offset

//         for (int y = start; y < end; y++)
//         {
//             double yoffset = (y / height) * 64;
//             own_mlx_pixel_put(cub, x, y, (cub->east_table)[(int)(yoffset + xoffset)]);
//         }
//     }
// }


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