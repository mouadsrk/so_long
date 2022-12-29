#include"so_long.h"

void enQueue_neighbours(int h,int v,Queue *p,char **m)
{
    if(m[][] != '1')
        enQueue();

}
int player_range(t_h_v el_po,t_h_v player_position,size_t map_nodes,char **m )
{
    Queue *p;;
    Queue *visited;

    p= new_Queue((int) map_nodes);
    if(!p)
        return 0;
    visited= new_Queue((int) map_nodes);
    if(!visited)
        return (freeQueue(&p),0);
    enQueue(player_position.h,player_position.v,p);
    enQueue(player_position.h,player_position.v,visited);
    
    enQueue_neighbours(player_position.h,player_position.v,p,m);


    

}


