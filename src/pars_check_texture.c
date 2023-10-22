/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:09:45 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/22 14:57:01 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"



void	check_duplicate(t_cub *cub, char *text)
{
	if (!ft_strcmp(text, "NO"))
		cub->no += 1;
	if (!ft_strcmp(text, "SO"))
		cub->so += 1;
	if (!ft_strcmp(text, "WE"))
		cub->we += 1;
	if (!ft_strcmp(text, "EA"))
		cub->ea += 1;
	if (!ft_strcmp(text, "C"))
		cub->c += 1;
	if (!ft_strcmp(text, "F"))
		cub->f += 1;
}

void	check_color(char *str)
{
	int		i;
	int		n;
	char	**s;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',' && str[i + 1] == '\0')
			printerror_message("invalid color\n");
		i++;
	}
	i = 0;
	s = ft_split(str, ',');
	if (s[0] == NULL || s[1] == NULL || s[2] == NULL || s[3] != NULL)
		printerror_message("invalid color\n");
	while (i <= 2)
	{
		n = ft_atoi(s[i]);
		if (n < 0 || n > 255)
			printerror_message("invalid color\n");
		i++;
	}
}

void	duplicate(t_cub *cub)
{
	if (cub->no != 1 || cub->so != 1 || cub->we != 1 || cub->ea != 1
		|| cub->c != 1 || cub->f != 1)
		printerror_message("invalid texture7!\n");
}

void	check_texture_color(t_cub *cub)
{
	int	i;

	i = 0;
	cub->no = 0;
	cub->so = 0;
	cub->we = 0;
	cub->ea = 0;
	cub->c = 0;
	cub->f = 0;
	while (i < 6)
	{
		cub->text = ft_split(cub->all_map[i], ' ');
		if (cub->text[2] != NULL || (ft_strcmp(cub->text[0], "NO")
				&& ft_strcmp(cub->text[0], "SO") && ft_strcmp(cub->text[0],
					"WE") && ft_strcmp(cub->text[0], "EA")
				&& ft_strcmp(cub->text[0], "C") && ft_strcmp(cub->text[0],
					"F")))
			printerror_message("invalid texture!\n");
		check_duplicate(cub, cub->text[0]);
		if (!ft_strcmp(cub->text[0], "C") || !ft_strcmp(cub->text[0], "F"))
			check_color(cub->text[1]);
		else
			check_opening(cub->text[1]);
		i++;
	}
	duplicate(cub);
}
