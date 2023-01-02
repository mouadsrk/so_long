#include"so_long.h"

void display(char **map)
{
int i;
i = 0;
	while(map[i])
		{
			printf("%s\n",map[i]);
			i++;
		}
	printf("\n\n");
}




void player_move(char **map)
{
	t_h_v e_p;
	int c;
	int i;
	int number;

	number = 0;
	int j;
	j = 0;
	char v = 'k';
	i = 0;
	while(map[i])
		{
			printf("%s\n",map[i]);
			i++;
		}
		c = number_of_element(&e_p , map);
	printf("c = %d\n",c);
	
	while(v != 'E')
	{
		scanf("%c",&v);
		if(v == 'w')
		{
			move_up(&c,&e_p,map ,&number);
			display(map);
		}
		else if(v == 's')
		{
			move_down(&c,&e_p,map,&number);
			display(map);
		}
		else if(v == 'a')
		{
			move_left(&c,&e_p,map,&number);
			display(map);
		}
		else if(v == 'd')
		{
			move_right(&c,&e_p,map,&number);
			display(map);
		}
	}
}



