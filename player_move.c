#include"so_long.h"

// void display(char **map)
// {
// int i;
// i = 0;
// 	while(map[i])
// 		{
// 			printf("%s\n",map[i]);
// 			i++;
// 		}
// 	printf("\n\n");
// }




void player_move(char **map,int keycode)
{
	t_h_v e_p;
	int c;
	// int i;
	static int number;

	// i = 0;
	// while(map[i])
	// 	{
	// 		printf("%s\n",map[i]);
	// 		i++;
	// 	}
		c = number_of_element(&e_p , map);
	printf("c = %d\n",c);
	

		if(keycode == 126)
		{
			move_up(&c,&e_p,map ,&number);
			// display(map);
		}
		else if(keycode == 125)
		{
			move_down(&c,&e_p,map,&number);
			// display(map);
		}
		else if(keycode == 123)
		{
			move_left(&c,&e_p,map,&number);
			// display(map);
		}
		else if(keycode == 124)
		{
			move_right(&c,&e_p,map,&number);
			// display(map);
		}
		if(keycode == 53)
		exit(0);
}



