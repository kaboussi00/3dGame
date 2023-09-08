#include "cub3d.h"

void	printerror_message(char *str)
{
	write (1, "Error\n", 6);
	ft_putstr(str);
	exit(0);
}

void	ft_putstr(char *s)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	check_extension(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	if (str[i] != 'b')
		printerror_message("extension error\n");
	if (str[i - 1] != 'u')
		printerror_message("extension error\n");
	if (str[i -2] != 'c' )
		printerror_message("extension error\n");
	if (str[i - 3] != '.')
		printerror_message("extension error\n");
}

int	check_opening(char *file)
{
	int	fd;

	fd = open(file, O_RDWR);
	if (fd == -1)
		printerror_message("can't open file\n");
	return (fd);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return(i);
}

int	ft_strncmp(const char *str1, const char *str2, int n)
{
	int			i;

	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void    count_map(char *file)
{
    int i;
    t_cub   *cub;
    char* line_readed;

    i = 0;
    cub->fd=open(file, O_RDWR);
    if (!fd)
        printerror_message("can't open file\n");
    line_readed = get_next_line(cub->fd);
    while (line_readed)
    {
        if (!line_readed)
            printerror_message("empty file\n");
        else
        {
            if (line_readed[0] != '\n') 
                cub->line++;
        }
        free(line_readed);
        line_readed = get_next_line(cub->fd);
    }
}

void press_map(t_cub *cub)
{
    char *read_line;

    cub->map = malloc((sizeof(char *)) * (cub->line + 1));
    if  (cub->map)
        retun (0);
    cub->i = 0;
    read_line=get_next_line(cub->fd);
    while (cub->i < cub->line)
    {
        if (read_line[0] != '\n')
            cub->map[cub->i] = read_line;
        read_line=get_next_line(cub->fd);
    }
    cub->map[i] = NULL;
}

