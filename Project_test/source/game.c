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

#define PRIVATE static
#define PUBLIC

#define ROW			12
#define COL			12
#define GAME_ROW	(ROW - 2)
#define GAME_COL	(COL - 2)

typedef struct tagCELL_INFO {
	int env_bomb_count;
	int is_bomb;
} CELL_INFO;

PRIVATE void fill_array(int number_of_bombs);
PRIVATE int get_sum(int i, int j);
PRIVATE void calculate_numbers();
PRIVATE int get_number_of_bombs(int level);

PRIVATE CELL_INFO g_matrix[ROW][COL];

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

PUBLIC void init_game(int level)
{
	srand(TIMER0_DATA);
	fill_array(get_number_of_bombs(level)); /* matrisi random dolduruyor */
}

PUBLIC void on_matrix_clicked(int i, int j)
{
	// +1 because of the extra frame on g_matrix
	if (g_matrix[i+1][j+1].is_bomb) {
#ifdef TEST
		fill_19x19_button(j*19, i*19+32, GREY, BLACK);
#endif
		return;
	}

	if (g_matrix[i+1][j+1].env_bomb_count == 1) {
#ifdef TEST
		fill_19x19_button(j*19, i*19+32, GREY, BLUE);
#endif
	}
	else if (g_matrix[i+1][j+1].env_bomb_count == 2) {
#ifdef TEST
		fill_19x19_button(j*19, i*19+32, GREY, GREEN);
#endif
	}
	else if (g_matrix[i+1][j+1].env_bomb_count == 3) {
#ifdef TEST
		fill_19x19_button(j*19, i*19+32, GREY, YELLOW);
#endif
	}
}


