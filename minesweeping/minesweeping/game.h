#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define BOMB_COUNT 10

void Initboard(char board[ROWS][COLS], int rows, int cols,char set);
void Displayboard(char board[ROWS][COLS], int row, int col );
void layoutbomb(char mine[ROWS][COLS], int row, int col);
void finebomb(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);
void openboard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
