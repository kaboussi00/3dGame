/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:09:21 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/30 19:25:08 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (0);
	p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (0);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	return (free(s1), p);
}

int	ft_str_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char	**ft_free(char **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

void	free_map(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map[i] != NULL)
	{
		free(cub->map[i]);
		i++;
	}
	free(cub->map);
	i = 0;
	while (cub->copie[i] != NULL)
	{
		free(cub->copie[i]);
		i++;
	}
	free(cub->copie);
	i = 0;
	while (cub->all_map[i] != NULL)
	{
		free(cub->all_map[i]);
		i++;
	}
	free(cub->all_map);
}

void	initial_variable(t_cub *cub)
{
	cub->i = 0;
	cub->j = 0;
	cub->len = 0;
	cub->line = 0;
	cub->sprite = 0;
	cub->player.walk_direction = 0;
	cub->player.turn_direction = 0;
	cub->player.move_speed = 30.0;
	cub->player.rotation_angle = M_PI_2;
	cub->player.rotation_speed = 30.0 * (M_PI / 180);
	cub->fov = (60 * (M_PI / 180));
}
