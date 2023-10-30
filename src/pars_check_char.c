/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:09:58 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/30 19:48:16 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_not_char(t_cub *cub)
{
	cub->i = 0;
	while (cub->i < cub->line - 6)
	{
		cub->j = 0;
		while (cub->j < cub->len - 1)
		{
			if (!ft_strchr("10WSEND ", cub->map[cub->i][cub->j]))
			{
				printf("char: %c\n", cub->map[cub->i][cub->j]);
				printerror_message("not valid character\n");
			}
			cub->j++;
		}
		cub->i++;
	}
}

void	set_rotation(t_cub *cub)
{
	if (cub->map[cub->i][cub->j] == 'W')
		cub->player.rotation_angle = M_PI;
	else if (cub->map[cub->i][cub->j] == 'E')
		cub->player.rotation_angle = 0;
	else if (cub->map[cub->i][cub->j] == 'S')
		cub->player.rotation_angle = M_PI_2;
	else if (cub->map[cub->i][cub->j] == 'N')
		cub->player.rotation_angle = 3 * M_PI_2;
}

void	check_char(t_cub *cub)
{
	cub->i = 0;
	cub->p = 0;
	while (cub->i < cub->line - 6)
	{
		cub->j = 0;
		while (cub->j < cub->len - 1)
		{
			if (cub->map[cub->i][cub->j] == 'W'
				|| cub->map[cub->i][cub->j] == 'E'
				|| cub->map[cub->i][cub->j] == 'S'
				|| cub->map[cub->i][cub->j] == 'N')
			{
				set_rotation(cub);
				cub->p += 1;
				cub->pos_i = cub->i;
				cub->pos_j = cub->j;
			}
			cub->j++;
		}
		cub->i++;
	}
	if (cub->p != 1)
		printerror_message("more or less than one player\n");
}
