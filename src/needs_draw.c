/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needs_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:35:34 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/27 00:29:28 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int	*get_table(t_cub *cub, int x)
{
	if (cub->ray_data[x].vertical == 1 && cub->ray_data[x].rayRight)
		return (cub->east_table);
	else if (cub->ray_data[x].vertical == 1 && cub->ray_data[x].rayLeft)
		return (cub->west_table);
	else if (cub->ray_data[x].vertical == 0 && cub->ray_data[x].rayUp)
		return (cub->north_table);
	else
		return (cub->south_table);
}

double	hit_ver(t_ray *ray)
{
	double	distance;

	if (ray->dis_H < ray->dis_V)
	{
		distance = ray->dis_H;
		ray->vertical = 0;
	}
	else
	{
		distance = ray->dis_V;
		ray->vertical = 1;
	}
	return (distance);
}

void	draw_floor_ceiling(t_cub *cub, int start, int end, int x)
{
	int	y;

	y = 0;
	while (y <= start)
	{
		own_mlx_pixel_put(cub, x, y, cub->color_ceiling);
		y++;
	}
	y = end;
	while (y < HEIGHT)
	{
		own_mlx_pixel_put(cub, x, y, cub->color_floor);
		y++;
	}
}


int check_door(t_cub *cub, int x, int y)
{
    double dist;
    if (x >= 0 && x < cub->line - 6 && y >= 0 && y < cub->len - 1)
    {
        if (cub->map[x][y] == 'D')
        {
            dist = distance(cub->player.posXinmap, cub->player.posYinmap, x * SZ, y * SZ);
            // printf("%f\n", dist);
            if (dist <= CLOSE_DISTANCE_THRESHOLD)
            {
                cub->map[x][y] = 'C';
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;
}



void draw_wall_with_textures(t_cub *cub, double height, int x)
{
    int y;
    int h;
    double tex_x;
    double texture_step;
    double texture_pos;

    // Calculate texture coordinates based on ray intersection
    if (cub->ray_data[x].vertical)
        tex_x = fmod(cub->ray_data[x].y_ver, cub->north_img.height);
    else
        tex_x = fmod(cub->ray_data[x].x_hor, cub->north_img.height);

    // Check if the ray intersects with a door on both sides
    int door1 = check_door(cub, (int)(cub->ray_data[x].x_hor / SZ), (int)(cub->ray_data[x].y_hor / SZ));
    int door2 = check_door(cub, (int)((cub->ray_data[x].x_hor - 1) / SZ), (int)(cub->ray_data[x].y_hor / SZ));

    // Prioritize rendering the door over the wall
    if (door1 && door2) {
        cub->table = cub->door_closed_texture;
    } else if (door1) {
        cub->table = cub->door_closed_texture;
    } else if (door2) {
        cub->table = cub->door_closed_texture;
    } else {
        cub->table = get_table(cub, x);
    }

    // Calculate texture mapping step and initial position
    texture_step = (double)cub->north_img.height / height;
    texture_pos = ((cub->start - (HEIGHT / 2) + (height / 2)) * texture_step);

    // Clamp texture_pos to valid range [0, cub->north_img.height - 1]
    texture_pos = fmin(fmax(texture_pos, 0), cub->north_img.height - 1);

    // Loop through the wall slice and draw pixels with textures
    y = cub->start;
    while (y < cub->end)
    {
        // Calculate texture index based on texture_pos and tex_x
        h = ((int)texture_pos % cub->north_img.height) * cub->north_img.width + (int)tex_x;

        // Draw the pixel with the corresponding texture color
        own_mlx_pixel_put(cub, x, y, cub->table[h]);

        // Update texture_pos for the next pixel in the wall slice
        texture_pos += texture_step;
        y++;
    }
}


