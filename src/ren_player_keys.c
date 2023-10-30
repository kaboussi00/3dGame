/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ren_player_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:23:06 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/30 01:51:39 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	handle_mouse(int x, int y, t_cub *cub)
{
	static int	prev_x;
	int			delta_x;

	prev_x = -1;
	(void)y;
	if (prev_x == -1)
		prev_x = x;
	delta_x = x - prev_x;
	cub->player.rotation_angle += delta_x * MOUSE_SENSITIVITY;
	render(cub);
	prev_x = x;
	return (0);
}

int	my_exit_prs(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->mlx_window);
	free_map(cub);
	exit(0);
	return (0);
}

void	ft_helper(int code, t_cub *cub)
{
	if (code == 123 || code == 124)
	{
		if (code == 123)
			cub->player.turn_direction = -1;
		if (code == 124)
			cub->player.turn_direction = 1;
		rotation_angle(cub);
		render(cub);
	}
}

int	key_press(int code, t_cub *cub)
{
	if (code == 49 || code == 257)
	{
		if (code == 49)
			ft_check_status_door(cub, 1);
		else if (code == 257)
			ft_check_status_door(cub, 0);
	}
	if (code == 53)
	{
		mlx_destroy_window(cub->mlx, cub->mlx_window);
		free_map(cub);
		exit(0);
	}
	if (code == 3)
		spray(cub);
	if (code == 1 || code == 13)
	{
		if (code == 1)
			cub->player.walk_direction = -1;
		if (code == 13)
			cub->player.walk_direction = 1;
		move_walk_player(cub);
		render(cub);
	}
	if (code == 0 || code == 2)
	{
		if (code == 0)
			cub->player.side_direction = -1;
		if (code == 2)
			cub->player.side_direction = 1;
		move_side_player(cub);
		render(cub);
	}
	ft_helper(code, cub);
	return (0);
}

int	key_releases(int code, t_cub *cub)
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
	if (code == 3)
		cub->sprite = 0;
	render(cub);
	return (0);
}
