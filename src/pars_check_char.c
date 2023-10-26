/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:09:58 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/26 21:39:00 by rel-isma         ###   ########.fr       */
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
					|| (cub->map[cub->i - 1][cub->j] == '1'
                    && cub->map[cub->i + 1][cub->j] == '1'))
				{
                    cub->pos_door_x = cub->i;
                    cub->pos_door_y = cub->j;
				}
				else
					printerror_message("Invalid door placement!\n");
			}
			cub->j++;
		}
		cub->i++;
	}
	return (0);
}



void	check_char(t_cub *cub)
{
	cub->i = 0;
	cub->p = 0;
    cub->door_states =  0;
	while (cub->i < cub->line - 6)
	{
		cub->j = 0;
		while (cub->j < cub->len - 1)
		{
            if  (cub->map[cub->i][cub->j] == 'D')
                   cub->door_states++;
			if (cub->map[cub->i][cub->j] == 'W'
				|| cub->map[cub->i][cub->j] == 'E'
				|| cub->map[cub->i][cub->j] == 'S'
				|| cub->map[cub->i][cub->j] == 'A')
			{
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
