#include"so_long.h"

void map_dimention(t_vars	*vars)
{
	vars->mh = 0;
	vars->mv = ft_strlen(vars->map[vars->mh]);
	while(vars->map[vars->mh])
		vars->mh++;
}

int	key_hook(int keycode, t_vars *vars)
{
	player_move(vars,keycode);
	return (0);
}

#include <time.h>

int timeout ( int seconds )
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}

    return  1;
}

void    mlx_graphique(t_vars    *vars)
{
	int		img_width;
	int		img_height;
	t_h_v 	p;

	vars->c = 1;
	vars->d = 0;
	img_width = 60;
	img_height = 60;
    vars->mlx = mlx_init();
    map_dimention(vars);
	vars->win = mlx_new_window(vars->mlx, vars->mv * 60, vars->mh * 60, "so long");
	vars->i_p =  mlx_xpm_file_to_image(vars->mlx,"player.xpm",&img_width,&img_height);
	vars->i_e =  mlx_xpm_file_to_image(vars->mlx,"nwall.xpm",&img_width,&img_height);
	vars->i_c =  mlx_xpm_file_to_image(vars->mlx,"b_wa.xpm",&img_width,&img_height);
	vars->i_w =  mlx_xpm_file_to_image(vars->mlx,"wall.xpm",&img_width, &img_height);
	vars->i_s =  mlx_xpm_file_to_image(vars->mlx,"deser.xpm",&img_width ,&img_height);
	vars->i_pl =  mlx_xpm_file_to_image(vars->mlx,"pl0.xpm",&img_width, &img_height);
	vars->i_eo =  mlx_xpm_file_to_image(vars->mlx,"open.xpm",&img_width ,&img_height);
	display(vars);
	mlx_hook(vars->win,2, 1L<<0,key_hook, vars);
	mlx_loop(vars->mlx);
}