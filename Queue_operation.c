#include"so_long.h"


Queue* new_Queue(int SIZE)
{
  Queue *p;
  p = malloc (sizeof(Queue));
    if(!p)
      return (NULL);
  p->front = -1;
  p->rear = -1;
  p->size = SIZE;
  p->h = malloc (SIZE + 1);
  if(!p->h)
      return (free(p),p = NULL,NULL);
  p->v = malloc (SIZE + 1);
  if(!p->v)
      return (free(p),p = NULL,free(p->v),p->v = NULL,NULL);
  p->h[SIZE] = '\0';
  p->v[SIZE] = '\0';
  
  return (p);
}

void enQueue(char h,char v,Queue *p)
{
  if (p->rear == p->size - 1)
    return ;
  p->rear += 1;
  if (p->rear == 0)
  p->front = 0;
  p->h[p->rear] = h;
  p->v[p->rear] = v;
}

void deQueue(Queue *p)
{
  if (p->front == -1)
    return;
  p->front++;
  if(p->front > p->rear)
  {
    p->front = -1;
    p->rear = -1;
  }
}

void freeQueue(Queue **p)
{
  free((*p)->h);
  (*p)->h = NULL;
  free((*p)->v);
  (*p)->v = NULL;
  free(*p);
  (*p) = NULL;
}

void free_t_h_v(t_h_v *e)
{
    free(e->h);
    e->eh = NULL;
    free(e->ev);
    e->ev = NULL;
}