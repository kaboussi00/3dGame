/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:54:55 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/22 16:23:21 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len_str;
	char	*scpy;

	len_str = ft_strlen((char *)s1);
	scpy = malloc((len_str + 1) * sizeof(char));
	if (!scpy)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		scpy[i] = s1[i];
		i++;
	}
	scpy[i] = '\0';
	return (scpy);
}

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
			return (free(texture_path), free_splite(split), printerror_message("Invalid texture path!\n"));
	}
	else
		return (free_splite(split), printerror_message("Invalid texture path!\n"));
}

void	parse_texture_color(t_cub *cub, char *line)
{
	char	**split;
	char	**rgb;
	char	**rgb2;

	split = ft_split(line, ' ');
	if (!split)
		printerror_message("Invalid texture type!\n");
	if (split && split[1] && split[2] == NULL)
	{
		if (ft_strcmp(split[0], "F") == 0)
		{
			rgb = ft_split(split[1], ',');
			if (!rgb)
				return (free_splite(split), printerror_message("Invalid texture color!\n"));
			cub->color_floor = rgb_to_int(atoi(rgb[0]), atoi(rgb[1]),
					atoi(rgb[2]));
			free_splite(rgb);
		}
		else if (ft_strcmp(split[0], "C") == 0)
		{
			rgb2 = ft_split(split[1], ',');
			if (!rgb)
				return (free_splite(split), printerror_message("Invalid texture color!\n"));
			cub->color_ceiling = rgb_to_int(atoi(rgb2[0]), atoi(rgb2[1]),
					atoi(rgb2[2]));
			free_splite(rgb2);
		}
		free_splite(split);
	}
	else
		return (free_splite(split), printerror_message("Invalid texture color!\n"));
}
