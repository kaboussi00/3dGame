/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:04:33 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/22 14:40:06 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_textures_helper(t_cub *cub)
{
	cub->south_img.addr = mlx_get_data_addr(cub->south_img.img,
			&cub->south_img.bits_per_pixel, &cub->south_img.line_length,
			&cub->south_img.endian);
	cub->south_table = (unsigned int *)cub->south_img.addr;
	cub->west_img.img = mlx_xpm_file_to_image(cub->mlx, cub->west_texture_path,
			&cub->west_img.width, &cub->west_img.height);
	if (cub->west_img.img == NULL)
		return (printerror_message("Failed to load texture!\n"), exit(1));
	cub->west_img.addr = mlx_get_data_addr(cub->west_img.img,
			&cub->west_img.bits_per_pixel, &cub->west_img.line_length,
			&cub->west_img.endian);
	cub->west_table = (unsigned int *)cub->west_img.addr;
	cub->east_img.img = mlx_xpm_file_to_image(cub->mlx, cub->east_texture_path,
			&cub->east_img.width, &cub->east_img.height);
	if (cub->east_img.img == NULL)
		return (printerror_message("Failed to load texture!\n"), exit(1));
	cub->east_img.addr = mlx_get_data_addr(cub->east_img.img,
			&cub->east_img.bits_per_pixel, &cub->east_img.line_length,
			&cub->east_img.endian);
	cub->east_table = (unsigned int *)cub->east_img.addr;
}

void	init_textures(t_cub *cub)
{
	cub->north_img.img = mlx_xpm_file_to_image(cub->mlx,
			cub->north_texture_path,
			&cub->north_img.width, &cub->north_img.height);
	if (cub->north_img.img == NULL)
	{
		printerror_message("Failed to load texture!\n");
		exit(1);
	}
	cub->north_img.addr = mlx_get_data_addr(cub->north_img.img,
			&cub->north_img.bits_per_pixel, &cub->north_img.line_length,
			&cub->north_img.endian);
	cub->north_table = (unsigned int *)cub->north_img.addr;
	cub->south_img.img = mlx_xpm_file_to_image(cub->mlx,
			cub->south_texture_path,
			&cub->south_img.width, &cub->south_img.height);
	if (cub->south_img.img == NULL)
	{
		printerror_message("Failed to load texture!\n");
		exit(1);
	}
	init_textures_helper(cub);
}
