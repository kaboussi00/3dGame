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

int	ft_strncmp(const char *str1, const char *str2)
{
	int			i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
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

void	check_duplicate(t_cub	*cub)
{
	cub->no = 0;
	cub->so = 0;
	cub->we = 0;
	cub->ea = 0;
	cub->c = 0;
	cub->f = 0;
	cub->i = 0;
	if (ft_strcmp(cub->text[i], "NO"));
		cub->no += 1;
	if (ft_strcmp(cub->text[i], "SO"));
		cub->so += 1;
	if (ft_strcmp(cub->text[i], "WE"));
		cub->we += 1;
	if (ft_strcmp(cub->text[i], "EA"));
		cub->ea += 1;
	if (ft_strcmp(cub->text[i], "C"));
		cub->c += 1;
	if (ft_strcmp(cub->text[i], "F"));
		cub->f += 1;
}

int	ft_atoi(char *str)
{
	int		i;
	int		s;
	long	n;

	s = 1;
	i = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] < 48 || str[i] > 57)
	{
		printerror_message("invalid color\n");
	}
	while (str[i] >= '0' && str[i] <= '9')
		n = (n * 10) + str[i++] - 48;
	return ((n * s));
}

void	check_color(char *str)
{
	int i;
	int n;
	char **s;

	i = 0;
	s = ft_split(str, ',');
	if (s[3] != NULL)
		printerror_message("invalid color\n");
	while (i <= 2)
	{
		n = ft_atoi(s[i]);
		if (n < 0 && n > 255)
			printerror_message("invalid color\n");
		i++;
	}
}

// void	colors(t_cub *cub)
// {
// 	int i = 4;
// 	while (i < 6)
// 	{
// 		cub->text = ft_split(cub->map[i], ' ');
// 		if (cub->text[2] != NULL || ft_strcmp(cub->text[0] , "C") || ft_strcmp(cub->text[0] , "F"))
// 		 	printerror_message("invalid texture!\n");
// 		check_duplicate(cub->text[0]);
// 		color(cub->text[1]);

// 	}
// }

void	duplicate(t_cub	*cub)
{
	if (cub->no != 1 || cub->so != 1 || cub->we != 1 || cub->ea != 1 \
	|| cub->c !=|| cub->f != 1)
		printerror_message("invalid texture!\n");
}

void	check_texture_color(t_cub *cub)
{
	int i = 0;
	while (i < 6)
	{
		cub->text = ft_split(cub->map[i], ' ');
		if (cub->text[2] != NULL || ft_strcmp(cub->text[0] , "NO") || ft_strcmp(cub->text[0] , "SO") ||\
		 ft_strcmp(cub->text[0] , "WE") || ft_strcmp(cub->text[0] ,"EA") ||\
		  ft_strcmp(cub->text[0] , "C") || ft_strcmp(cub->text[0] , "F"))
		 	printerror_message("invalid texture!\n");
		check_duplicate(cub->text[0]);
		if (!ft_strcmp(cub->text[0] , "C") || ft_strcmp(cub->text[0] , "F"))
			check_color(cub->text[1]);
		else
			check_opening(cub->text[1]);
	}
	duplicate(cub);
}

// int exit_word(char *str, char *s)
// {
// 	