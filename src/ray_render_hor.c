/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render_hor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:38:53 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/30 10:07:10 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	convert_into_map_h(t_ray *ray_data, t_cub *cub)
{
	double	y;

	while (ray_data->x_hor >= 0 && ray_data->x_hor <= (cub->line - 6) * SZ
		&& ray_data->y_hor >= 0 && ray_data->y_hor <= cub->len * SZ)
	{
		y = ray_data->y_hor;
		if (ray_data->ray_up)
			y = ray_data->y_hor - 1;
		if (cub->map[(int)(ray_data->x_hor / SZ)][(int)(y / SZ)] == 'D')
			ray_data->flags_hor = 1;
		else if (cub->map[(int)(ray_data->x_hor / SZ)][(int)(y / SZ)] == 'C')
			ray_data->flags_hor = 1;
		else
			ray_data->flags_hor = 0;
		if (cub->map[(int)(ray_data->x_hor / SZ)][(int)(y / SZ)] != '1'
			&& cub->map[(int)(ray_data->x_hor / SZ)][(int)(y / SZ)] != ' '
			&& cub->map[(int)(ray_data->x_hor / SZ)][(int)(y / SZ)] != 'D')
		{
			ray_data->x_hor += ray_data->x_step_h;
			ray_data->y_hor += ray_data->y_step_h;
		}
		else
			break ;
	}
}

void	check_wall__hor(t_ray *ray_data, t_cub *cub)
{
	ray_data->x_hor = cub->player.x_inwindow;
	ray_data->y_hor = cub->player.y_inwindow;
	ray_data->y_intercept_h = floor(ray_data->y_hor / SZ) * SZ;
	if (ray_data->ray_down)
		ray_data->y_intercept_h += SZ;
	ray_data->x_intercept_h = ray_data->x_hor + ((ray_data->y_intercept_h
				- ray_data->y_hor) / tan(ray_data->angle));
	ray_data->y_step_h = SZ;
	if (ray_data->ray_up)
		ray_data->y_step_h *= -1;
	ray_data->x_step_h = SZ / tan(ray_data->angle);
	if ((ray_data->ray_left && ray_data->x_step_h > 0) || (ray_data->ray_right
			&& ray_data->x_step_h < 0))
		ray_data->x_step_h *= -1;
	ray_data->x_hor = ray_data->x_intercept_h;
	ray_data->y_hor = ray_data->y_intercept_h;
	convert_into_map_h(ray_data, cub);
}
