/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:13:24 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/08 18:23:43 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	graphique_image(int i, int j,	t_vars	*v)
{
	i = i * 60;
	j = j * 60;
	if (v->map[i / 60][j / 60] == 'P' && v->d == 0)
	{
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_s, j, i);
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_p, j, i);
	}
	else if (v->map[i / 60][j / 60] == 'P' && v->d == 1)
	{
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_s, j, i);
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_pl, j, i);
	}
	else if (v->map[i / 60][j / 60] == 'E' && v->c > 0)
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_e, j, i);
	else if (v->map[i / 60][j / 60] == 'E' && v->c == 0)
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_eo, j, i);
	else if (v->map[i / 60][j / 60] == '0')
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_s, j, i);
	else if (v->map[i / 60][j / 60] == '1')
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_w, j, i);
	else if (v->map[i / 60][j / 60] == 'C')
	{
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_s, j, i);
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_c, j, i);
	}	
}

void	display(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			graphique_image(i, j, vars);
			j++;
		}
		i++;
	}
}

void	player_move(t_vars *vars, int keycode)
{
	t_h_v		e_p;
	static int	number;

	vars->c = number_of_element(&e_p, vars->map);
	if (keycode == 126)
		move_up(&e_p, vars, &number);
	else if (keycode == 125)
		move_down(&e_p, vars, &number);
	else if (keycode == 123)
		move_left(&e_p, vars, &number);
	else if (keycode == 124)
		move_right(&e_p, vars, &number);
	if (keycode == 53)
		exit(0);
}
