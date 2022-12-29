#include"so_long.h"

int check_visited(int h, int v,Queue *visited)
{
    int i;

    i = 0;
    if(visited->front == -1)
    return 1;
    while(i < visited->rear)
    {
        if(h == visited->h[i] & v == visited->v[i])
            return 0;
        i++;
    }
    return 1;
}

void enQueue_neighbours(Queue *p,Queue *visited,char **m)
{
    if(m[p->h[p->front]][p->v[p->front] + 1] != '1' )
        enQueue(p->h[p->front], p->v[p->front] + 1, p);
    if(m[p->h[p->front]][p->v[p->front] - 1] != '1')
        enQueue(p->h[p->front], p->v[p->front]  - 1, p);    
    if(m[p->h[p->front] + 1][p->v[p->front]] != '1')
        enQueue(p->h[p->front] + 1 ,p->v[p->front], p);
    if(m[p->h[p->front] - 1][p->h[p->front]] != '1')
        enQueue(p->h[p->front] - 1 ,p->v[p->front], p);
}
int player_range(t_h_v el_po,t_h_v player_position,size_t map_nodes,char **m )
{
    Queue *p;
    Queue *visited;

    p= new_Queue((int) map_nodes);
    if(!p)
        return 0;
    visited= new_Queue((int) map_nodes);
    if(!visited)
        return (freeQueue(&p),0);
    enQueue(player_position.h,player_position.v,p);
    
    while(p->front != -1)    
    {
        enQueue_neighbours(p,visited,m);
        enQueue(p->h[p->front],p->v[p->front],visited);
        deQueue(p);
    }


}


