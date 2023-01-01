#include"so_long.h"


int so_long()
{
    char **map;

    map = map_make(map);
    if(!map)
        return 0;
    player_move(map);
    return 1;
}
int main ()
{
	int i;
	i = so_long();
	if (i == 1)
		ft_printf("good map");
	else
		ft_printf("bad map");
}