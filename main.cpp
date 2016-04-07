
#include "snake.h"



int main()
{
	int k = -1;
	
	do
	{
		system("cls");
		printf("1 --- PLAY\n");
		printf("2 --- TOP(not func =( )\n");
		printf("3 --- Robot\n");
		printf("0 --- EXIT\n");
		scanf_s("%i", &k);
		switch (k) 
		{
		case 1:
		{
			start();
			break;
		}	
		case 2:
		{
			break;
		}
		case 3:
		{
			start_robot();
			break;
		}
		default:
			break;
		}

	} while (k != 0);
	
	return 0;
}