#include "snake.h"
#include <cstdio>

int snake_size, change_x, change_y, coordinats_x[100], coordinats_y[100], food_x = -1, food_y = -1;

char symb, pole[15][20];

const int  N = 13, M = 17;

int change_direction()
{
	symb = _getch();
	switch (symb)
	{
	case 'w':
		if (change_x != 1 || change_y != 0)
		{
			change_x = -1;
			change_y = 0;
		}
		break;
	case 'a':
		if (change_x != 0 || change_y != 1)
		{
			change_x = 0;
			change_y = -1;
		}
		break;
	case 's':
		if (change_x != -1 || change_y != 0)
		{
			change_x = 1;
			change_y = 0;
		}
		break;
	case 'd':
		if (change_x != 0 || change_y != -1)
		{
			change_x = 0;
			change_y = 1;
		}
		break;
	case 27:
		return 0;
		break;
	default:
		break;
	}
	return 1;
}
void  show_table()
{
	system("cls");
	for (int i = 0; i <= N + 1; ++i)
		for (int j = 0; j <= M + 1; ++j)
		{
			if (i == 0 || j == 0 || i == N + 1 || j == M + 1)
			{
				printf("#");
				if (j == M + 1)
					printf("\n");
				
			}
			else
				printf("%c", pole[i][j]);
		}
}


void clear_snake_on_table()
{
	int i;
	for (i = 1; i <= snake_size; ++i)
		pole[coordinats_x[i]][coordinats_y[i]] = ' ';
}


void show_snake_on_table()
{
	if (change_x == 1 && change_y == 0)
		pole[coordinats_x[1]][coordinats_y[1]] = 'v';
	if (change_x == -1 && change_y == 0)
		pole[coordinats_x[1]][coordinats_y[1]] = '^';
	if (change_x == 0 && change_y == 1)
		pole[coordinats_x[1]][coordinats_y[1]] = '>';
	if (change_x == 0 && change_y == -1)
		pole[coordinats_x[1]][coordinats_y[1]] = '<';

	for (int i = 2; i <= snake_size; ++i)
		pole[coordinats_x[i]][coordinats_y[i]] = 'O';

}


bool is_snake_eat_itself()
{
	for (int i = 2; i <= snake_size; ++i)
		if (coordinats_x[1] == coordinats_x[i] && coordinats_y[1] == coordinats_y[i])
			return true;
	return false;
}


void check_where_is_snake()
{
	if (coordinats_x[1]>N)
		coordinats_x[1] = 1;
	if (coordinats_x[1]<1)
		coordinats_x[1] = N;
	if (coordinats_y[1]>M)
		coordinats_y[1] = 1;
	if (coordinats_y[1]<1)
		coordinats_y[1] = M;
}


int step()
{
	clear_snake_on_table();
	for (int i = snake_size; i>1; --i)
	{
		coordinats_x[i] = coordinats_x[i - 1];
		coordinats_y[i] = coordinats_y[i - 1];
	}

	coordinats_x[1] += change_x;
	coordinats_y[1] += change_y;
	check_where_is_snake();

	if (coordinats_x[1] == food_x && coordinats_y[1] == food_y)
	{
		snake_size++;
		food_x = -1;
		food_y = -1;
	}
	show_snake_on_table();
	if (is_snake_eat_itself() == true)
	{
		printf("OOOPS\n");
		return 0;
	}
	return 1;
}

bool food_check()
{
	if (food_x == -1 && food_y == -1)
		return false;
	return true;
}

void place_food()
{
	srand((unsigned int) time(NULL));
	for (int i = 1; i < 10; ++i)
	{
		int x = rand(), y = rand();
		if (x < 0)
			x *= -1;
		if (y < 0)
			y *= -1;
		x %= (N + 1);
		y %= (M + 1);
		if (x == 0)
			++x;
		if (y == 0)
			++y;
		if (pole[x][y] != 'O' &&pole[x][y] != '^' &&pole[x][y] != 'v' &&pole[x][y] != '<' &&pole[x][y] != '>')
		{
			food_x = x;
			food_y = y;
			pole[x][y] = 'o';
			return;
		}
	}
}
void main_settings()
{
	clear_snake_on_table();
	snake_size = 2;
	coordinats_x[1] = 1;
	coordinats_y[1] = 2;
	coordinats_x[2] = 1;
	coordinats_y[2] = 1;

	change_x = 0;
	change_y = 1;
}



void start()
{
	main_settings();

	while (1)
	{
		if (_kbhit())
			if (!change_direction())
				break;
		if (!step())
		{
			//ask();
			break;
		}
		if (food_check() == false)
			place_food();
		 show_table();
		printf("%i", snake_size);
		Sleep(200);
	}
}

