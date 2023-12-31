#include "cub3d.h"

void copie_with_spaces(t_cub *cub)
{
    cub->i = 0;
    cub->j = 1;
    int x;
    int y;
    cub->copie=malloc(sizeof(char *) * cub->line - 3);
    if (!cub->copie)
        return ;
    cub->copie[0]=charge_space(' ', cub->len + 2);
    while (cub->i < cub->line - 6)
    {
        x=1;
        y=0;
        cub->copie[cub->j] = malloc(sizeof(char) * cub->len + 2);
        cub->copie[cub->j][0] = ' ';
        while(cub->map[cub->i][y])   
            cub->copie[cub->j][x++] = cub->map[cub->i][y++];
        cub->copie[cub->j][cub->len + 1] = ' ';
        cub->copie[cub->j][cub->len + 2] = '\0';
        cub->i++;
        cub->j++;
    }
    cub->copie[cub->j]=charge_space(' ', cub->len + 2);
    cub->copie[cub->j+1]=NULL;
}

void    check_wall(t_cub *cub)
{
    int x;
    int y;
    x = 0;
    while (cub->copie[x])
    {
        y = 0;
        while (cub->copie[x][y])
        {
            if (cub->copie[x][y] == '0' || cub->copie[x][y] == cub->map[cub->pos_i][cub->pos_j])
            {
                if (cub->copie[x][y + 1] == ' ' || cub->copie[x][y - 1] == ' '\
                || cub->copie[x + 1][y] == ' ' || cub->copie[x - 1][y] == ' ')
                    printerror_message("invalid map!!\n");
            } 
            y++;
        }
        x++;
    }
}