#include "so_long.h"

void move_downP(t_h_v *e_p, t_vars *vars, int number)
{
    int h;
    int v;
    char *n;

    n = ft_itoa(number);
	h = e_p->ph;
	v = e_p->pv;
    if(vars->map[h + 1][v] == 'C' || vars->map[h + 1][v] == '0')
    {
        e_p->ph = h + 1;
        if(vars->map[h + 1][v] == 'C')
			vars->c -= 1;
        vars->map[h][v] = '0';
        vars->map[h + 1][v] = 'P';
        mlx_clear_window(vars->mlx,vars->win);
        mlx_string_put(vars->mlx,vars->win,0,(vars->mh - 1) *60,91422,n);
        free(n);
        display(vars);
    }
    else if(vars->map[h + 1][v] == 'E' && vars->c == 0)
    {
        e_p->ph = h + 1;
        vars->map[h][v] = '0';
		exit(0);
    }
}


void move_down(t_h_v *e_p,t_vars *vars  , int *number)
{
	int h;
	int v;

	h = e_p->ph;
	v = e_p->pv;
	if(vars->map[h + 1][v] == '1')
		return ;
	if(vars->map[h + 1][v] == 'E' && vars->c != 0)
		return ;
	*number += 1;
    // ft_printf("move down move number =%d \n",*number);
    move_downP(e_p,vars,*number);
}