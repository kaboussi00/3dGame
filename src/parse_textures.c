/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:54:55 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/22 17:33:22 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_splite(char **split)
{
	int		i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	parse_texture_path(t_cub *cub, char *line)
{
	char	**split;
	char	*texture_path;

	split = ft_split(line, ' ');
	if (!split)
		printerror_message("Invalid texture path!\n");
	if (split && split[1] && split[2] == NULL)
	{
		texture_path = ft_strdup(split[1]);
		if (ft_strcmp(split[0], "NO") == 0)
			cub->north_texture_path = texture_path;
		else if (ft_strcmp(split[0], "SO") == 0)
			cub->south_texture_path = texture_path;
		else if (ft_strcmp(split[0], "WE") == 0)
			cub->west_texture_path = texture_path;
		else if (ft_strcmp(split[0], "EA") == 0)
			cub->east_texture_path = texture_path;
		else
			return (free(texture_path), free_splite(split),
				printerror_message("Invalid texture path!\n"));
	}
	else
		return (free_splite(split),
			printerror_message("Invalid texture path!\n"));
}

void	ft_parse_color(char *str, t_cub *cub, char **split, int flg)
{
	char	**rgb;

	rgb = ft_split(str, ',');
	if (!rgb)
		return (free_splite(split),
			printerror_message("Invalid color!\n"));
	if (flg)
	{
		cub->color_floor = rgb_to_int(atoi(rgb[0]), atoi(rgb[1]),
				atoi(rgb[2]));
	}
	else
		cub->color_ceiling = rgb_to_int(atoi(rgb[0]), atoi(rgb[1]),
				atoi(rgb[2]));
	free_splite(rgb);
}

void	parse_texture_color(t_cub *cub, char *line)
{
	char	**split;
	char	**rgb;
	char	**rgb2;

	rgb = NULL;
	rgb2 = NULL;
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
