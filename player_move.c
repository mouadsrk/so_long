#include"so_long.h"


void display(char **m)
{
    int i , j;
    i = 0;
    j = 0;
    while(m[i])
    {
       printf("%s\n",m[i]);  
        i++;
    }
}

int player_move(char **m)
{
    if(!m)
        return 0;
    // int i;
    // i = 0;
    // while(m[i])
    // {
    //    printf("%s\n",m[i]);  
    //     i++;
    // }
    return 1;
}



