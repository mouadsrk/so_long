#include "so_long.h"

char *player_position(char **s ,char ** map)
{
	size_t i;
    size_t j;
	int cont;

	cont = 0; 
	i = 0;
	j = 0;
	while (map[i])
	{
		j= 0;
		while(map[i][j])
		{
			if(map[i][j] == 'C' || map[i][j] == 'E')
				cont++;
			else if(map[i][j] == 'P')
				*s = map[i][j];
			j++;
		}
		i++;
	}
	return (cont);
} 




int map_path(char ** m)
{
    size_t i;
    size_t n;
	int cont;
	char *s;
	char *g;

    i = 0;
    while(m[i])
    	i++;
    n = ft_strlen(m[i]) * i;
	i =0;
	cont = player_position(&s,m);
}