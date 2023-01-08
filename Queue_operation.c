/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:31:37 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/08 19:22:02 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

t_queue	*new_queue(int SIZE)
{
	t_queue	*p;
	int		i;

	i = 0;
	p = malloc (sizeof(t_queue));
	if (!p)
		return (NULL);
	p->front = -1;
	p->rear = -1;
	p->size = SIZE;
	p->h = malloc (sizeof(int) * (SIZE + 1));
	if (!p->h)
		return (free(p), p = NULL, NULL);
	p->v = malloc (sizeof(int) * (SIZE + 1));
	if (!p->v)
		return (free(p), p = NULL, free(p->v), p->v = NULL, NULL);
	while (i <= SIZE)
	{
		p->h[i] = -1337;
		p->v[i] = -1337;
		i++;
	}
	return (p);
}

void	enqueue(int h, int v, t_queue *p)
{
	if (p->rear == p->size - 1)
		return ;
	p->rear += 1;
	if (p->rear == 0)
	p->front = 0;
	p->h[p->rear] = h;
	p->v[p->rear] = v;
}

void	dequeue(t_queue *p)
{
	if (p->front == -1)
		return ;
	p->front++;
	if (p->front > p->rear)
	{
		p->front = -1;
		p->rear = -1;
	}
}
// if(p->front > p->rear) rear star with -1 but with front 0 

void	freequeue(t_queue **p)
{
	free((*p)->h);
	(*p)->h = NULL;
	free((*p)->v);
	(*p)->v = NULL;
	free(*p);
	(*p) = NULL;
}
