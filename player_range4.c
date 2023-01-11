/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_range4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:15:36 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/10 20:07:39 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	c_queued(int h, int v, t_queue *q)
{
	int	i;

	i = 0;
	if (q->front == -1)
		return (0);
	while (i <= q->rear)
	{
		if (h == q->h[i] & v == q->v[i])
			return (1);
		i++;
	}
	return (0);
}

void	enqueue_neighbours(t_queue **p, t_queue *Q, char **m)
{
	int	h;
	int	v;

	if ((*p)->front == -1)
		return ;
	h = (*p)->h[(*p)->front];
	v = (*p)->v[(*p)->front];
	if ((m[h][v + 1] == '0' || m[h][v + 1] == 'C') && (!c_queued(h, v + 1, Q)))
		enqueue(h, v + 1, *p);
	if ((m[h][v - 1] == '0' || m[h][v - 1] == 'C') && (!c_queued(h, v - 1, Q)))
		enqueue(h, v - 1, *p);
	if ((m[h + 1][v] == '0' || m[h + 1][v] == 'C') && (!c_queued(h + 1, v, Q)))
		enqueue(h + 1, v, *p);
	if ((m[h - 1][v] == '0' || m[h - 1][v] == 'C') && (!c_queued(h - 1, v, Q)))
		enqueue(h - 1, v, *p);
}

int	check_exit(t_h_v el_po, t_queue *visited)
{
	int	h;
	int	v;

	h = el_po.eh;
	v = el_po.ev;
	if (c_queued(h, v + 1, visited))
		return (1);
	if (c_queued(h, v - 1, visited))
		return (1);
	if (c_queued(h + 1, v, visited))
		return (1);
	if (c_queued(h - 1, v, visited))
		return (1);
	return (0);
}

int	check_elpo(t_h_v el_po, t_queue *visited)
{
	int	i;

	i = 0;
	while (el_po.h[i] != -1337)
	{
		if (c_queued(el_po.h[i], el_po.v[i], visited))
			i++;
		else
			return (0);
	}
	return (1);
}

int	player_range(t_h_v el_po,	size_t map_nodes,	char **m)
{
	t_queue	*p;
	t_queue	*visited;
	size_t	i;

	i = 0;
	p = new_queue((int) map_nodes);
	if (!p)
		return (0);
	visited = new_queue((int) map_nodes);
	if (!visited)
		return (freequeue(&p), 0);
	enqueue(el_po.ph, el_po.pv, p);
	while (i <= map_nodes)
	{
		enqueue_neighbours(&p, p, m);
		i++;
		if (!c_queued(p->h[p->front], p->v[p->front], visited))
			enqueue(p->h[p->front], p->v[p->front], visited);
		dequeue(p);
	}
	if (!check_exit(el_po, visited) || !check_elpo(el_po, visited))
		return (freequeue(&p), freequeue(&visited), 0);
	return (freequeue(&p), freequeue(&visited), 1);
}
