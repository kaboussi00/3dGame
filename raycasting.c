/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 07:04:47 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/01 10:44:26 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double degress_to_radian(double degress)
{
    return degress * (M_PI/180.0);
}

void calculateFOVAndRays(double *fovAngle, int *numRays) 
{
    *fovAngle = 60.0 * (M_PI / 180.0);  // Calculate FOV angle in radians
    *numRays = 320;                     // Set the number of rays
}
