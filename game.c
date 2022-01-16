//
//  game.c
//  MineSweeper
//
//  Created by Tim George on 2022/1/16.
//

#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = set;
        }
    }
}

void showBoard(char board[ROWS][COLS], int row, int col)
{
    printf("------扫雷游戏------\n");
    //打印列坐标号
    for (int i = 0; i <= col; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for (int i = 1; i <= row; i++) {
        printf("%d ", i);//打印行坐标号
        for (int j = 1; j <= col; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("------扫雷游戏------\n");
}

void setMine(char mine[ROWS][COLS], int row, int col)
{
    int cnt = LEVEL;
    while (cnt) {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        if (mine[x][y] == '0') {
            mine[x][y] = '1';
            --cnt;
        }
    }
}


//统计（x,y）坐标周围8个位置的雷数
//static int getMineCount(char mine[ROWS][COLS], int x, int y)
//{
//    return mine[x - 1][y - 1] +
//        mine[x - 1][y] +
//        mine[x - 1][y + 1] +
//        mine[x][y - 1] +
//        mine[x][y + 1] +
//        mine[x + 1][y - 1] +
//        mine[x + 1][y] +
//        mine[x + 1][y + 1] -
//        8 * '0';
//}
static int getMineCount(char mine[ROWS][COLS], int x, int y)
{
    int cnt = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (mine[x + i][y + j] == '1') {
                cnt++;
            }
        }
    }
    return cnt;
}

void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    //    1. 输入排查坐标
    //    2. 检查是否为雷
    //        1. 是雷，游戏结束
    //        2. 不是雷， 统计坐标周围几个雷，继续游戏
    int x, y;
    int win = 0;
    while (win < ROW * COL - LEVEL) {
        printf("请输入坐标:>");
        scanf("%d %d", &x, &y);
        if (x >= 1 && x <= 9 && y >= 1 && y <= 9) {
            //是雷，结束
            if (mine[x][y] == '1') {
                printf("很遗憾，踩中雷了\n");
                showBoard(mine, row, col);
                break;
            }
            //不是雷，统计
            else
            {
                int cnt = getMineCount(mine, x, y);
                show[x][y] = cnt + '0';//数字->字符；数字转字符
                showBoard(show, ROW, COL);
                win++;
            }
        }
        else
        {
            printf("坐标非法，请重新输入:>");
        }
    }
    if (win == ROW * COL - LEVEL) {
        printf("恭喜你，扫雷成功！\n");
    }
}
