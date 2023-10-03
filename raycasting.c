/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 07:04:47 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/03 13:50:48 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void castRays(t_cub *cub)
{
    int i;

    i = 0;
    cub->rayData = malloc(sizeof(t_ray) * NUM_RAYS);
	if (!cub->rayData)
        return (0);
    // Start first ray subtracting half of the FOV
    cub->player.rayangle = cub->player.rotationangle - (FOV / 2);

    // Loop all columns casting the FOV
    while (i < NUM_RAYS) 
    {
        cub->rayData->angle = cub->player.rayangle;
        // ray.cast()... (You'll need to implement ray casting here)

        // cub->rayData[i]. = ; // Store the ray in the rays array

        cub->player.rayangle += FOV / NUM_RAYS;
        i++;
    }
}
