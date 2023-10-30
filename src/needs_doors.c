/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needs_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:55:47 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/30 09:56:01 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_close(t_cub *cub)
{
	int	x;
	int	y;

	x = (int)(cub->player.posx_inmap / SZ);
	y = (int)(cub->player.posy_inmap / SZ);
	if (cub->map[x + 1][y] == 'D')
		cub->map[x + 1][y] = 'd';
	if (cub->map[x - 1][y] == 'D')
		cub->map[x - 1][y] = 'd';
	if (cub->map[x][y + 1] == 'D')
		cub->map[x][y + 1] = 'd';
	if (cub->map[x][y - 1] == 'D')
		cub->map[x][y - 1] = 'd';
}

void	check_open(t_cub *cub)
{
	int	x;
	int	y;

	x = (int)(cub->player.posx_inmap / SZ);
	y = (int)(cub->player.posy_inmap / SZ);
	if (cub->map[x + 1][y] == 'd')
		cub->map[x + 1][y] = 'D';
	if (cub->map[x - 1][y] == 'd')
		cub->map[x - 1][y] = 'D';
	if (cub->map[x][y + 1] == 'd')
		cub->map[x][y + 1] = 'D';
	if (cub->map[x][y - 1] == 'd')
		cub->map[x][y - 1] = 'D';
}

void	ft_check_status_door(t_cub *cub, int flags)
{
	if (flags)
		check_close(cub);
	else
		check_open(cub);
}
