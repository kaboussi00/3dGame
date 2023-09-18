#include "cub3d.h"

void	check_not_char(t_cub *cub)
{
	cub->i = 0;
	while (cub->i < cub->line - 6)
	{
		cub->j = 0;
		while (cub->j < cub->len - 1)
		{
			if (!ft_strchr("10WSEN ", cub->map[cub->i][cub->j]))
				printerror_message("not valid character\n");
			cub->j++;
		}
		cub->i++;
	}
}

void	check_char(t_cub	*cub)
{
	cub->i = 0;
	cub->p = 0;
	while (cub->i < cub->line - 6)
	{
		cub->j = 0;
		while (cub->j < cub->len - 6)
		{
			if (cub->map[cub->i][cub->j] == 'W' || cub->map[cub->i][cub->j] == 'E' \
            || cub->map[cub->i][cub->j] == 'S' || cub->map[cub->i][cub->j] == 'A')
			{
				cub->p += 1;
				cub->pos_i = cub->i;
				cub->pos_j = cub->j;
			}
			else if (cub->map[cub->i][cub->j] == '0')
				cub->space++;
            cub->j++;
		}
        cub->i++;
	}
	if (cub->p != 1)
		printerror_message("more or less than one player\n");
}
