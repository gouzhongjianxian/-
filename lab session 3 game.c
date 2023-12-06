#include<stdio.h>
#include"lab session 3 game.h"
void play()
{
    int ret=0;
    char board[ROW][COL];
    srand((unsigned int)time(NULL));
    initboard(board,ROW,COL);
    displayboard(board,ROW,COL);
    printf("\n");
    while(1)
    {
        playermove(board,ROW,COL);
        displayboard(board,ROW,COL);
        printf("\n");
        ret=iswin(board,ROW,COL);
        if(ret!='C')
        {
            break;
        }
        computermove(board,ROW,COL);
        displayboard(board,ROW,COL);
        printf("\n");
        ret=iswin(board,ROW,COL);
        if(ret!='C')
        {
            break;
        }
    }
    if(ret=='X')
    {
        printf("玩家赢\n");
    }
    else if(ret=='O')
    {
        printf("电脑赢\n");
    }
    else if(ret=='Q')
    {
        printf("平局\n");
    }
}
int main()
{
    play();
    return 0;
}