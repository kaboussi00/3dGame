/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:29:10 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/30 10:54:18 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rotationIndexX(t_cub *cub)
{
	double ra;
	double x;
		
	x = 1;
	ra = cub->player.rotationangle;
	if (ra >= 0 && ra < M_PI_2)
		x *= 1;
	else if (ra >= M_PI_2 && ra < M_PI)
		x *= -1;
	else if (ra >= M_PI && ra < 3 * M_PI / 2)
		x *= -1;
	else if (ra >= 3 * M_PI / 2 && ra < 2 * M_PI)
		x *= 1;
	return (x);
}

int	rotationIndexY(t_cub *cub)
{
	double ra;
	double y;

	y = 1;
	ra = cub->player.rotationangle;
	if (ra >= 0 && ra < M_PI_2)
		y *= -1;
	else if (ra >= M_PI_2 && ra < M_PI)
		y *= -1;
	else if (ra >= M_PI && ra < 3 * M_PI / 2)
		y *= 1;
	else if (ra >= 3 * M_PI / 2 && ra < 2 * M_PI)
		y *= 1;
	return (y);
}

int	render(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->mlx_window);
	render_minimap(cub);
	render_player(cub, SZ/4);
	drowLine(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_window, cub->img.img, 0, 0);
	return(0);
}