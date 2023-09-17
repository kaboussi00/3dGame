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

char	*charge_space(char c, int len)
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

void	copy_map(t_cub *cub)
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
        if (size < cub->len)
        {
            str = charge_space(' ', l);
            cub->map[cub->j] = ft_strjoin(cub->map[cub->j], str);
            free (str);
            str = NULL;
        }
        cub->i++;
        cub->j++;
    }
    cub->map[cub->j] = NULL;
}

int	charge_1(t_cub *cub, t_data p)
{
	t_data	data;

	if (cub->map[p.y][p.x] == 'W' || cub->map[p.x][p.y] == 'A'\
    || cub->map[p.y][p.x] == 'S' || cub->map[p.x][p.y] == 'D')
	{
		cub->o++;
		cub->map[p.y][p.x] = '1';
		return (0);
	}
	if (p.y < 0 || p.y >= cub->line || p.x < 0 || p.x >= cub->len
		|| cub->map[p.y][p.x] == '1')
		return (0);
	cub->map[p.y][p.x] = '1';
	data.x = p.x;
	data.y = p.y + 1;
	charge_1(cub, data);
	data.x = p.x;
	data.y = p.y - 1;
	charge_1(cub, data);
	data.x = p.x - 1;
	data.y = p.y;
	charge_1(cub, data);
	data.x = p.x + 1;
	data.y = p.y;
	charge_1(cub, data);
	return (1);
}

void	check_walls(t_cub *cub)
{
	t_data	p;

	cub->o = 0;
	p.y = cub->pos_i;
	p.x = cub->pos_j;
	charge_1(cub, p);
	cub->i = -1;
	while (++cub->i < cub->line)
	{
		cub->j = -1;
		while (++cub->j < cub->len)
		{
			if (cub->o != 1 || cub->o != ' ')
				printerror_message("invalid map !\n");
		}
	}
	ft_free(cub->map);
}
