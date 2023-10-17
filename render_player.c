/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:29:10 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/17 19:38:25 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int player_is_in_north(double rotationangle)
{
    if (rotationangle >= 3 * M_PI / 2 || rotationangle < M_PI / 4)
        return 1;
    return 0;
}

int player_is_in_south(double rotationangle)
{
    if (rotationangle >= 135 && rotationangle < 225)
        return 1;
    return 0;
}

int player_is_in_west(double rotationangle)
{
    if (rotationangle >= 225 && rotationangle < 315)
        return 1;
    return 0;
}

int player_is_in_east(double rotationangle)
{
    if (rotationangle >= 45 && rotationangle < 135)
        return 1;
    return 0;
}

void init_textures(t_cub *cub)
{
    cub->east_table = NULL;
    cub->north_img.img = mlx_xpm_file_to_image(cub->mlx, cub->north_texture_path, &cub->north_img.width, &cub->north_img.height);
    if (cub->north_img.img == NULL)
        printerror_message("Failed to load texture!\n");//TODO: exit if a texture not found
    cub->north_img.addr = mlx_get_data_addr(cub->north_img.img, &cub->north_img.bits_per_pixel, &cub->north_img.line_length, &cub->north_img.endian);
    cub->north_table = (unsigned int *)cub->north_img.addr;
    cub->south_img.img = mlx_xpm_file_to_image(cub->mlx, cub->south_texture_path, &cub->south_img.width, &cub->south_img.height);
    if (cub->south_img.img == NULL)
        printerror_message("Failed to load texture!\n");
    cub->south_img.addr = mlx_get_data_addr(cub->south_img.img, &cub->south_img.bits_per_pixel, &cub->south_img.line_length, &cub->south_img.endian);
    cub->south_table = (unsigned int *)cub->south_img.addr;
    cub->west_img.img = mlx_xpm_file_to_image(cub->mlx, cub->west_texture_path, &cub->west_img.width, &cub->west_img.height);
    if (cub->west_img.img == NULL)
        printerror_message("Failed to load texture!\n");
    cub->west_img.addr = mlx_get_data_addr(cub->west_img.img, &cub->west_img.bits_per_pixel, &cub->west_img.line_length, &cub->west_img.endian);
    cub->west_table = (unsigned int *)cub->west_img.addr;
    cub->east_img.img = mlx_xpm_file_to_image(cub->mlx, cub->east_texture_path, &cub->east_img.width, &cub->east_img.height);
    if (cub->east_img.img == NULL)
        printerror_message("Failed to load texture!\n");
    cub->east_img.addr = mlx_get_data_addr(cub->east_img.img, &cub->east_img.bits_per_pixel, &cub->east_img.line_length, &cub->east_img.endian);
    cub->east_table = (unsigned int *)cub->east_img.addr;
 
    
}



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
    printf("%d\n\n", cub->rayData[x].vertical);
    if (!(cub->rayData[x].dis_H < cub->rayData[x].dis_V) && cub->rayData[x].rayRight)
        return cub->east_table;
    else if (!(cub->rayData[x].dis_H < cub->rayData[x].dis_V) && cub->rayData[x].rayLeft)
        return cub->west_table;
    else if ((cub->rayData[x].dis_H < cub->rayData[x].dis_V) && cub->rayData[x].rayUp)
    {
        puts("rayUp\n\n");
        return cub->north_table;
    }
    else if ((cub->rayData[x].dis_H < cub->rayData[x].dis_V) && cub->rayData[x].rayDown)
    {
        puts("rayUp\n\n");
        return cub->south_table;

    }
    else
    {
        printerror_message("error get_table\n");
        return (NULL);
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
        } else {
            distance = cub->rayData[x].dis_V;
            cub->rayData[x].vertical = 1;
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
        double textureStep = 64 / height;
        double texturePos = (start - (HEIGHT / 2) + (height / 2)) * textureStep;
        unsigned int *table = get_table(cub, x);
        for (int y = start; y < end; y++)
        {
            // Get the texture color based on texture index and texture coordinates
            unsigned int color;
            if (cub->rayData[x].vertical)
            {
                int texX = (int)cub->rayData[x].y_ver % 64;
                color = table[(int)(texturePos) * 64 + texX];
            } 
            else
            {
                int texX = (int)cub->rayData[x].x_hor % 64;
                color = table[(int)(texturePos) * 64 + texX];
            }
            texturePos += textureStep;
            own_mlx_pixel_put(cub, x, y, color);
        }
    }
}


int	render(t_cub *cub)
{
    fillWindow(cub);
	mlx_clear_window(cub->mlx, cub->mlx_window);
	CastRays(cub);
    init_textures(cub);
    drawWall(cub);
    // render_minimap(cub);
	// render_player(cub, SZ/4);
    mlx_put_image_to_window(cub->mlx, cub->mlx_window, cub->img.img, 0, 0);
    return(0);
}