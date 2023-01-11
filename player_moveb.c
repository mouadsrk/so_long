/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moveb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:13:24 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/11 23:19:20 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	graphique_image_norm(int i, int j,	t_vars	*v)
{
	if (v->map[i / 60][j / 60] == 'C')
	{
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_s, j, i);
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_c, j, i);
	}	
	else if (v->map[i / 60][j / 60] == 'R' && v->rd == 0)
	{
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_s, j, i);
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_r, j, i);
	}
	else if (v->map[i / 60][j / 60] == 'R' && v->rd == 1)
	{
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_s, j, i);
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_rl, j, i);
	}
	else if (v->map[i / 60][j / 60] == '0')
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_s, j, i);
	else if (v->map[i / 60][j / 60] == '1')
		v->p_im = mlx_put_image_to_window(v->mlx, v->win, v->i_w, j, i);
}

void	graphique_image(int i, int j,	t_vars	*v)
{
	char	*n;

	n = ft_itoa(v->number);
	i = i * 60;
	j = j * 60;
	mlx_string_put(v->mlx, v->win, 0, v->mh * 60, 16776966, n);
	free(n);
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
	else
		graphique_image_norm(i, j, v);
}

void	display(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->mh)
	{
		j = 0;
		while (j < vars->mv)
		{
			graphique_image(i, j, vars);
			j++;
		}
		i++;
	}
}

void	player_moveb(t_vars *vars, int keycode)
{
	t_h_v		e_p;

	vars->c = number_of_element(&e_p, vars->map);
	if (keycode == 126 || keycode == 13)
		move_upb(&e_p, vars);
	else if (keycode == 125 || keycode == 1)
		move_downb(&e_p, vars);
	else if (keycode == 123 || keycode == 2)
		move_leftb(&e_p, vars);
	else if (keycode == 124 || keycode == 0)
		move_rightb(&e_p, vars);
	if (keycode == 53)
		exit(0);
}
