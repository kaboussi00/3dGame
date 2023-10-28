/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render_ver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:15:30 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/28 07:47:53 by rel-isma         ###   ########.fr       */
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
		if (ray_data->rayLeft)
			x--;
		if (cub->map[(int)(x / SZ)][(int)((ray_data->y_ver / SZ))] == 'D')
			ray_data->flags_ver = 1;
		else
			ray_data->flags_ver = 0;
		if (cub->map[(int)(x / SZ)][(int)(ray_data->y_ver / SZ)] != '1'
			&& cub->map[(int)(x / SZ)][(int)(ray_data->y_ver / SZ)] != ' ' \
            && cub->map[(int)(x / SZ)][(int)(ray_data->y_ver / SZ)] != 'D')
		{
			ray_data->x_ver += ray_data->x_Step_V;
			ray_data->y_ver += ray_data->y_Step_V;
		}
		else
			break ;
	}
}

void	check_wall__ver(t_ray *ray_data, t_cub *cub)
{
	ray_data->x_ver = cub->player.xInwindow;
	ray_data->y_ver = cub->player.yInwindow;
	ray_data->xIntercept_V = floor(ray_data->x_ver / SZ) * SZ;
	if (ray_data->rayRight)
		ray_data->xIntercept_V += SZ;
	ray_data->yIntercept_V = ray_data->y_ver + ((ray_data->xIntercept_V
				- ray_data->x_ver) * tan(ray_data->angle));
	ray_data->x_Step_V = SZ;
	if (ray_data->rayLeft)
		ray_data->x_Step_V *= -1;
	ray_data->y_Step_V = SZ * tan(ray_data->angle);
	if ((ray_data->rayUp && ray_data->y_Step_V > 0) || (ray_data->rayDown
			&& ray_data->y_Step_V < 0))
		ray_data->y_Step_V *= -1;
	ray_data->x_ver = ray_data->xIntercept_V;
	ray_data->y_ver = ray_data->yIntercept_V;
	convert_into_map_v(ray_data, cub);
}
