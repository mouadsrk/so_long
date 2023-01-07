#include "so_long.h"


int number_of_element(t_h_v *el_po ,char ** map)
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
				el_po->ph = i;
				el_po->pv = j;
			}
			j++;
		}
		i++;
	}
	return (cont);
}

void set_element_position(char **map , int cont ,t_h_v *el_po )
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
				el_po->h[cont] = i;
			if(map[i][j] == 'C')	
				el_po->v[cont++] = j;
			if(map[i][j] == 'E')
				el_po->eh= i;
			if(map[i][j] == 'E')
				el_po->ev = j;
			j++;
		}
		i++;
	}
	el_po->h[cont] = -1337;
	el_po->v[cont] = -1337;
}

int map_data(char ** m)
{
    size_t map_nodes;
	int cont;
	t_h_v el_po;

    map_nodes  = 0;
    while(m[map_nodes])
    	map_nodes++;
    map_nodes = (ft_strlen(m[0]) - 2) * (map_nodes - 2);
	cont = number_of_element(&el_po,m);
	el_po.h = malloc((cont + 1) * sizeof(int));
	 if(!el_po.h)
		return (0);
	el_po.v = malloc((cont + 1) * sizeof(int));
	if(!el_po.v)
	 	return (free(el_po.h),el_po.h=NULL,0);
	set_element_position(m,cont,& el_po);
	if(player_range(el_po,map_nodes, m) == 0)
	{
		ft_printf("Error\nno valid path in the map.\n");
		return (free(el_po.h), el_po.h = NULL, free(el_po.v), el_po.v = NULL, 0);
	}
	return (free(el_po.h), el_po.h = NULL, free(el_po.v), el_po.v = NULL,1);
}