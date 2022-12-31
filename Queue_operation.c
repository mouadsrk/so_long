#include"so_long.h"


Queue* new_Queue(int SIZE)
{
  Queue *p;
  int i;
  
  i = 0;
  p = malloc (sizeof(Queue));
    if(!p)
      return (NULL);
  p->front = -1;
  p->rear = -1;
  p->size = SIZE;
  p->h = malloc (sizeof(int) * (SIZE + 1));
  if(!p->h)
      return (free(p),p = NULL,NULL);
  p->v = malloc (sizeof(int) * (SIZE + 1));
  if(!p->v)
      return (free(p),p = NULL,free(p->v),p->v = NULL,NULL);
  while(i <=  SIZE)
    {
    p->h[i] = -1337;
    p->v[i] = -1337;
    i++;
    }
  return (p);
}

void enQueue(int h, int v,Queue *p)
{
  if (p->rear == p->size - 1)
    return ;
  p->rear += 1;
  if (p->rear == 0)
  p->front = 0;
  p->h[p->rear] = h;
  p->v[p->rear] = v;
  //  printf("enQueue ------------\n");
  printf("r = %d\n",p->rear);
  printf("f = %d\n",p->front);
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
    // printf("deQueue ------------\n");
  // printf("r = %d\n",p->rear);
  // printf("f = %d\n",p->front);
}
// if(p->front > p->rear) rear star with -1 but with front 0 

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
    e->h = NULL;
    free(e->v);
    e->v = NULL;
}