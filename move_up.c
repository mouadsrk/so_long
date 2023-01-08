/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:14:23 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/08 20:33:12 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_upp(t_h_v *e_p, t_vars *vars)
{
	int		h;
	int		v;

	h = e_p->ph;
	v = e_p->pv;
	if (vars->map[h - 1][v] == 'C' || vars->map[h - 1][v] == '0')
	{
		e_p->ph = h - 1;
		if (vars->map[h - 1][v] == 'C')
			vars->c -= 1;
		vars->map[h][v] = '0';
		vars->map[h - 1][v] = 'P';
		mlx_clear_window(vars->mlx, vars->win);
		display(vars);
	}
	else if (vars->map[h - 1][v] == 'E' || vars->c == 0)
		exit(0);
}

void	move_up(t_h_v *e_p, t_vars *vars, int *number)
{
	int	h;
	int	v;

	h = e_p->ph;
	v = e_p->pv;
	if (vars->map[h - 1][v] == '1')
		return ;
	if (vars->map[h - 1][v] == 'E' && vars->c != 0)
		return ;
	*number += 1;
	ft_printf("move number: %d\n",*number);
	move_upp(e_p, vars);
}
