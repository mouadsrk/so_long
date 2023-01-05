#include"so_long.h"

// void graphique_image()
// {


// }


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
				if(vars->map[i][j] == 'P')
				{
					vars->p_im = mlx_put_image_to_window(vars->mlx, vars->win,vars->i_s , j * 60,i * 60);
					vars->p_im = mlx_put_image_to_window(vars->mlx, vars->win,vars->i_p , j * 60,i * 60);
				}
				else if(vars->map[i][j] == 'E')
				{
					vars->p_im = mlx_put_image_to_window(vars->mlx, vars->win,vars->i_s , j * 60,i * 60);
					vars->p_im = mlx_put_image_to_window(vars->mlx, vars->win,vars->i_e , j * 60,i * 60);
				}
				else if(vars->map[i][j] == '0')
					vars->p_im = mlx_put_image_to_window(vars->mlx, vars->win,vars->i_s , j * 60,i * 60);
				else if(vars->map[i][j] == '1')
					vars->p_im = mlx_put_image_to_window(vars->mlx, vars->win,vars->i_w , j * 60,i * 60);
				else if(vars->map[i][j] == 'C')
				{
					vars->p_im = mlx_put_image_to_window(vars->mlx, vars->win,vars->i_s , j * 60,i * 60);
					vars->p_im = mlx_put_image_to_window(vars->mlx, vars->win,vars->i_c , j * 60,i * 60);
				}
				j++;
			}
			i++;
		}
}




void player_move(t_vars *vars, int keycode)
{
	t_h_v e_p;
	int c;
	static int number;

	c = number_of_element(&e_p , vars->map);
	
	if(keycode == 126)
		move_up(&c,&e_p,vars ,&number);
	else if(keycode == 125)
		move_down(&c,&e_p,vars,&number);
	else if(keycode == 123)
		move_left(&c,&e_p,vars,&number);
	else if(keycode == 124)
		move_right(&c,&e_p,vars,&number);
	if(keycode == 53)
		exit(0);
}



