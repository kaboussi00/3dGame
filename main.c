#include "cub3d.h"

int main(int ac, char **av)
{
    t_cub cub;
    int i = 0;

    if (ac != 2)
        printerror_message("invalid arg\n");
    parse(&cub, av[1]);
    i = 0;
    while(cub.copie[i])
    {
        printf("after check {%s}\n", cub.copie[i++]);
    }
}
