#include "so_long.h"

void move_downP(int *c,t_h_v *e_p, t_vars *vars)
{
    int h;
    int v;

	h = e_p->ph;
	v = e_p->pv;
    if(vars->map[h + 1][v] == 'C' || vars->map[h + 1][v] == '0')
    {
        e_p->ph = h + 1;
        if(vars->map[h + 1][v] == 'C')
			*c -= 1;
        // vars->p_im = mlx_put_image_to_window(vars->mlx, vars->win,vars->i_s , v * 60,(h + 1) * 60);
        vars->p_im = mlx_put_image_to_window(vars->mlx, vars->win,vars->i_p , v * 60,(h + 1) * 60);
        vars->p_im = mlx_put_image_to_window(vars->mlx, vars->win,vars->i_s , v * 60,h * 60);
        vars->map[h][v] = '0';
        vars->map[h + 1][v] = 'P';
    }
    else if(vars->map[h + 1][v] == 'E' && *c == 0)
    {
        e_p->ph = h + 1;
        vars->map[h][v] = '0';
		exit(0);
    }
}


void move_down(int *c,t_h_v *e_p,t_vars *vars  , int *number)
{
	int h;
	int v;

	h = e_p->ph;
	v = e_p->pv;
	if(vars->map[h + 1][v] == '1')
		return ;
	if(vars->map[h + 1][v] == 'E' && *c != 0)
		return ;
	*number += 1;
    ft_printf("move down move number =%d \n",*number);
    move_downP(c, e_p,vars);
	
}