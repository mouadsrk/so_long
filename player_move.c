#include"so_long.h"

void graphique_image(int i,int j ,t_vars *v)
{
	if(v->map[i][j] == 'P' && v->d == 0)
	{
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_s , j * 60, i * 60);
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_p , j * 60,i * 60);
	}
	else if(v->map[i][j] == 'P' && v->d == 1)
	{
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_s , j * 60, i * 60);
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_pl , j * 60,i * 60);
	}
	else if(v->map[i][j] == 'E' && v->c > 0)
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_e , j * 60,i * 60);
	else if(v->map[i][j] == 'E' && v->c == 0)
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_eo , j * 60,i * 60);
	if(v->map[i][j] == '0')
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_s , j * 60,i * 60);
	if(v->map[i][j] == '1')
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_w , j * 60,i * 60);
	if(v->map[i][j] == 'C')
	{
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_s , j * 60,i * 60);
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_c , j * 60,i * 60);
	}	
}


void display(t_vars *vars)
{
int i;
int j;

i = 0;
	while(vars->map[i])
		{
			j = 0;
			while(vars->map[i][j])
			{
				graphique_image(i, j ,vars);
				j++;
			}
			i++;
		}
}




void player_move(t_vars *vars, int keycode)
{
	t_h_v e_p;
	static int number;

	vars->c = number_of_element(&e_p , vars->map);
	
	if(keycode == 126)
		move_up(&e_p,vars ,&number);
	else if(keycode == 125)
		move_down(&e_p,vars,&number);
	else if(keycode == 123)
		move_left(&e_p,vars,&number);
	else if(keycode == 124)
		move_right(&e_p,vars,&number);
	if(keycode == 53)
		exit(0);
}



