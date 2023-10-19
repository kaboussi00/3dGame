/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:29:10 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/19 16:53:59 by rel-isma         ###   ########.fr       */
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

unsigned int *get_table(t_cub *cub, int x)
{
    if (cub->rayData[x].vertical == 1 && cub->rayData[x].rayRight)
        return cub->east_table;
    else if (cub->rayData[x].vertical == 1 && cub->rayData[x].rayLeft)
        return cub->west_table;
    else if (cub->rayData[x].vertical == 0 && cub->rayData[x].rayUp)
        return cub->north_table;
    else 
        return cub->south_table;
}


double hitVer(t_ray *ray) {
    double distance;
    if (ray->dis_H < ray->dis_V) {
         distance = ray->dis_H;
         ray->vertical = 0;
    } else {
        distance = ray->dis_V;
        ray->vertical = 1;
    }
    return distance;
}

void drawWall(t_cub *cub)
{

    for (int x = 0; x < WIDTH; x++)
    {
        double alpha = normalizingAngle(cub->rayData[x].angle - cub->player.rotationangle);
        double distance;
        int textureIndex = 0;

        // Determine whether the ray hit a vertical or horizontal wall
        distance = hitVer(&cub->rayData[x]);

        // Calculate projected wall height
        double new_dis = distance * cos(alpha);
        double height = (500 / new_dis) * 100;
        int start = (HEIGHT / 2) - (height / 2);
        int end = start + height;
        // printf("height == %f\n", height);

        // Ensure the start and end points are within screen bounds
        if (end > HEIGHT) end = HEIGHT;
        if (start < 0) start = 0;

        // Draw floor and ceiling
        for (int y = end; y < HEIGHT; y++)
            own_mlx_pixel_put(cub, x, y, 0x696969);
        for (int y = 0; y <= start; y++)
            own_mlx_pixel_put(cub, x, y, 0x87CEEB);

        // Draw wall texture
        double texX;
        double textureStep = (float)cub->north_img.height / height;
        double texturePos = (start - (HEIGHT / 2) + (height / 2)) * textureStep;
        unsigned int *table = get_table(cub, x);
        if (!table)
        {
            printerror_message("table :: empty\n");
            exit(1);
        }
        if (cub->rayData[x].vertical)
            texX = fmod(cub->rayData[x].y_ver , 64);
        else
            texX = fmod(cub->rayData[x].x_hor , 64);
        for (int y = start; y < end; y++)
        {
            // Get the texture color based on texture index and texture coordinates
            int h = ((int)texturePos * cub->north_img.height) + (texX * (cub->north_img.width / 64));
            texturePos += textureStep;
            own_mlx_pixel_put(cub, x, y, table[h]);
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