void start_robot()
{
	main_settings();

	while (1)
	{
		if (_kbhit())
		{
			return;
		}
		change_direction_auto();
		proverka(return_napravlenie());
		if (!step())
		{
			//ask();
			break;
		}
		if (food_check() == false)
			place_food();
		show_table();
		printf("%i", snake_size);
		Sleep(100);
	}
	system("cls");
	printf("\t\t ROBOT SCORE IS %i", snake_size);

	_getch();
}
void vverh()
{
	if (change_x != 1 || change_y != 0)
	{
		
		//w
		change_x = -1;
		change_y = 0;
	}
}
void vnis()
{
	if (change_x != -1 || change_y != 0)
	{
		
		//s
		change_x = 1;
		change_y = 0;
	}
	
}
void vlevo()
{
	if (change_x != 0 || change_y != 1)
	{
		
		//a
		change_x = 0;
		change_y = -1;
	}
}
void vpravo()
{
	
	if (change_x != 0 || change_y != -1)
	{
		
		//d
		change_x = 0;
		change_y = 1;
	}
}

int return_napravlenie()
{
	if (change_x == 0 && change_y == -1)
		return 1;//vlevo
	if (change_x == 0 && change_y == 1)
		return 2;//vpravo
	if (change_x == 1 && change_y == 0)
		return 3;//vnis
	if (change_x == -1 && change_y == 0)
		return 4;//vverh
	return 0;
}
void change_direction_auto()
{
	switch (return_napravlenie())
	{
	case 1:
	{
		if (food_y >= coordinats_y[1])
		{
			if (food_x < coordinats_x[1])
				vverh();
			else
				vnis();
		}
		break;
	}
	case 2:
	{
		if (food_y <= coordinats_y[1])
		{
			if (food_x < coordinats_x[1])
				vverh();
			else
				vnis();
		}
		break;

	}
	case 3:
	{

		if (food_x <= coordinats_x[1])
		{
			if (food_y < coordinats_y[1])
				vlevo();
			else
				vpravo();
		}
		break;
	}
	case 4:
	{

		if (food_x >= coordinats_x[1])
		{
			if (food_y < coordinats_y[1])
				vlevo();
			else
				vpravo();
		}
		break;
	}
	}
		
}

void proverka(int i)
{
	int z,j;
	switch (i)
	{
	case 1:
	{
		if (pole[coordinats_x[1]][coordinats_y[1] - 1] == 'O'  && pole[coordinats_x[1] - 1][coordinats_y[1]] == 'O')		
				vnis();
		else
			if (pole[coordinats_x[1]][coordinats_y[1] - 1] == 'O'  && pole[coordinats_x[1] + 1][coordinats_y[1]] == 'O')
				vverh();
			else
				if (pole[coordinats_x[1]][coordinats_y[1] - 1] == 'O')
			{
					j = 0;
					for (z = 0; pole[coordinats_x[1] + z][coordinats_y[1]] != '#'; ++z)
						if (pole[coordinats_x[1] + z][coordinats_y[1]] == 'O')
							j = 1;
				if (j==1)
					vverh();
				else
					vnis();
			}
	
		break;
	}
	case 2:
	{
		if (pole[coordinats_x[1]][coordinats_y[1] + 1] == 'O'  && pole[coordinats_x[1] - 1][coordinats_y[1]] == 'O')
			vnis();
		else
			if (pole[coordinats_x[1]][coordinats_y[1] + 1] == 'O'  && pole[coordinats_x[1] + 1][coordinats_y[1]] == 'O')
				vverh();
			else
				if (pole[coordinats_x[1]][coordinats_y[1] + 1] == 'O')
			{
					j = 0;
					for (z = 0; pole[coordinats_x[1] + z][coordinats_y[1]] != '#'; ++z)
						if (pole[coordinats_x[1] + z][coordinats_y[1]] == 'O')
							j = 1;
					if (j == 1)
						vverh();
					else
						vnis();
			}
		break;
	}
	case 3:
	{
		if (pole[coordinats_x[1] + 1][coordinats_y[1]] == 'O'  && pole[coordinats_x[1]][coordinats_y[1] + 1] == 'O')
			vlevo();
		else
			if (pole[coordinats_x[1] + 1][coordinats_y[1]] == 'O'  && pole[coordinats_x[1]][coordinats_y[1] - 1] == 'O')
				vpravo();
			else
				if (pole[coordinats_x[1] + 1][coordinats_y[1]] == 'O')
			{
					j = 0;
					for (z = 0; pole[coordinats_x[1]][coordinats_y[1]+z] != '#'; ++z)
						if (pole[coordinats_x[1]][coordinats_y[1] + z] == 'O')
							j = 1;
					if (j == 1)
						vlevo();
					else
						vpravo();
			}
		break;
	}
	case 4:
	{
		if (pole[coordinats_x[1] - 1][coordinats_y[1]] == 'O'  && pole[coordinats_x[1]][coordinats_y[1] + 1] == 'O')
			vlevo();
		else
			if (pole[coordinats_x[1] - 1][coordinats_y[1]] == 'O'  && pole[coordinats_x[1]][coordinats_y[1] - 1] == 'O')
				vpravo();
			else
				if (pole[coordinats_x[1] - 1][coordinats_y[1]] == 'O')
			{
					j = 0;
					for (z = 0; pole[coordinats_x[1]][coordinats_y[1]+z] != '#'; ++z)
						if (pole[coordinats_x[1]][coordinats_y[1] + z] == 'O')
							j = 1;
					if (j == 1)
						vlevo();
					else
						vpravo();
			}
		break;
	}
	}
}