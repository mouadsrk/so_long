#include "so_long.h"

void move_rightP(int *c,t_h_v *e_p, char **map)
{
    int h;
    int v;

	h = e_p->ph;
	v = e_p->pv;
    if(map[h][v + 1] == 'C' || map[h][v + 1] == '0')
    {
        e_p->pv = v + 1;
        if(map[h][v + 1] == 'C')
			*c -= 1;
        map[h][v] = '0';
        map[h][v + 1] = 'P';
    }
    else if(map[h][v + 1] == 'E' && *c == 0)
    {
        e_p->pv = v + 1;
        map[h][v] = '0';
        exit(0); 
    }

}


void move_right(int *c,t_h_v *e_p, char **map, int *number)
{
	int h;
	int v;

	h = e_p->ph;
	v = e_p->pv;
	if(map[h][v + 1] == '1')
		return ;
	if(map[h][v + 1] == 'E' && *c != 0)
		return ;
    *number += 1;
    ft_printf("move right move number = %d \n",*number);
    move_rightP(c, e_p,map);
}