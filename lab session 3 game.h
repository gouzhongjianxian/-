#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>

void initboard(char board[ROW][COL],int row,int col);
void playermove(char board[ROW][COL],int row,int col);
void displayboard(char board[ROW][COL],int row,int col);
void computermove(char board[ROW][COL],int row,int col);
char iswin(char board[ROW][COL],int row,int col);
int checkcomputer(char board[ROW][COL],int row,int col);
char judgeplayer(char board[ROW][COL],int row,int col,int k);

void initboard(char board[ROW][COL],int row,int col)
{
    int i=0;
    int j=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            board[i][j]='.';
        }
    }
}

void playermove(char board[ROW][COL],int row,int col)
{
    
    int n=0;
    while(1)
    {
        scanf("%d",&n);
        int i=0;
        int j=0;
        if(n>0&&n<10)
        {
            i=2-(n-1)/3;
            j=(n-1)%3;
            if(board[i][j]=='X')
            {
                printf("输入错误,请重新输入\n");
            }
            else if(board[i][j]=='O')
            {
                printf("输入错误,请重新输入\n");
            }
            else
            {
                board[i][j]='X';
                break;
            }
        }
        else
        {
            printf("输入错误,请重新输入\n");
        }
    }
}

void displayboard(char board[ROW][COL],int row,int col)
{
    int i=0;
    int j=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

void computermove(char board[ROW][COL],int row,int col)
{
    int x=0;
    int y=0;
    int a=0;
    a=checkcomputer(board,row,col);
    while(a==0)
    {
        x=rand()%row;
        y=rand()%col;
        if(board[x][y]=='.')
        {
            board[x][y]='O';
            break;
        }
    }
}

int isfull(char board[ROW][COL],int row,int col)
{
    int i=0;
    int j=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(board[i][j]=='.')
            {
                return 0;
            }
        }
    }
    return 1;
}

char iswin(char board[ROW][COL],int row,int col)
{
    int i=0;
    int j=0;
    for(i=0;i<row;i++)
    {
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]!='.')
        {
            return board[i][0];
        }
    }
    for(i=0;i<col;i++)
    {
        if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[0][i]!='.')
        {
            return board[0][i];
        }
    }
    if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[0][0]!='.')
    {
        return board[0][0];
    }
    if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[0][2]!='.')
    {
        return board[0][2];
    }
    if(1==isfull(board,ROW,COL))
    {
        return 'Q';
    }
    else
    {
        return 'C';
    }
}

int checkcomputer(char board[ROW][COL],int row,int col)
{
    int i=0;
    int j=0;
    int k=0;
    while(k==0)
    {
        for(i=0;i<row;i++)
        {
            if(board[i][0]==board[i][1]&&board[i][0]=='O'&&board[i][2]=='.')
            {
                board[i][2]='O';
                k=1;
                break;
            }
            if(board[i][0]==board[i][2]&&board[i][0]=='O'&&board[i][1]=='.')
            {
                board[i][1]='O';
                k=1;
                break;
            }
            if(board[i][1]==board[i][2]&&board[i][1]=='O'&&board[i][0]=='.')
            {
                board[i][0]='O';
                k=1;
                break;
            }
        }
        if(k!=0)
        {
            break;
        }
        for(j=0;j<col;j++)
        {
            if(board[0][j]==board[1][j]&&board[0][j]=='O'&&board[2][j]=='.')
            {
                board[2][j]='O';
                k=1;
                break;
            }
            if(board[0][j]==board[2][j]&&board[0][j]=='O'&&board[1][j]=='.')
            {
                board[1][j]='O';
                k=1;
                break;
            }
            if(board[1][j]==board[2][j]&&board[1][j]=='O'&&board[0][j]=='.')
            {
                board[0][j]='O';
                k=1;
                break;
            }
        }
        break;
    }
    while(k==0)
    {
        if(board[0][0]==board[1][1]&&board[0][0]=='O'&&board[2][2]=='.')
        {
            board[2][2]='O';
            k=1;
            break;
        }
        if(board[0][0]==board[2][2]&&board[0][0]=='O'&&board[1][1]=='.')
        {
            board[1][1]='O';
            k=1;
            break;
        }
        if(board[1][1]==board[2][2]&&board[1][1]=='O'&&board[0][0]=='.')
        {
            board[0][0]='O';
            k=1;
            break;
        }
        if(board[0][2]==board[1][1]&&board[0][2]=='O'&&board[2][0]=='.')
        {
            board[2][0]='O';
            k=1;
            break;
        }
        if(board[0][2]==board[2][0]&&board[0][2]=='O'&&board[1][1]=='.')
        {
            board[1][1]='O';
            k=1;
            break;
        }
        if(board[1][1]==board[2][0]&&board[1][1]=='O'&&board[0][2]=='.')
        {
            board[0][2]='O';
            k=1;
            break;
        }
        break;
    }
    k=judgeplayer(board,row,col,k);
    return k;
}

char judgeplayer(char board[ROW][COL],int row,int col,int k)
{
    int i=0;
    int j=0;
    while(k==0)
    {
        for(i=0;i<row;i++)
        {
            if(board[i][0]==board[i][1]&&board[i][0]=='X'&&board[i][2]=='.')
            {
                board[i][2]='O';
                k=1;
                break;
            }
            if(board[i][0]==board[i][2]&&board[i][0]=='X'&&board[i][1]=='.')
            {
                board[i][1]='O';
                k=1;
                break;
            }
            if(board[i][1]==board[i][2]&&board[i][1]=='X'&&board[i][0]=='.')
            {
                board[i][0]='O';
                k=1;
                break;
            }
        }
        if(k!=0)
        {
            break;
        }
        for(j=0;j<col;j++)
        {
            if(board[0][j]==board[1][j]&&board[0][j]=='X'&&board[2][j]=='.')
            {
                board[2][j]='O';
                k=1;
                break;
            }
            if(board[0][j]==board[2][j]&&board[0][j]=='X'&&board[1][j]=='.')
            {
                board[1][j]='O';
                k=1;
                break;
            }
            if(board[1][j]==board[2][j]&&board[1][j]=='X'&&board[0][j]=='.')
            {
                board[0][j]='O';
                k=1;
                break;
            }
        }
        break;
    }
    while(k==0)
    {
        if(board[0][0]==board[1][1]&&board[0][0]=='X'&&board[2][2]=='.')
        {
            board[2][2]='O';
            k=1;
            break;
        }
        if(board[0][0]==board[2][2]&&board[0][0]=='X'&&board[1][1]=='.')
        {
            board[1][1]='O';
            k=1;
            break;
        }
        if(board[1][1]==board[2][2]&&board[1][1]=='X'&&board[0][0]=='.')
        {
            board[0][0]='O';
            k=1;
            break;
        }
        if(board[0][2]==board[1][1]&&board[0][2]=='X'&&board[2][0]=='.')
        {
            board[2][0]='O';
            k=1;
            break;
        }
        if(board[0][2]==board[2][0]&&board[0][2]=='X'&&board[1][1]=='.')
        {
            board[1][1]='O';
            k=1;
            break;
        }
        if(board[1][1]==board[2][0]&&board[1][1]=='X'&&board[0][2]=='.')
        {
            board[0][2]='O';
            k=1;
            break;
        }
        break;
    }
    return k;
}