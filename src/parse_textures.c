/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:54:55 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/29 18:36:19 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_helper_parse_path(t_cub *cub, char **split, char *line)
{
	char	*texture_path;

	texture_path = ft_strdup(split[1]);
	if (ft_strcmp(split[0], "NO") == 0)
		cub->north_texture_path = texture_path;
	else if (ft_strcmp(split[0], "SO") == 0)
		cub->south_texture_path = texture_path;
	else if (ft_strcmp(split[0], "WE") == 0)
		cub->west_texture_path = texture_path;
	else if (ft_strcmp(split[0], "EA") == 0)
		cub->east_texture_path = texture_path;
	else if (ft_strcmp(split[0], "F") == 0)
	{
		free(texture_path);
		parse_texture_color(cub, line);
	}
	else if (ft_strcmp(split[0], "C") == 0)
	{
		free(texture_path);
		parse_texture_color(cub, line);
	}
	else
		return (free(texture_path), free_splite(split),
			printerror_message("Invalid texture path!\n"));
}

void	parse_texture_path(t_cub *cub, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		printerror_message("Invalid texture path!!\n");
	if (split && split[1] && split[2] == NULL)
		ft_helper_parse_path(cub, split, line);
	else
		return (free_splite(split),
			printerror_message("Invalid texture path!\n"));
	free_splite(split);
}

void	ft_parse_color(char *str, t_cub *cub, char **split, int flg)
{
	char	**rgb;

	parse_line_color(str);
	rgb = ft_split(str, ',');
	if (!rgb || rgb[1] == NULL || rgb[2] == NULL)
		return (free_splite(split), printerror_message("Invalid color!\n"));
	if (flg)
	{
		if (ft_atoi(rgb[0]) >= 0 && ft_atoi(rgb[0]) <= 255
			&& ft_atoi(rgb[1]) >= 0 && ft_atoi(rgb[1]) <= 255
			&& ft_atoi(rgb[2]) >= 0 && ft_atoi(rgb[2]) <= 255)
			cub->color_floor = rgb_to_int(ft_atoi(rgb[0]), ft_atoi(rgb[1]),
				ft_atoi(rgb[2]));
		else
			return (free_splite(rgb), free_splite(split),
				printerror_message("Invalid color!\n"));
	}
	else
	{
		if (ft_atoi(rgb[0]) >= 0 && ft_atoi(rgb[0]) <= 255
			&& ft_atoi(rgb[1]) >= 0 && ft_atoi(rgb[1]) <= 255
			&& ft_atoi(rgb[2]) >= 0 && ft_atoi(rgb[2]) <= 255)
			cub->color_ceiling = rgb_to_int(ft_atoi(rgb[0]), ft_atoi(rgb[1]),
				ft_atoi(rgb[2]));
		else
			return (free_splite(rgb), free_splite(split),
				printerror_message("Invalid color!\n"));
	}
	return (free_splite(rgb));
}

void	parse_texture_color(t_cub *cub, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		printerror_message("Invalid color!\n");
	if (split && split[1] && split[2] == NULL)
	{
		if (ft_strcmp(split[0], "F") == 0)
			ft_parse_color(split[1], cub, split, 1);
		else if (ft_strcmp(split[0], "C") == 0)
			ft_parse_color(split[1], cub, split, 0);
		free_splite(split);
	}
	else
		return (free_splite(split), printerror_message("Invalid color!\n"));
}
