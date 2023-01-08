/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemie_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:38:50 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/09 00:00:27 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    enemie_patrol(t_vars *v, int i, int j)
{
    int x;
    int y;

    x = 0;
    y = 0;
    x = rand() % 3 - 1;
    if (x == 0)
        y = rand() % 3 - 1;
    if (v->map[i + x][j + y] == 'P')
    {
        ft_printf("YOU LOST");
        exit(0);
    }
    if (v->map[i + x][j + y] == '0')
    {
        if(x == -1)
        	v->rd = 1;
        if(x == 1)
       		v->rd = 0;
        v->map[i][j] = '0';
        v->map[i + x][j + y] = 'R';
    }
}

void	enemie_move(t_vars *v)
{
    static int l;
	int	i;
	int	j;

	i = 0;
	j = 0;
    if (l++ == 20)
    {
	    while (v->map[i])
	    {
	    	j = 0;
	    	while (v->map[i][j])
	    	{
	    		if (v->map[i][j] == 'R')
                     enemie_patrol(v, i, j);
	    		j++;
	    	}
	    	i++;
	    }
        l = 0;
    }
}
