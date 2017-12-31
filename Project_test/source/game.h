/*
 *	File Name	:	game.h
 *	Author		:
 *	Last Update :	23.12.2017
 *
 *	Header file of game
 */


#ifndef GAME_H_
#define GAME_H_


#define NBOMBS_EASY		10
#define NBOMBS_MEDIUM	20
#define NBOMBS_HARD		30

void init_game(int level);
void on_matrix_clicked(int i, int j);
void stopGame();


#endif /* GAME_H_ */
