/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:08:17 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/21 17:01:39 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void init_textures_helper(t_cub *cub)
    {
    cub->south_img.addr = mlx_get_data_addr(cub->south_img.img, &cub->south_img.bits_per_pixel, &cub->south_img.line_length, &cub->south_img.endian);
    cub->south_table = (unsigned int *)cub->south_img.addr;
    cub->west_img.img = mlx_xpm_file_to_image(cub->mlx, cub->west_texture_path, &cub->west_img.width, &cub->west_img.height);
    if (cub->west_img.img == NULL)
    {
        printerror_message("Failed to load texture!\n");
        exit(1);
    }
    cub->west_img.addr = mlx_get_data_addr(cub->west_img.img, &cub->west_img.bits_per_pixel, &cub->west_img.line_length, &cub->west_img.endian);
    cub->west_table = (unsigned int *)cub->west_img.addr;
    cub->east_img.img = mlx_xpm_file_to_image(cub->mlx, cub->east_texture_path, &cub->east_img.width, &cub->east_img.height);
    if (cub->east_img.img == NULL)
    {
        printerror_message("Failed to load texture!\n");
        exit(1);
    }
    cub->east_img.addr = mlx_get_data_addr(cub->east_img.img, &cub->east_img.bits_per_pixel, &cub->east_img.line_length, &cub->east_img.endian);
    cub->east_table = (unsigned int *)cub->east_img.addr;
}

void init_textures(t_cub *cub)
{
    cub->north_img.img = mlx_xpm_file_to_image(cub->mlx, cub->north_texture_path, &cub->north_img.width, &cub->north_img.height);
    if (cub->north_img.img == NULL)
    {
        printerror_message("Failed to load texture!\n");
        exit(1);
    }
    cub->north_img.addr = mlx_get_data_addr(cub->north_img.img, &cub->north_img.bits_per_pixel, &cub->north_img.line_length, &cub->north_img.endian);
    cub->north_table = (unsigned int *)cub->north_img.addr;
    cub->south_img.img = mlx_xpm_file_to_image(cub->mlx, cub->south_texture_path, &cub->south_img.width, &cub->south_img.height);
    if (cub->south_img.img == NULL)
    {
        printerror_message("Failed to load texture!\n");
        exit(1);
    }
    init_textures_helper(cub);
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
    
    init_textures(cub);
    mlx_loop_hook(cub->mlx, &render, cub);

	mlx_hook(cub->mlx_window, 17, 0L, &myExit_prs, cub);
	mlx_hook(cub->mlx_window, 3, 0L, &keyReleases, cub);
    mlx_hook(cub->mlx_window, 2, 0L, &keyPress, cub);
    mlx_hook(cub->mlx_window, 6, 0, &handleMouse, cub);
    mlx_loop(cub->mlx);
    return (0);
}