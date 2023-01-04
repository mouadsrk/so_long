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
	player_move(vars->map,keycode);
	return (0);
}

void    mlx_graphique(t_vars    vars)
{
    vars.mlx = mlx_init();
    map_dimention(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.mv * 50, vars.mh * 50, "so long");
	mlx_key_hook(vars.win,key_hook, &vars);
	mlx_loop(vars.mlx);

}