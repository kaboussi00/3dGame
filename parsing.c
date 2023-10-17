/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:08:46 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/17 17:40:05 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void parse(t_cub *cub, char *file)
// {
// 	check_extension(file);
//     check_opening(file);
//     count_map(cub, file);
//     press_map(cub, file);
//     check_texture_color(cub);
//     new_map(cub);
//     check_char(cub);
//     check_not_char(cub);
//     copie_with_spaces(cub);
//     check_wall(cub);
// }
void parse(t_cub *cub, char *file)
{
    check_extension(file);
    check_opening(file);
    count_map(cub, file);
    press_map(cub, file);
    // check_texture_color(cub);
    parse_texture_path(cub, cub->all_map[0]); // Parse North texture path
    parse_texture_path(cub, cub->all_map[1]); // Parse South texture path
    parse_texture_path(cub, cub->all_map[2]); // Parse West texture path
    parse_texture_path(cub, cub->all_map[3]); // Parse East texture path
    new_map(cub);
    check_char(cub);
    check_not_char(cub);
    copie_with_spaces(cub);
    check_wall(cub);
}
