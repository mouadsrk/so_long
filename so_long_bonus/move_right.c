/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:52:36 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/09 00:17:07 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right_norm(t_h_v *e_p, t_vars *vars)
{
	int		h;
	int		v;

	h = e_p->ph;
	v = e_p->pv;
	if (vars->map[h][v + 1] == 'E' && vars->c == 0)
	{
		ft_printf("you win");
		exit(0);
	}
	else if (vars->map[h][v + 1] == 'R')
	{
		ft_printf("you lost");
		exit(0);
	}
}

void	move_rightp(t_h_v *e_p, t_vars *vars)
{
	int		h;
	int		v;

	h = e_p->ph;
	v = e_p->pv;
	if (vars->map[h][v + 1] == 'C' || vars->map[h][v + 1] == '0')
	{
		vars->d = 0;
		e_p->pv = v + 1;
		if (vars->map[h][v + 1] == 'C')
			vars->c -= 1;
		vars->map[h][v] = '0';
		vars->map[h][v + 1] = 'P';
		mlx_clear_window(vars->mlx, vars->win);
		display(vars);
	}
	else
		move_right_norm(e_p, vars);
}

void	move_right(t_h_v *e_p,	t_vars *vars)
{
	int	h;
	int	v;

	h = e_p->ph;
	v = e_p->pv;
	if (vars->map[h][v + 1] == '1')
		return ;
	if (vars->map[h][v + 1] == 'E' && vars->c != 0)
		return ;
	vars->number += 1;
	move_rightp(e_p, vars);
}
