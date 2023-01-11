/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_graphiqueb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:01:30 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/11 23:23:07 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	map_dimention(t_vars	*vars)
{
	vars->mh = 0;
	vars->mv = ft_strlen(vars->map[vars->mh]);
	while (vars->map[vars->mh])
		vars->mh++;
}

int	key_hook(int keycode, t_vars *vars)
{
	player_moveb(vars, keycode);
	return (0);
}

int	ft_close(void)
{
	exit (0);
}

void	file_to_imageb(t_vars *v)
{
	int		i_w;
	int		i_h;

	i_w = 60;
	i_h = 60;
	v->i_p = mlx_xpm_file_to_image(v->mlx, "textures/player.xpm", &i_w, &i_h);
	v->i_e = mlx_xpm_file_to_image(v->mlx, "textures/exit.xpm", &i_w, &i_h);
	v->i_c = mlx_xpm_file_to_image(v->mlx, "textures/b_wa.xpm", &i_w, &i_h);
	v->i_w = mlx_xpm_file_to_image(v->mlx, "textures/wall.xpm", &i_w, &i_h);
	v->i_s = mlx_xpm_file_to_image(v->mlx, "textures/deser.xpm", &i_w, &i_h);
	v->i_pl = mlx_xpm_file_to_image(v->mlx, "textures/pl0.xpm", &i_w, &i_h);
	v->i_eo = mlx_xpm_file_to_image(v->mlx, "textures/eopen.xpm", &i_w, &i_h);
	v->i_r = mlx_xpm_file_to_image(v->mlx, "textures/enemie.xpm", &i_w, &i_h);
	v->i_rl = mlx_xpm_file_to_image(v->mlx, "textures/enemiel.xpm", &i_w, &i_h);
}

void	mlx_graphiqueb(t_vars	*v)
{
	v->c = 1;
	v->d = 0;
	v->rd = 0;
	v->number = 0;
	v->mlx = mlx_init();
	map_dimention(v);
	v->win = mlx_new_window(v->mlx, v->mv * 60, (v->mh + 1) * 60, "so long");
	file_to_imageb(v);
	if (!v->i_pl || !v->i_s || !v->i_w || !v->i_r || !v->i_rl
		||!v->i_c || !v->i_e || !v->i_p || !v->i_eo)
		return (ft_printf("Error\ninvalide image"), ft_free(v->map, v->mh));
	display(v);
	mlx_loop_hook(v->mlx, display_enemie, v);
	mlx_hook(v->win, 17, 1L << 0, ft_close, v);
	mlx_hook(v->win, 2, 1L << 0, key_hook, v);
	mlx_loop(v->mlx);
}
