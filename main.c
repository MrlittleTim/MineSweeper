//
//  main.c
//  MineSweeper
//
//  Created by Tim George on 2022/1/16.
//

#include "game.h"

int main(int argc, const char * argv[]) {
    int input;
    srand((unsigned int)time(NULL));
    do {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input) {
            case 1:
                game();
                break;
            case 0:
                printf("退出\n");
                break;
            default:
                printf("重选\n");
                break;
        }
    } while (input);
    
    return 0;
}

void menu(void)
{
    printf("***************************\n");
    printf("******    1. play   *******\n");
    printf("******    2. exit   *******\n");
    printf("***************************\n");
}

void game(void)
{
    char mine[ROWS][COLS];//存布雷信息
    char show[ROWS][COLS];//存排雷信息
    //初始化         11*11
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    
    //打印显示棋盘    9*9
    showBoard(show, ROW, COL);
    
    //布置雷
    setMine(mine, ROW, COL);
    showBoard(mine, ROW, COL);
    
    //排查雷
    findMine(mine, show, ROW, COL);
    
}
