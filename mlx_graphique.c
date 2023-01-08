/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_graphique.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:01:30 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/08 20:21:45 by mserrouk         ###   ########.fr       */
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
	player_move(vars, keycode);
	return (0);
}

int	ft_close(int keycode, t_vars *vars)
{
	exit (0);
}

void	file_to_image(t_vars *v, int i_w, int i_h)
{
	v->i_p = mlx_xpm_file_to_image(v->mlx, "player.xpm", &i_w, &i_h);
	v->i_e = mlx_xpm_file_to_image(v->mlx, "nwall.xpm", &i_w, &i_h);
	v->i_c = mlx_xpm_file_to_image(v->mlx, "b_wa.xpm", &i_w, &i_h);
	v->i_w = mlx_xpm_file_to_image(v->mlx, "wall.xpm", &i_w, &i_h);
	v->i_s = mlx_xpm_file_to_image(v->mlx, "deser.xpm", &i_w, &i_h);
	v->i_pl = mlx_xpm_file_to_image(v->mlx, "pl0.xpm", &i_w, &i_h);
	v->i_eo = mlx_xpm_file_to_image(v->mlx, "open.xpm", &i_w, &i_h);
}

void	mlx_graphique(t_vars	*v)
{
	int		i_w;
	int		i_h;
	t_h_v	p;

	v->c = 1;
	v->d = 0;
	i_w = 60;
	i_h = 60;
	v->mlx = mlx_init();
	map_dimention(v);
	v->win = mlx_new_window(v->mlx, v->mv * 60, v->mh * 60, "so long");
	file_to_image(v, i_w, i_h);
	if (!v->i_pl || !v->i_s || !v->i_w
		||!v->i_c || !v->i_e || !v->i_p || !v->i_eo)
		return (ft_printf("Error\ninvalide image"), ft_free(v->map, v->mh));
	display(v);
	mlx_string_put(v->mlx, v->win, 0, (v->mh - 1) * 60, 91422, "0");
	mlx_hook(v->win, 17, 1L << 0, ft_close, v);
	mlx_hook(v->win, 2, 1L << 0, key_hook, v);
	mlx_loop(v->mlx);
}
