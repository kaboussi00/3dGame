#include "cub3d.h"

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
		printerror_message("can't open file1\n");
    close(fd);
}
