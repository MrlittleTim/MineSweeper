//
//  game.h
//  MineSweeper
//
//  Created by Tim George on 2022/1/16.
//

#ifndef game_h
#define game_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

#define LEVEL 79

#endif /* game_h */
void menu(void);
void game(void);
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void showBoard(char board[ROWS][COLS], int row, int col);
void setMine(char mine[ROWS][COLS], int row, int col);
void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);


