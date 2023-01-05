#include "so_long.h"

void move_rightP(int *c,t_h_v *e_p, t_vars *vars)
{
    int h;
    int v;

	h = e_p->ph;
	v = e_p->pv;
    if(vars->map[h][v + 1] == 'C' || vars->map[h][v + 1] == '0')
    {
        e_p->pv = v + 1;
        if(vars->map[h][v + 1] == 'C')
			*c -= 1;
        // vars->p_im = mlx_put_image_to_window(vars->mlx, vars->win,vars->i_s , (v + 1) * 60,h * 60);
        vars->p_im = mlx_put_image_to_window(vars->mlx, vars->win,vars->i_p , (v + 1) * 60,h  * 60);
         vars->p_im = mlx_put_image_to_window(vars->mlx, vars->win,vars->i_s , v * 60,h * 60);
       vars->map[h][v] = '0';
        vars->map[h][v + 1] = 'P';
    }
    else if(vars->map[h][v + 1] == 'E' && *c == 0)
    {
        e_p->pv = v + 1;
        vars->map[h][v] = '0';
        exit(0); 
    }

}


void move_right(int *c,t_h_v *e_p,t_vars *vars  , int *number)
{
	int h;
	int v;

	h = e_p->ph;
	v = e_p->pv;
	if(vars->map[h][v + 1] == '1')
		return ;
	if(vars->map[h][v + 1] == 'E' && *c != 0)
		return ;
    *number += 1;
    ft_printf("move right move number = %d \n",*number);
    move_rightP(c, e_p,vars);
}