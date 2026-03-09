#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#include<unistd.h>
#include <ctype.h>


#define N 30
#define M 60
void Snake_Screen();
void print();
void ResetScreenPosition();
void Random();
void movement();
int getch_noblock();
void BodyRemove();
void GameOver();

int i,j,snake[N][M],x,y,Dy,Head,Tail,game=0,a,b,fruits,var,dir,score=0;

void Snake_Screen()
{
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            snake[i][j]=0;
        }
    }
    x = N/2; y=M/2; Dy = y; Head = 5; Tail=1,fruits=0,dir='d';

    for(i=0;i<Head;i++)
    {
        Dy++;
        snake[x][Dy-Head] = i+1;
    }
}
void print()
{
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            if(i==1)
            {
                if(i==1 && j==1)
                    printf(" ");
                printf("%c",220);
            }
        }

    }
    printf("\tScore : %d",score);
    printf("\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<=M;j++)
        {
            if(j==1)
            {
                printf("%c",221);
            }
            else if(j==M)
            {
                printf("%c",222);
            }
            else if(snake[i][j]==0)
            {
                printf(" ");
            }
            else if(snake[i][j]>0 && snake[i][j]!=Head)
            {
                printf("o");
            }
            else if(snake[i][j]==Head)
            {
                printf("%c",79);
            }
            else if(snake[i][j]==-1)
            {
                printf("%c",79);
            }
        }
        printf("\n");
    }

    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            if(i==N)
            {
                if(i==N && j==1)
                    printf(" ");
                printf("%c",223);
            }
        }

    }

}
void ResetScreenPosition()
{
    HANDLE out;
    COORD position;
    out = GetStdHandle(STD_OUTPUT_HANDLE);
    position.X = 0;
    position.Y = 0;
    SetConsoleCursorPosition(out,position);
}
void Random()
{
    srand(time(0));
    a = 1+rand()%28;
    b = 1+rand()%58;
    if(fruits==0 && snake[a][b]==0)
    {
        snake[a][b] = -1;
        fruits = 1;
    }
}
int getch_noblock()
{
    if(_kbhit())
    {
        return _getch();
    }
    else
    {
        return -1;
    }
}
void movement()
{
    var = getch_noblock();
    var = tolower(var);
    if((var == 'd' || var == 'a')||(var == 'w' || var == 's') && ((abs(dir-var))>5))
        dir = var;
    if(dir == 'd')
    {
        y++;
        if(y==M-1)
            y=1;

        if(snake[x][y]!=0 && snake[x][y]!=-1)
        {
            GameOver();
            printf("\n\n\n\t\t\tScore : %d",score);
            exit(0);
        }
        if(snake[x][y]==-1)
        {
            fruits= 0;
            score+=10;
            Tail -=1;
        }
        Head++;
        snake[x][y]=Head;
    }
    if(dir == 's')
    {
        x++;
        if(x==N-1)
        {
            x = 1;
        }
        if(snake[x][y]!=0 && snake[x][y]!=-1)
        {
            GameOver();
            printf("\n\n\n\t\t\tScore : %d",score);
            exit(0);
        }
        if(snake[x][y]==-1)
        {
            fruits= 0;
            score+=10;
            Tail -=1;
        }
        Head++;
        snake[x][y]=Head;
    }
    if(dir == 'a')
    {
        y--;
        if(y==0)
        {
            y=M-1;
        }
        if(snake[x][y]!=0 && snake[x][y]!=-1)
        {
            GameOver();
            printf("\n\n\n\t\t\tScore : %d",score);
            exit(0);
        }
        if(snake[x][y]==-1)
        {
            fruits= 0;
            score+=10;
            Tail -=1;
        }
        Head++;
        snake[x][y]=Head;
    }
    if(dir == 'w')
    {
        x--;
        if(x == 0)
        {
            x = N-1;
        }
        if(snake[x][y]!=0 && snake[x][y]!=-1)
        {
            GameOver();
            printf("\n\n\n\t\t\tScore : %d",score);
            exit(0);
        }
        if(snake[x][y]==-1)
        {
            fruits= 0;
            score+=10;
            Tail -=1;
        }
        Head++;
        snake[x][y]=Head;
    }

}
void BodyRemove()
{
    for(i=1;i<N;i++)
    {
        for(j=1;j<M;j++)
        {
            if(snake[i][j]==Tail)
            {
                snake[i][j] = 0;
            }
        }
    }
    Tail++;
}
void GameOver()
{

    system("cls");
    printf("\n\n\t\t\t GAME IS THE OVER !!!!!");
}
int main()
{
    Snake_Screen();
    while(game!=1)
    {
        print();
        ResetScreenPosition();
        Random();
        movement();
        BodyRemove();
        sleep(0.9);
    }
    return 0;
}

