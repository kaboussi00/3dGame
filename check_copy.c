#include "cub3d.h"

void	check_not_char(t_cub *cub)
{
	cub->i = 0;
	while (cub->i < cub->line)
	{
		printf("{line %d}\n", cub->line);
		cub->j = 0;
		while (cub->j < cub->len)
		{
			printf("{len %d}\n", cub->len);
			if ((!ft_strchr("10W ", cub->map[cub->i][cub->j])) || (!ft_strchr("10S ", cub->map[cub->i][cub->j])) \
            || (!ft_strchr("10N ", cub->map[cub->i][cub->j])) || (!ft_strchr("10E ", cub->map[cub->i][cub->j])) )
				printerror_message("koukia\n");
			cub->j++;
		}
		cub->i++;
	}
}

void	check_char(t_cub	*cub)
{
	cub->i = 0;
	cub->p = 0;
    printf("len : {%d}\n", cub->len);
    printf("line : {%d}\n", cub->line);
    int p;
    puts("b");
    while (cub->map[p])
    {
        puts("l");
        printf("map : {%s}\n", cub->map[p]);
        p++;
    }
    puts("j");
	while (cub->i++ < cub->line - 1)
	{
        puts("here");
		cub->j = 0;
		while (cub->j < cub->len - 1)
		{
             puts("here1");
			if (cub->map[cub->i][cub->j] == 'W' || cub->map[cub->i][cub->j] == 'E' \
            || cub->map[cub->i][cub->j] == 'S' || cub->map[cub->i][cub->j] == 'A')
			{
                puts("a");
				cub->p += 1;
				cub->pos_i = cub->i;
				cub->pos_j = cub->j;
			}
            puts("b");
            cub->j++;
		}
        cub->i++;
	}
    puts("here2");
	if (cub->p != 1)
		printerror_message("more or less than one player\n");
}
