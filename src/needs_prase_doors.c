/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needs_prase_doors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:43:35 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/28 23:48:02 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_doors_v(t_cub *cub, int i, int j)
{
	if ((cub->map[i][j - 1] == '1' && cub->map[i][j + 1] == '1') || (cub->map[i
			- 1][j] == '1' && cub->map[i + 1][j] == '1'))
	{
		return (1);
	}
	else
		return (0);
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
				if (check_doors_v(cub, cub->i, cub->j))
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
					num_door++;
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
		if (!cub->door_positions[i])
			printerror_message("aloc door!\n");
		i++;
	}
}
