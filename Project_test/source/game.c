/*
*
*	File Name	:	game.c
*	Author		:
*	Last Update :	23.12.2017
*
*	Implementation of game
*/

#define TEST

#ifdef TEST
#include <stdio.h>
#endif

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "game.h"
#include "timer.h"
#include "graphic_sub.h"
#include "sound.h"
#include "P_Controls.h"

#define PRIVATE static
#define PUBLIC

#define ROW			12
#define COL			12
#define GAME_ROW	(ROW - 2)
#define GAME_COL	(COL - 2)

PRIVATE void fill_array(int number_of_bombs);
PRIVATE int get_sum(int i, int j);
PRIVATE void calculate_numbers();
PRIVATE int get_number_of_bombs(int level);
PRIVATE void show_empty_relatives(int i, int j);
PRIVATE void show_bombs(void);

PRIVATE CELL_INFO g_matrix[ROW][COL];

PUBLIC void init_game(int level)
{
	srand(TIMER0_DATA);
	int i, j;

	for(i = 0; i < ROW; ++i)
		for(j = 0; j < COL; ++j) {
			g_matrix[i][j].env_bomb_count = 0;
			g_matrix[i][j].is_bomb = 0;
			g_matrix[i][j].uncovered = 0;
		}

	fill_array(get_number_of_bombs(level)); /* matrisi random dolduruyor */
}

PRIVATE void fill_array(int number_of_bombs)
{
	int i, row, col;
	int status[ROW][COL];
	memset(status, 0, sizeof(status));
	int repeat;

	for (i = 0; i < number_of_bombs; ++i) { /*[1, ROW - 1)*/
		do {
			repeat = 0;
			row = rand() % GAME_ROW + 1;
			col = rand() % GAME_COL + 1;
			if (status[row][col])
			repeat = 1;
		} while (repeat);

		status[row][col] = 1;
		g_matrix[row][col].is_bomb = 1;
	}
	calculate_numbers();

#ifdef TEST

#endif
}

PRIVATE int get_sum(int i, int j)
{
	int sum = 0;

	/*(i - 1, j - 1), (i - 1, j), (i - 1, j + 1), (i, j - 1), (i, j + 1), (i + 1, j - 1), (i + 1, j), (i + 1, j +1)*/
	sum = g_matrix[i - 1][j - 1].is_bomb + g_matrix[i - 1][j].is_bomb + g_matrix[i - 1][j + 1].is_bomb +
		g_matrix[i][j - 1].is_bomb + g_matrix[i][j + 1].is_bomb + g_matrix[i + 1][j - 1].is_bomb +
		g_matrix[i + 1][j].is_bomb + g_matrix[i + 1][j + 1].is_bomb;

	return sum;
}
PRIVATE void calculate_numbers()
{
	int i, j;

	for (i = 1; i <= GAME_ROW; ++i) {
		for (j = 1; j <= GAME_COL; ++j) {
			if (!g_matrix[i][j].is_bomb)
				g_matrix[i][j].env_bomb_count = get_sum(i, j);
		}
	}
}

PRIVATE int get_number_of_bombs(int level)
{
	int number_of_bombs = NBOMBS_EASY;

	switch (level) {
	case 2:
		number_of_bombs = NBOMBS_MEDIUM;
		break;
	case 3:
		number_of_bombs = NBOMBS_HARD;
		break;
	}

	return number_of_bombs;
}

PRIVATE void show_empty_relatives(int i, int j)
{
	if (i < 1 || i > GAME_ROW || j < 1 || j > GAME_COL)
		return;

	if (g_matrix[i][j].uncovered)
		return;

	if (g_matrix[i][j].env_bomb_count > 0) {
		g_matrix[i][j].uncovered = 1;
	}
	else {
		g_matrix[i][j].uncovered = 1;
		show_empty_relatives(i - 1, j - 1);
		show_empty_relatives(i - 1, j);
		show_empty_relatives(i - 1, j + 1);
		show_empty_relatives(i, j - 1);
		show_empty_relatives(i, j + 1);
		show_empty_relatives(i + 1, j - 1);
		show_empty_relatives(i + 1, j);
		show_empty_relatives(i + 1, j + 1);
	}

	if (g_matrix[i][j].env_bomb_count == 0)
		fill_19x19_button((i-1)*19, (j-1)*19+32, GREY, WHITE);
	else if (g_matrix[i][j].env_bomb_count == 1)
	{
		fill_19x19_button((i-1)*19, (j-1)*19+32, GREY, WHITE);
		fill_19x19_one((i-1)*19, (j-1)*19+32);
	}
	else if (g_matrix[i][j].env_bomb_count == 2)
	{
		fill_19x19_button((i-1)*19, (j-1)*19+32, GREY, WHITE);
		fill_19x19_two((i-1)*19, (j-1)*19+32);
	}
	else if (g_matrix[i][j].env_bomb_count == 3)
	{
		fill_19x19_button((i-1)*19, (j-1)*19+32, GREY, WHITE);
		fill_19x19_three((i-1)*19, (j-1)*19+32);
	}
	else if (g_matrix[i][j].env_bomb_count == 4)
	{
		fill_19x19_button((i-1)*19, (j-1)*19+32, GREY, WHITE);
		fill_19x19_four((i-1)*19, (j-1)*19+32);
	}
	else if (g_matrix[i][j].env_bomb_count == 5)
	{
		fill_19x19_button((i-1)*19, (j-1)*19+32, GREY, WHITE);
		fill_19x19_five((i-1)*19, (j-1)*19+32);
	}
	else if (g_matrix[i][j].env_bomb_count == 6)
	{
		fill_19x19_button((i-1)*19, (j-1)*19+32, GREY, WHITE);
		fill_19x19_six((i-1)*19, (j-1)*19+32);
	}
	else if (g_matrix[i][j].env_bomb_count == 7)
	{
		fill_19x19_button((i-1)*19, (j-1)*19+32, GREY, WHITE);
		fill_19x19_seven((i-1)*19, (j-1)*19+32);
	}
	else if (g_matrix[i][j].env_bomb_count == 8)
	{
		fill_19x19_button((i-1)*19, (j-1)*19+32, GREY, WHITE);
		fill_19x19_eight((i-1)*19, (j-1)*19+32);
	}

}

PRIVATE void show_bombs()
{
	int i, j;

	for (i = 1; i < GAME_ROW; ++i)
		for (j = 1; j < GAME_COL; ++j)
			if (g_matrix[i][j].is_bomb)
			{
				fill_19x19_button((i-1)*19, (j-1)*19+32, GREY, WHITE);
				fill_19x19_bomb((i-1)*19, (j-1)*19+32);
			}


}

PUBLIC void on_matrix_clicked(int countery, int counterx)
{
/*
	// +1 because of the extra frame on g_matrix
	if (g_matrix[i+1][j+1].is_bomb) {
#ifdef TEST
		fill_19x19_bomb(j*19, i*19+32);
#endif
		return;
	}
*/

	// +1 because of the extra frame on g_matrix
	if (g_matrix[countery+1][counterx+1].is_bomb)
	{
		show_bombs();
		irqDisable(IRQ_TIMER0);
		Explosion_Effect_Play();
		stopMusic();
		stopTouching();
	}
	else
		show_empty_relatives(countery+1, counterx+1);
}


