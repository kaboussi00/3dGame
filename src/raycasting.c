/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 07:04:47 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/27 20:45:26 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cast_rays(t_cub *cub)
{
	int	i;

	i = 0;
	cub->ray_data = malloc(sizeof(t_ray) * NUM_RAYS);
	if (!cub->ray_data)
		return ;
	cub->player.rayangle = cub->player.rotation_angle - (cub->fov / 2);
	while (i < NUM_RAYS)
	{
		cub->player.rayangle = normalizing_angle(cub->player.rayangle);
		cub->ray_data[i].angle = cub->player.rayangle;
		set_directions(&cub->ray_data[i]);
		check_wall__hor(&cub->ray_data[i], cub);
		check_wall__ver(&cub->ray_data[i], cub);
		closest_dis(&cub->ray_data[i], cub);
		cub->player.rayangle += cub->fov / NUM_RAYS;
		i++;
	}
}
