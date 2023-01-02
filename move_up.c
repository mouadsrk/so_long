#include "so_long.h"



void move_upP(int *c,t_h_v *e_p, char **map)
{
    int h;
    int v;

	h = e_p->ph;
	v = e_p->pv;
    if(map[h - 1][v] == 'C' || map[h - 1][v] == '0')
    {
        e_p->ph = h - 1;
        if(map[h - 1][v] == 'C')
			*c -= 1;
        map[h][v] = '0';
        map[h - 1][v] = 'P';
    }
    else if(map[h - 1][v] == 'E' && *c == 0)
    {
        e_p->ph = h - 1;
        map[h][v] = '0';
        printf("%c\n",map[h - 1][v]); 
    }

}


void move_up(int *c,t_h_v *e_p, char **map)
{
	int h;
	int v;

	h = e_p->ph;
	v = e_p->pv;
    
	if(map[h - 1][v] == '1')
		return ;
	if(map[h - 1][v] == 'E' && *c != 0)
		return ;
    if (map[h][v] == 'P')
        move_upP(c, e_p,map);
    else if(map[h][v] == 'E' && *c == 0)
    {
        e_p->ph -= 1;
        map[h - 1][v] = 'P'; 
    }
}