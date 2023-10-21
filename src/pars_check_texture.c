/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:09:45 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/21 15:47:51 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_duplicate(t_cub	*cub, char *text)
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
	int i;
	int n;
	char **s;

	i = 0;
	s = ft_split(str, ',');	
	if (s[0]== NULL || s[1] == NULL || s[2]== NULL || s[3] != NULL)
		printerror_message("invalid color\n");
	while (i <= 2)
	{
		n = ft_atoi(s[i]);
		if (n < 0 || n > 255)
			printerror_message("invalid color\n");
		i++;
	}
}

void	duplicate(t_cub	*cub)
{
	if (cub->no != 1 || cub->so != 1 || cub->we != 1 || cub->ea != 1 \
	|| cub->c != 1 || cub->f != 1)
		printerror_message("invalid texture7!\n");
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

void parse_texture_path(t_cub *cub, char *line)
{
    char **split = ft_split(line, ' ');
    if (split && split[1] && split[2] == NULL)
    {
        char *texture_path = ft_strdup(split[1]);
        if (ft_strcmp(split[0], "NO") == 0)
            cub->north_texture_path = texture_path;
        else if (ft_strcmp(split[0], "SO") == 0)
            cub->south_texture_path = texture_path;
        else if (ft_strcmp(split[0], "WE") == 0)
            cub->west_texture_path = texture_path;
        else if (ft_strcmp(split[0], "EA") == 0)
            cub->east_texture_path = texture_path;
        else
        {
            free(texture_path);
            printerror_message("Invalid texture type!\n");
        }

        // Free individual strings
        for (int i = 0; split[i] != NULL; i++) {
            free(split[i]);
        }

        // Free the split array itself
        free(split);
    }
    else
    {
        printerror_message("Invalid texture line!\n");
    }
}


// void	check_texture_color(t_cub *cub)
// {
// 	int i = 0;
// 	cub->no = 0;
// 	cub->so = 0;
// 	cub->we = 0;
// 	cub->ea = 0;
// 	cub->c = 0;
// 	cub->f = 0;
// 	while (i < 6)
// 	{
// 		cub->text = ft_split(cub->all_map[i], ' ');
// 		// printf("texture == [%s] /// i == [%d]\n", cub->text[1], i);
// 		if (cub->text[2] != NULL || (ft_strcmp(cub->text[0] , "NO") && ft_strcmp(cub->text[0] , "SO") &&\
// 		 ft_strcmp(cub->text[0] , "WE") && ft_strcmp(cub->text[0] ,"EA") &&\
// 		  ft_strcmp(cub->text[0] , "C") && ft_strcmp(cub->text[0] , "F")))
// 		 	printerror_message("invalid texture!\n");
// 		check_duplicate(cub, cub->text[0]);
// 		if (!ft_strcmp(cub->text[0] , "C") || !ft_strcmp(cub->text[0] , "F"))
// 			check_color(cub->text[1]);
// 		else {
// 			check_opening(cub->text[1]);
// 		}
// 		i++;
// 	}
// 	duplicate(cub);
// }


