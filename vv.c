#include <libc.h>

int main()
{
	int i = 0;
	int c = 500000;
	while(300000000>i++)
	{
	if (i == c)
	{
		c = c + 5000;
		printf("\n");
	}
	printf("1");
	}
}

