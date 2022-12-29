#include "so_long.h"

int number_of_element(t_h_v *s ,char ** map)
{
	int i;
    int j;
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
			{
				s->h = i;
				s->v = j;
			}
			j++;
		}
		i++;
	}
	return (cont);
}

void set_element_position(char **map , int cont ,t_h_v *element_pos )
{
	int i;
	int j;

	j = 0;
	i = 0;
	cont = 0;
	while (map[i])
	{
		j= 0;
		while(map[i][j])
		{
			if(map[i][j] == 'C' || map[i][j] == 'E')
			{
				element_pos->eh[cont] = i;
				element_pos->ev[cont++] = j;
			}
			j++;
		}
		i++;
	}
	element_pos->eh[cont] = -1337;
	element_pos->ev[cont] = -1337;
}

int map_data(char ** m)
{
    size_t map_nodes;
	int cont;
	t_h_v player_position;
	t_h_v element_pos;
	int i;

	i = 0;
    map_nodes  = 0;
    while(m[map_nodes])
    	map_nodes++;
    map_nodes = (ft_strlen(m[0]) - 2) * (map_nodes - 2);
	cont = number_of_element(&player_position,m);
	element_pos.eh = malloc((cont + 1) * sizeof(int));
	 if(!element_pos.eh)
		return (ft_free(m,cont), 0);
	element_pos.ev = malloc((cont + 1) * sizeof(int));
	if(!element_pos.ev)
	 	return (ft_free(m,cont),0,free(element_pos.eh),element_pos.eh=NULL,0);
	  set_element_position(m,cont,&element_pos);
	while(element_pos.ev[i] != -1337)
	i++;
	
	return 1;
}