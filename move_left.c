#include "so_long.h"

void move_leftP(int *c,t_h_v *e_p, char **map)
{
    int h;
    int v;

	h = e_p->ph;
	v = e_p->pv;
    if(map[h][v - 1] == 'C' || map[h][v - 1] == '0')
    {
        e_p->pv = v - 1;
        if(map[h][v - 1] == 'C')
			*c -= 1;
        map[h][v] = '0';
        map[h][v - 1] = 'P';
    }
    else if(map[h][v - 1] == 'E' && *c == 0)
    {
        e_p->pv = v - 1;
        map[h][v] = '0';
        // printf("%c\n",map[h - 1][v]); 
    }

}


void move_left(int *c,t_h_v *e_p, char **map)
{
	int h;
	int v;

	h = e_p->ph;
	v = e_p->pv;
	if(map[h][v - 1] == '1')
		return ;
	if(map[h][v - 1] == 'E' && *c != 0)
		return ;
    if (map[h][v] == 'P')
        move_leftP(c, e_p,map);
    else if(map[h][v] == 'E' && *c == 0)
    {
        e_p->pv -= 1;
        map[h][v - 1] = 'P'; 
    }
}