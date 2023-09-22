#include "cub3d.h"

void player_position(t_cub *cub)
{
    // in window
    cub->pos_i = cub->pos_i * SZ + (SZ / 2);
    cub->pos_j = cub->pos_j * SZ + (SZ / 2);
}

void render_player(t_cub *cub, int rayon)
{
    double  i;
    double  degr;
    double  new_y;
    double  new_x;

    i = 0;
    while(i < rayon)
    {
        degr = 0;
        while(degr < 360)
        {
            new_x = i * cos(degr * M_PI / 180);
            new_y = i * sin(degr * M_PI / 180);
            own_mlx_pixel_put(cub, cub->pos_j + new_y, cub->pos_i + new_x, 0xf5756c);
            degr++;
        }
        i++;
    }

}