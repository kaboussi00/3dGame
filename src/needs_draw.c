/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needs_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:35:34 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/21 22:03:40 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int	*get_table(t_cub *cub, int x)
{
	if (cub->rayData[x].vertical == 1 && cub->rayData[x].rayRight)
		return (cub->east_table);
	else if (cub->rayData[x].vertical == 1 && cub->rayData[x].rayLeft)
		return (cub->west_table);
	else if (cub->rayData[x].vertical == 0 && cub->rayData[x].rayUp)
		return (cub->north_table);
	else
		return (cub->south_table);
}

double	hitVer(t_ray *ray)
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

void	draw_wall_with_textures(t_cub *cub, int start, int end, double height,
		int x)
{
	double texX;
	double textureStep = (float)cub->north_img.height / height;
	double texturePos = (start - (HEIGHT / 2) + (height / 2)) * textureStep;
	unsigned int *table = get_table(cub, x);
	if (cub->rayData[x].vertical)
		texX = fmod(cub->rayData[x].y_ver, 64);
	else
		texX = fmod(cub->rayData[x].x_hor, 64);
	for (int y = start; y < end; y++)
	{
		// Get the texture color based on texture index and texture coordinates
		int h = ((int)texturePos * cub->north_img.height) + (texX
			* (cub->north_img.width / 64));
		texturePos += textureStep;
		own_mlx_pixel_put(cub, x, y, table[h]);
	}
}