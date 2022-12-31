#include"so_long.h"

int c_Queued(int h, int v,Queue *q )
{
	int i;

	i = 0;
	if(q->front == -1 )
	return 0;
	while(i <= q->rear)
	{
		if(h == q->h[i] & v == q->v[i])
			return 1;
		i++;
	}
	return 0;
}

void enQueue_neighbours(Queue **p,Queue *Queued,char **m)
{
	int h;
	int v;

	if((*p)->front == - 1)
		return ;
	h = (*p)->h[(*p)->front];
	v = (*p)->v[(*p)->front];

	
	if((m[h][v + 1] != '1' || m[h][v + 1] == 'C') && (!c_Queued(h, v + 1, Queued)))
	{
		printf("Q---------\n");
		printf("R1\n");
		enQueue(h, v + 1, *p);
	}
	if((m[h][v - 1] == '0' || m[h][v - 1] == 'C') && (!c_Queued(h,v - 1, Queued)))
	{
		printf("Q---------\n");
		printf("L2\n");
		enQueue(h, v  - 1, *p); 
	}
	if((m[h + 1][v] == '0' || m[h + 1][v] == 'C') && (!c_Queued(h + 1, v, Queued)))
	{
		printf("Q---------\n");
		printf("D3\n");
		enQueue(h + 1 ,v, *p);
	}
	if((m[h - 1][v] == '0' || m[h + 1][v] == 'C') && (!c_Queued(h - 1, v, Queued)))
	{

		printf("Q---------\n");
		printf("U4\n");
		enQueue(h - 1 ,v, *p);
	}
}

int check_EXIT(t_h_v el_po,Queue *visited,char **map)
{
	int i ;
	int h;
	int v;

	h = el_po.ph;
	v = el_po.pv;

	if(c_Queued(h, v + 1, visited))
		return 1;
	if(c_Queued(h,v - 1, visited))
		return 1;
	if (c_Queued(h + 1, v, visited))
		return 1;
	if(c_Queued(h - 1, v, visited))
		return 1;
	return 0;
}

int player_range(t_h_v el_po,t_h_v player_position,size_t map_nodes,char **m)
{
    Queue *p;
    Queue *visited;
    int i;

     i = 0;
    p= new_Queue((int) map_nodes);
    if(!p)
        return 0;
    visited= new_Queue((int) map_nodes);
    if(!visited)
        return (freeQueue(&p),0);
        printf("Q---------\n");
    enQueue(player_position.ph,player_position.pv,p);
     while(i <= map_nodes)    
    {
        enQueue_neighbours(&p,p,m);
        // printf("%d %d\n",p->h[i],p->v[i]);
        i++;
        if(!c_Queued(p->h[p->front],p->v[p->front],visited)) 
        {
        printf("visitied--------\n"); 
        enQueue(p->h[p->front],p->v[p->front],visited);
        }
        //  printf("Q---------\n");
         deQueue(p);
        // printf("<%d>\n",i);
    }
    i = 0;

    while(el_po.h[i] != -1337)
    {
        if(c_Queued(el_po.h[i],el_po.v[i],visited))
            i++;
        else    
            return (freeQueue(&p),freeQueue(&visited),0);
    }
    if(!check_EXIT(el_po,visited,m))
    return (freeQueue(&p),freeQueue(&visited),0);
    return 1;
}

// 11111111111 0
// 1000C0100E1 1
// 100000C0001 2
// 11111P0C111 3
// 11111111111 4

// 012345678910

	
// 11111111111 
// 1000C0100E1 
// 100000C0001 
// 11111P0C111 
// 11111111111