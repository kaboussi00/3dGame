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

void	check_opening(char *file)
{
	int	fd;

	fd = open(file, O_RDWR);
	if (fd == -1)
		printerror_message("can't open file\n");
    close(fd);
}

void    count_map(t_cub *cub, char *file)
{
    char* line_readed;

    cub->fd=open(file, O_RDWR);
    if (cub->fd < 0)
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
    close(cub->fd);
}

void press_map(t_cub *cub, char *file)
{
    char *read_line;

    cub->fd=open(file, O_RDWR);
    if (cub->fd < 0)
        printerror_message("can't open file\n");
    cub->map = malloc((sizeof(char *)) * (cub->line + 1));
    if  (!cub->map)
        return ;
    cub->i = 0;
    printf("{fd : %d}\n", cub->fd);
    read_line = get_next_line(cub->fd);
    printf("{%s}\n", read_line);
    while (read_line)
    {
        if (read_line[0] != '\n')
            cub->map[cub->i++] = read_line;
        read_line=get_next_line(cub->fd);
    }
    cub->map[cub->i] = NULL;
}

int main(int ac, char **av)
{
    t_cub cub;

    if (ac != 2)
        printerror_message("invalid arg\n");
    check_extension(av[1]);
    check_opening(av[1]);
    count_map(&cub, av[1]);
    press_map(&cub, av[1]);
    check_texture_color(&cub);
    puts("1");
    copy_map(&cub);
    puts("2");
    // while (cub->map[i])
    // {
    //     puts("e");
    //     printf("map : %s\n", cub.map[i]);
    //     i++;
    //     puts("v");
    // }
    int i = 0;
    while(cub.map[i])
    {
        printf("%s\n", cub.map[i++]);
    }
}
