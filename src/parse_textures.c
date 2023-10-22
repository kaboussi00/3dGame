/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:54:55 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/22 14:55:53 by rel-isma         ###   ########.fr       */
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

void	parse_texture_path(t_cub *cub, char *line)
{
	char	**split;
	char	**rgb;
	char	*texture_path;
	char	**rgb2;
	int		i;

	split = ft_split(line, ' ');
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
		else if (ft_strcmp(split[0], "F") == 0)
		{
			rgb = ft_split(split[1], ',');
			cub->color_floor = rgb_to_int(atoi(rgb[0]), atoi(rgb[1]),
					atoi(rgb[2]));
		}
		else if (ft_strcmp(split[0], "C") == 0)
		{
			rgb2 = ft_split(split[1], ',');
			cub->color_ceiling = rgb_to_int(atoi(rgb2[0]), atoi(rgb2[1]),
					atoi(rgb2[2]));
		}
		else
		{
			free(texture_path);
			printerror_message("Invalid texture type!\n");
		}
		i = 0;
		while (split[i] != NULL)
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
	else
		printerror_message("Invalid texture line!\n");
}
