#include"so_long.h"






void player_move(char **map)
{
	t_h_v e_p;
	int c;
	int i;
	i= 0;
	int j;
	j = 0;
	while(map[i])
		{
			printf("%s\n",map[i]);
			i++;
		}
		c = number_of_element(&e_p , map);
	printf("c = %d\n",c);
	
	// move_up(&c,&e_p,map);
	// move_down(&c,&e_p,map);
	// move_left(&c,&e_p,map);
	// move_right(&c,&e_p,map);
	i = 0;
	while(j < 7)
	{
			move_down(&c,&e_p,map);
			i = 0;
			while(map[i])
			{
			printf("%s\n",map[i]);
			i++;
			}
		printf("c = %d\n",c);
		printf("\n");
		j++;
	}
	j = 0;
	while(j < 7)
	{
			move_up(&c,&e_p,map);
			i = 0;
			while(map[i])
			{
			printf("%s\n",map[i]);
			i++;
			}
		printf("c = %d\n",c);
		printf("\n");
		j++;
	}
}



