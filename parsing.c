#include "cub3d.h"

void parse(t_cub *cub, char *file)
{
	check_extension(file);
    check_opening(file);
    count_map(cub, file);
    press_map(cub, file);
    check_texture_color(cub);
    new_map(cub);
    check_char(cub);
    check_not_char(cub);
    copie_with_spaces(cub);
    check_wall(cub);
}