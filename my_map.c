/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:04:50 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/14 12:50:44 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// char	*ft_strdup(const char *str)
// {
// 	size_t	len;
// 	char	*p;
// 	int		i;

// 	len = 0;
// 	while (str[len])
// 		len++;
// 	p = malloc((len + 1) * sizeof(char));
// 	if (!p)
// 		return (NULL);
// 	i = 0;
// 	while (str[i])
// 	{
// 		p[i] = str[i];
// 		i++;
// 	}
// 	return (p);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (0);
	p = (char *)malloc (ft_strlen (s1) + ft_strlen (s2) + 1);
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
	return (p);
}

char	*charge(char c, int len)
{
	int		i;
	char	*p;

	i = 0;
	p = malloc((len + 1) * sizeof(char));
	if (!p || len == 0)
		return (NULL);
	while (i < len)
		p[i++] = c;
	p[i] = '\0';
	return (p);
}

int	ft_str_line(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

void copy_map(t_cub *cub)
{
    int size;
    int l;
    int x;
    int y;
    char *str;

    cub->i = 6;
    cub->j = 0;
    cub->map = malloc(sizeof(char *) * (cub->line - 5));
    if (!cub->map)
        return ;
    printf("cub->len avant  : %d\n", cub->len);
    while (cub->i < cub->line)
    {
        cub->map[cub->j] = malloc(sizeof(char) * (cub->len + 1));
        size = ft_str_line(cub->all_map[cub->i]);
        x = 0;
        y = 0;
        l = cub->len - size;
        while (cub->all_map[cub->i][x] && cub->all_map[cub->i][x] != '\n')
        {
            cub->map[cub->j][y++] = cub->all_map[cub->i][x++];
        }
        cub->map[cub->j][y] = '\0';
        printf("????????%d\n", size);
        printf("cub->len  : %d\n", cub->len);
        if (size < cub->len)
        {
            puts("p");
            str = charge(' ', l);
            cub->map[cub->j] = ft_strjoin(cub->map[cub->j], str);
            free (str);
            str = NULL;
        }
        cub->i++;
        cub->j++;
    }
    cub->map[cub->j] = NULL;
}

void	check_not_char(t_cub *cub)
{
	cub->i = 0;
	while (cub->i < cub->line)
	{
		cub->j = 0;
		while (cub->j < cub->len)
		{
			if (!ft_strchr("10N ", cub->map[cub->i][cub->j]) || !ft_strchr("10S ", cub->map[cub->i][cub->j]\
            || !ft_strchr("10E ", cub->map[cub->i][cub->j])) || !ft_strchr("10W ", cub->map[cub->i][cub->j]))
				printerror_message("invalid character\n");
			cub->j++;
		}
		cub->i++;
	}
}

void check_valid_walls(t_cub    *cub)
{
    cub->i = 0;
    while (cub->i < cub->line)
    {
        cub->j = 0;
        while (cub->j < cub->len)
        {
            
        }
        
    }
}

void check_space(t_cub  *cub)
{
    cub->i = 0;
    cub->j = 0;
    if (cub->map[cub->i][0] != '1' || cub->map[cub->i][0] != ' ')
        printerror_message("walls problem2\n");
    while (cub->map[cub->i][cub->j] == ' ')
    {
        cub->j++;
        if (cub->map[cub->i][cub->j+1] != 1)
            printerror_message("walls problem2\n");
    }
    
        
}

void	wallsbonus2(t_cub *cub)
{
	cub->i = 0;
	while (cub->i < cub->line)
	{
		if (cub->map[cub->i][0] != '1' || cub->map[cub->i][cub->len - 1] != '1')
			printerror_message("walls problem2\n");
		cub->i++;
	}
    while (cub->map[0][cub->i] && cub->map[0][cub->i] != '\n')
    {
    	if (cub->map[0][cub->i] != '1' || \
    	cub->map[cub->line - 1][cub->i] != '1')
    		printerror_message("walls problem1\n");
    	cub->i++;
    }
}

// while (var->map[0][var->i] && var->map[0][var->i] != '\n')
// {
// 	if (var->map[0][var->i] != '1' || \
// 	var->map[var->lines - 1][var->i] != '1')
// 		printerror_message("walls problem1\n");
// 	var->i++;
// }