#include"so_long.h"

void map_dimention(t_vars	*vars)
{
	vars->mh = 0;
	vars->mv = ft_strlen(vars->map[vars->mh]);
	while(vars->map[vars->mh])
		vars->mh++;
		vars->mh++;
}

int	key_hook(int keycode, t_vars *vars)
{
	player_move(vars,keycode);
	return (0);
}

int	ft_close(int keycode, t_vars *vars)
{
	exit (0);
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
		if(!vars->i_pl || !vars->i_s || !vars->i_w ||
			 !vars->i_c || !vars->i_e || !vars->i_p || !vars->i_eo)
			return(ft_printf("Error\n invalide image\n"),ft_free(vars->map,vars->mh));
	display(vars);
	mlx_string_put(vars->mlx,vars->win,0,(vars->mh - 1) *60,91422,"0");
	mlx_hook(vars->win, 17, 1L<<0, ft_close, vars);
	mlx_hook(vars->win,2, 1L<<0,key_hook, vars);
	mlx_loop(vars->mlx);
}