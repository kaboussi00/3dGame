/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render_ver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:15:30 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/29 12:38:37 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	convert_into_map_v(t_ray *ray_data, t_cub *cub)
{
	double	x;

	while (ray_data->x_ver >= 0 && ray_data->x_ver <= (cub->line - 6) * SZ
		&& ray_data->y_ver >= 0 && ray_data->y_ver <= cub->len * SZ)
	{
		x = ray_data->x_ver;
		if (ray_data->ray_left)
			x--;
		if (cub->map[(int)(x / SZ)][(int)((ray_data->y_ver / SZ))] == 'C')
			ray_data->flags_ver = 1;
		else if (cub->map[(int)(x / SZ)][(int)((ray_data->y_ver / SZ))] == 'D')
			ray_data->flags_ver = 1;
		else
			ray_data->flags_ver = 0;
		if (cub->map[(int)(x / SZ)][(int)(ray_data->y_ver / SZ)] != '1'
			&& cub->map[(int)(x / SZ)][(int)(ray_data->y_ver / SZ)] != ' '
			&& cub->map[(int)(x / SZ)][(int)(ray_data->y_ver / SZ)] != 'D')
		{
			ray_data->x_ver += ray_data->x_step_v;
			ray_data->y_ver += ray_data->y_step_v;
		}
		else
			break ;
	}
}

void	check_wall__ver(t_ray *ray_data, t_cub *cub)
{
	ray_data->x_ver = cub->player.x_inwindow;
	ray_data->y_ver = cub->player.y_inwindow;
	ray_data->x_intercept_v = floor(ray_data->x_ver / SZ) * SZ;
	if (ray_data->ray_right)
		ray_data->x_intercept_v += SZ;
	ray_data->y_intercept_v = ray_data->y_ver + ((ray_data->x_intercept_v
				- ray_data->x_ver) * tan(ray_data->angle));
	ray_data->x_step_v = SZ;
	if (ray_data->ray_left)
		ray_data->x_step_v *= -1;
	ray_data->y_step_v = SZ * tan(ray_data->angle);
	if ((ray_data->ray_up && ray_data->y_step_v > 0) || (ray_data->ray_down
			&& ray_data->y_step_v < 0))
		ray_data->y_step_v *= -1;
	ray_data->x_ver = ray_data->x_intercept_v;
	ray_data->y_ver = ray_data->y_intercept_v;
	convert_into_map_v(ray_data, cub);
}
