/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ren_player_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:23:06 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/21 17:44:12 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int handleMouse(int x, int y, t_cub *cub)
{
    (void)y;
    static int prevX = -1;

    if (prevX == -1)
        prevX = x; 
    int deltaX = x - prevX; 
    cub->player.rotationangle += deltaX * MOUSE_SENSITIVITY;
    render(cub);
    prevX = x;
    return 0;
}

int	myExit_prs(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->mlx_window);
	exit(0);
	return (0);
}

int keyPress(int code, t_cub *cub)
{
	if (code == 53)
		exit(0);
	if (code == 1 || code == 13)
	{
		if (code == 1)
			cub->player.walk_direction = -1;
		if (code == 13)
			cub->player.walk_direction = 1;
		moveWalkPlayer(cub);
		render(cub);
	}
	if (code == 0 || code == 2)
	{
		if (code == 0)
			cub->player.side_direction = -1;
		if (code == 2)
			cub->player.side_direction = 1;
		moveSidePlayer(cub);
		render(cub);
	}
	if (code == 123 || code == 124)
	{
		if (code == 123)
			cub->player.turn_direction = -1;
		if (code == 124)
			cub->player.turn_direction = 1;
		rotationAngle(cub);
		render(cub);
	}
	return (0);
}


int keyReleases(int code, t_cub *cub)
{
	if (code == 13)
		cub->player.walk_direction = 0;
	if (code == 1)
		cub->player.walk_direction = 0;
	if (code == 0)
		cub->player.side_direction = 0;
	if (code == 2)
		cub->player.side_direction = 0;
	if (code == 123)
		cub->player.turn_direction = 0;
	if (code == 124)
		cub->player.turn_direction = 0;
	render(cub);
	return (0);
}
