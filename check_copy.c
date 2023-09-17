#include "cub3d.h"

void	check_not_char(t_cub *cub)
{
	cub->i = 0;
	int p = 0;
	while (cub->i < cub->line - 6)
	{
		printf("{line %d}\n", cub->line - 6);
		while (cub->map[p])
		{
			printf("map ; %s\n", cub->map[p]);
			p++;
		}
		cub->j = 0;
		while (cub->j < cub->len)
		{
			puts("here");
			printf("{len %d}\n", cub->len);
			if ((!ft_strchr("10W ", cub->map[cub->i][cub->j])) || (!ft_strchr("10S ", cub->map[cub->i][cub->j])) \
            || (!ft_strchr("10N ", cub->map[cub->i][cub->j])) || (!ft_strchr("10E ", cub->map[cub->i][cub->j])) )
				printerror_message("koukia\n");
			cub->j++;
		}
		puts("======================");
		cub->i++;
	}
	puts("bvbvbv");
}

void	check_char(t_cub	*cub)
{
	cub->i = 0;
	cub->p = 0;
	cub->space = 0;
	cub->wall = 0;
    printf("len : {%d}\n", cub->len);
    printf("line : {%d}\n", cub->line);
    int l = 0;
    puts("b");
    while (cub->map[l])
    {
        puts("l");
        printf("map : {%s}\n", cub->map[l]);
        l++;
    }
    puts("j");
	while (cub->i < cub->line - 6)
	{
        puts("here");
		cub->j = 0;
		while (cub->j < cub->len - 6)
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
			// else if (cub->map[cub->i][cub->j] == '0')
			// 	cub->space++;
			// else if (cub->map[cub->i][cub->j] == '1')
			// 	cub->wall++;
            puts("b");
            cub->j++;
		}
        cub->i++;
	}
    puts("here2");
	if (cub->p != 1)
		printerror_message("more or less than one player\n");
	// else if (cub->space < 1)
	// 	printerror_message("no space !!");
	// else if (cub->wall < 1)
	// 	printerror_message("no walls !!");
}

void check_space(t_cub	*cub)
{
	cub->i = 0;
	cub->j = 0;

}