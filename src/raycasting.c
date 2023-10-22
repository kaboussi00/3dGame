/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 07:04:47 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/22 14:16:15 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cast_rays(t_cub *cub)
{
	int i = 0;
	cub->ray_data = malloc(sizeof(t_ray) * NUM_RAYS);
	if (!cub->ray_data)
		return ;
	cub->player.rayangle = cub->player.rotation_angle - (FOV / 2);
	while (i < NUM_RAYS)
	{
		cub->player.rayangle = normalizing_angle(cub->player.rayangle);
		cub->ray_data[i].angle = cub->player.rayangle;
		set_directions(&cub->ray_data[i]);
		check_wall__hor(&cub->ray_data[i], cub);
		check_wall__ver(&cub->ray_data[i], cub);
		closest_dis(&cub->ray_data[i], cub);
		cub->player.rayangle += FOV / NUM_RAYS;
		i++;
	}
}