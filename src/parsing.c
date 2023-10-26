/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:08:46 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/26 14:45:47 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse(t_cub *cub, char *file)
{
	cub->east_table = NULL;
	cub->west_table = NULL;
	cub->north_table = NULL;
	cub->south_table = NULL;
	check_extension(file);
	check_opening(file);
	count_map(cub, file);
	press_map(cub, file);
	check_texture_color(cub);
	parse_texture_path(cub, cub->all_map[0]);
	parse_texture_path(cub, cub->all_map[1]);
	parse_texture_path(cub, cub->all_map[2]);
	parse_texture_path(cub, cub->all_map[3]);
	parse_texture_path(cub, cub->all_map[4]);
	parse_texture_path(cub, cub->all_map[5]);
	new_map(cub);
	check_char(cub);
	check_not_char(cub);
	copie_with_spaces(cub);
	check_wall(cub);
	check_doors(cub);
}
