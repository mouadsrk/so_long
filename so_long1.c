// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   so_long1.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/01/01 06:00:53 by mserrouk          #+#    #+#             */
// /*   Updated: 2023/01/01 06:39:02 by mserrouk         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include"so_long.h"


int so_long(char **av)
{
    int i;
	t_vars	vars;

    vars.map = ft_read(av);
	if (!vars.map)
			return 0;	
	if (map_quality(vars.map) == 0)
		return (0);
	mlx_graphique(&vars);
    return (1);
}

int main (int ac, char **av)
{
	int i;
	if (ac != 2)
		return (1);
    i = 0;
	i = so_long(av);
	if (i == 1)
		printf("good map");
	else
		printf("bad map");
}
