#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <string.h>

int change_direction();
void show_table();
void clear_snake_on_table();
void show_snake_on_table();
bool is_snake_eat_itself();
void check_where_is_snake();
int step();
bool food_check();
void place_food();
void main_settings();
void start();
void ask();
void start_robot();
void change_direction_auto();
void vnis();
void vverh();
void vlevo();
void vpravo();
int return_napravlenie();
void proverka(int i);


#endif