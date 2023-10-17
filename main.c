/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:08:17 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/17 18:08:43 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void    init_textures(t_cub *cub)
// {
//    cub->east.img = mlx_xpm_file_to_image(cub->mlx, cub->south_texture_path, &cub->east.width, &cub->east.height);
//     // Similar lines for other textures (north, south, west)
//     if (cub->east.img == NULL)
//         printerror_message("Failed to load textures!\n");
//     cub->east.addr = mlx_get_data_addr(cub->east.img, \
//             &cub->east.bits_per_pixel, \
//             &cub->east.line_length, &cub->east.endian);
//     cub->east_table = (unsigned int*)cub->east.addr;
// }


int handleMouse(int x, int y, t_cub *cub)
{
    static int prevX = -1; // Previous mouse X position
    int deltaX;
    if (prevX != -1) {
        deltaX = x - prevX; // Change in mouse X position
        cub->player.rotationangle += deltaX * MOUSE_SENSITIVITY;
        render(cub);
    }
    prevX = x; // Update previous mouse X position
    return 0;
}

int main(int ac, char **av)
{
    t_cub   *cub;

    cub = malloc(sizeof(t_cub));
	if (!cub)
        return (0);
    if (ac != 2)
        printerror_message("invalid arg\n");
    initial_variable(cub);
    parse(cub, av[1]);
    player_position(cub);
    cub->mlx = mlx_init();
    cub->mlx_window = mlx_new_window(cub->mlx, WIDTH ,HEIGHT,  "my map <3");
    cub->img.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
    cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel, \
    &cub->img.line_length, &cub->img.endian);
    mlx_loop_hook(cub->mlx, &render, cub);
    mlx_hook(cub->mlx_window, 2, 0L, &keyPress, cub);
	mlx_hook(cub->mlx_window, 17, 0L, &myExit_prs, cub);
	mlx_hook(cub->mlx_window, 3, 0L, &keyReleases, cub);
    // mlx_hook(cub->mlx_window, 6, 0, &handleMouse, cub);
    mlx_loop(cub->mlx);
    return (0);
}