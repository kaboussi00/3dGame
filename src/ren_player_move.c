/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ren_player_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:45:42 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/28 06:47:05 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotation_angle(t_cub *cub)
{
	cub->player.rotation_angle += cub->player.turn_direction
		* cub->player.rotation_speed;
	if (cub->player.rotation_angle >= 360 * (M_PI / 180))
		cub->player.rotation_angle -= 360 * (M_PI / 180);
	if (cub->player.rotation_angle < 0)
		cub->player.rotation_angle += 360 * (M_PI / 180);
}


int	check_wall_walk(t_cub *cub)
{
	double	x;
	double	y;

	x = cub->player.xInwindow + cos(cub->player.rotation_angle)
		* cub->player.move_step;
	y = cub->player.yInwindow + sin(cub->player.rotation_angle)
		* cub->player.move_step;
	if ((cub->map[(int)((x) / SZ)][(int)((y) / SZ)] != '1' && cub->map[(int)((x)
				/ SZ)][(int)((y) / SZ)] != ' ')
		&& ((int)(cub->map[(int)cub->player.xInwindow / SZ][(int)y / SZ] != '1')
			&& cub->map[(int)x / SZ][(int)cub->player.yInwindow / SZ] != '1'))
		return (1);
	return (0);
}

int	check_wall_side(t_cub *cub)
{
	double	x;
	double	y;

	x = cub->player.xInwindow + cos(cub->player.rotation_angle + M_PI_2)
		* cub->player.move_step;
	y = cub->player.yInwindow + sin(cub->player.rotation_angle + M_PI_2)
		* cub->player.move_step;
	if ((cub->map[(int)((x) / SZ)][(int)((y) / SZ)] != '1' && cub->map[(int)((x)
				/ SZ)][(int)((y) / SZ)] != ' ')
		&& (((int)cub->map[(int)cub->player.xInwindow / SZ][(int)y / SZ] != '1')
			&& cub->map[(int)x / SZ][(int)cub->player.yInwindow / SZ] != '1'))
		return (1);
	return (0);
}

void	move_walk_player(t_cub *cub)
{
	cub->player.move_step = cub->player.walk_direction * cub->player.move_speed;
	cub->player.posXinmap = cub->player.xInwindow
		+ cos(cub->player.rotation_angle) * cub->player.move_step;
	cub->player.posYinmap = cub->player.yInwindow
		+ sin(cub->player.rotation_angle) * cub->player.move_step;
	if (check_wall_walk(cub))
	{
		cub->player.move_step = cub->player.walk_direction
			* cub->player.move_speed;
		cub->player.xInwindow += cos(cub->player.rotation_angle)
			* cub->player.move_step;
		cub->player.yInwindow += sin(cub->player.rotation_angle)
			* cub->player.move_step;
	}
}

void	move_side_player(t_cub *cub)
{
	cub->player.move_step = cub->player.side_direction * cub->player.move_speed;
	cub->player.posXinmap = cub->player.xInwindow
		+ cos(cub->player.rotation_angle + M_PI_2) * cub->player.move_step;
	cub->player.posYinmap = cub->player.yInwindow
		+ sin(cub->player.rotation_angle + M_PI_2) * cub->player.move_step;
	if (check_wall_side(cub))
	{
		cub->player.move_step = cub->player.side_direction
			* cub->player.move_speed;
		cub->player.xInwindow += cos(cub->player.rotation_angle + M_PI_2)
			* cub->player.move_step;
		cub->player.yInwindow += sin(cub->player.rotation_angle + M_PI_2)
			* cub->player.move_step;
	}
}
