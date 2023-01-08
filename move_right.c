#include "so_long.h"

void move_rightP(t_h_v *e_p, t_vars *vars, int number)
{
    int h;
    int v;
    char *n;

    n = ft_itoa(number);
	h = e_p->ph;
	v = e_p->pv;
    if(vars->map[h][v + 1] == 'C' || vars->map[h][v + 1] == '0')
    {
        vars->d =0;
        e_p->pv = v + 1;
        if(vars->map[h][v + 1] == 'C')
			vars->c -= 1;
       vars->map[h][v] = '0';
        vars->map[h][v + 1] = 'P';
        mlx_clear_window(vars->mlx,vars->win);
       mlx_string_put(vars->mlx,vars->win,0,(vars->mh - 1) *60,91422,n);
        display(vars);
        free(n);
    }
    else if(vars->map[h][v + 1] == 'E' && vars->c == 0)
    {
        e_p->pv = v + 1;
        vars->map[h][v] = '0';
        exit(0); 
    }

}


void move_right(t_h_v *e_p,t_vars *vars  , int *number)
{
	int h;
	int v;

	h = e_p->ph;
	v = e_p->pv;
	if(vars->map[h][v + 1] == '1')
		return ;
	if(vars->map[h][v + 1] == 'E' && vars->c != 0)
		return ;
    *number += 1;
    move_rightP( e_p,vars,*number);
}