/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render_ver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:15:30 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/11 10:48:52 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void convert_into_mapV(t_ray *rayData, t_cub *cub)
{
	double x;

	while (rayData->x_ver >= 0 && rayData->x_ver <= (cub->line - 6) * SZ
		&& rayData->y_ver >= 0 && rayData->y_ver <= cub->len * SZ)
	{
		x = rayData->x_ver;
		if (rayData->rayLeft)
			x--;
		if (cub->map[(int)(x / SZ)][(int)(rayData->y_ver / SZ)] != '1'
			&& cub->map[(int)(x / SZ)][(int)(rayData->y_ver / SZ)] != ' ')
		{
			rayData->x_ver += rayData->x_Step_V;
			rayData->y_ver += rayData->y_Step_V;
		}
		else
			break;
	}
}

void CheckWall__Ver(t_ray *rayData, t_cub *cub)
{
	rayData->x_ver = cub->player.xInwindow;
	rayData->y_ver = cub->player.yInwindow;
	rayData->xIntercept_V = floor(rayData->x_ver / SZ) * SZ;
	if (rayData->rayRight)
		rayData->xIntercept_V += SZ;
	rayData->yIntercept_V = rayData->y_ver + ((rayData->xIntercept_V - rayData->x_ver) * tan(rayData->angle));
	rayData->x_Step_V = SZ;
	if (rayData->rayLeft)
		rayData->x_Step_V *= -1;
	rayData->y_Step_V = SZ * tan(rayData->angle);
	if ((rayData->rayUp && rayData->y_Step_V > 0) || (rayData->rayDown && rayData->y_Step_V < 0))
		rayData->y_Step_V *= -1;
	rayData->x_ver = rayData->xIntercept_V;
	rayData->y_ver = rayData->yIntercept_V;
	convert_into_mapV(rayData, cub);
}
