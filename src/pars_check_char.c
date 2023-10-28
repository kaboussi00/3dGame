/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:09:58 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/28 12:10:09 by rel-isma         ###   ########.fr       */
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
				printerror_message("not valid character\n");
			cub->j++;
		}
		cub->i++;
	}
}

int	check_doors(t_cub *cub)
{
	int	num_doors;

	num_doors = 0;
	cub->i = 0;
	while (cub->i < cub->line - 6)
	{
		cub->j = 0;
		while (cub->j < cub->len - 1)
		{
			if (cub->map[cub->i][cub->j] == 'D')
			{
				if ((cub->map[cub->i][cub->j - 1] == '1'
						&& cub->map[cub->i][cub->j + 1] == '1')
					|| (cub->map[cub->i - 1][cub->j] == '1' && cub->map[cub->i
						+ 1][cub->j] == '1'))
				{
					cub->door_positions[num_doors][0] = cub->i;
					cub->door_positions[num_doors][1] = cub->j;
					num_doors++;
				}
				else
					printerror_message("Invalid door placement!\n");
			}
			cub->j++;
		}
		cub->i++;
	}
	return (num_doors);
}

int	calculate_number_of_doors(t_cub *cub)
{
	int	num_door;

	num_door = 0;
	cub->i = 0;
	while (cub->i < cub->line - 6)
	{
		cub->j = 0;
		while (cub->j < cub->len - 1)
		{
			if (cub->map[cub->i][cub->j] == 'D')
			{
				if ((cub->map[cub->i][cub->j - 1] == '1'
						&& cub->map[cub->i][cub->j + 1] == '1')
					|| (cub->map[cub->i - 1][cub->j] == '1' && cub->map[cub->i
						+ 1][cub->j] == '1'))
				{
					num_door++;
				}
				else
					printerror_message("Invalid door placement!\n");
			}
			cub->j++;
		}
		cub->i++;
	}
	return (num_door);
}
void	doors_aloc(t_cub *cub)
{
	int	i;

	i = 0;
	cub->num_doors = calculate_number_of_doors(cub);
	cub->door_positions = (int **)malloc(cub->num_doors * sizeof(int *));
	if (!cub->door_positions)
		printerror_message("aloc door!\n");
	while (i < cub->num_doors)
	{
		cub->door_positions[i] = (int *)malloc(2 * sizeof(int));
		i++;
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
