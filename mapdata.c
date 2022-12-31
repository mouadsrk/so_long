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
			if(map[i][j] == 'C')
				cont++;
			else if(map[i][j] == 'P')
			{
				s->ph = i;
				s->pv = j;
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
			if(map[i][j] == 'C')
				element_pos->h[cont] = i;
			if(map[i][j] == 'C')	
				element_pos->v[cont++] = j;
			if(map[i][j] == 'E')
				element_pos->ph= i;
			if(map[i][j] == 'E')
				element_pos->pv = j;
			j++;
		}
		i++;
	}
	element_pos->h[cont] = -1337;
	element_pos->v[cont] = -1337;
}

int map_data(char ** m, int *i)
{
    size_t map_nodes;
	int cont;
	t_h_v player_position;
	t_h_v el_po;
	int c = 0;
    map_nodes  = 0;
    while(m[map_nodes])
    	map_nodes++;
    map_nodes = (ft_strlen(m[0]) - 2) * (map_nodes - 2);
	cont = number_of_element(&player_position,m);
	el_po.h = malloc((cont + 1) * sizeof(int));
	 if(!el_po.h)
		return (0);
	el_po.v = malloc((cont + 1) * sizeof(int));
	if(!el_po.v)
	 	return (free(el_po.h),el_po.h=NULL,0);
	set_element_position(m,cont,& el_po);
	*i = player_range(el_po,player_position,map_nodes, m);
	if(*i == 0)
	{
		return (free(el_po.h), el_po.h = NULL, free(el_po.v), el_po.v = NULL, 0);
	}
	return (free(el_po.h), el_po.h = NULL, free(el_po.v), el_po.v = NULL,1);
}