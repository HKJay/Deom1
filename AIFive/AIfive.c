#define DESIRE_VICTORY 0.6
#include"AIFIVE.H"
#include<stdio.h>
#include<string.h>
#define QIPANNUM 15
#define NUM 5
int qipan[QIPANNUM][QIPANNUM] = {0};
int Input_Qipan(int x , int y , int player)
{
    extern int qipan[QIPANNUM][QIPANNUM];
    if(qipan[x-1][y-1] == 0)
    {
        qipan[x-1][y-1] = player;
    }else{
        return -1;
    }
    return 0;
}
int Jian_Cha(int x , int y , int player)
{
    int xt = 0 , yt = 0 , xyt = 0 , fxyt = 0;
    int mxt = 0 , myt = 0 , mxyt = 0 , mfxyt = 0;
    int jcx = x - 1 , jcy = y - 1 , jia = 0;
    for(int i = 0 ; i < QIPANNUM ; ++i )
    {
        if (qipan[x-1][i] == player)
        {
            ++xt;
        }else
        {
            mxt = xt > mxt ? xt : mxt;
            xt = 0;
        }
        if (qipan[i][y-1] == player)
        {
            ++yt;
        }else
        {
            myt = yt > myt ? yt : myt;
            yt = 0;
        }
    }
    while (jcx != 0 && jcy != 0)
    {
        --jcx;
        --jcy;
    }
    while (jcx + jia < QIPANNUM && jcy + jia < QIPANNUM)
    {
        if (qipan[jcx + jia][jcy + jia] == player)
        {
            ++xyt;
        }else
        {
            mxyt = xyt > mxyt ? xyt : mxyt;
            xyt = 0;
        }
        ++jia;
    }
    jcx = x - 1;
    jcy = y - 1;
    jia = 0;
    while (jcx != 0 && jcy != QIPANNUM - 1)
    {
        --jcx;
        ++jcy;
    }
    while (jcx + jia < QIPANNUM && jcy + jia > -1)
    {
        if (qipan[jcx + jia][jcy - jia] == player)
        {
            ++fxyt;
        }else
        {
            mfxyt = fxyt > mfxyt ? fxyt : mfxyt;
            fxyt = 0;
        }
        ++jia;
    }
    if (mxt == NUM || myt == NUM || mxyt == NUM || mfxyt == NUM)
    {
        return 1;
    }else{
        return 0;
    }
}
void Print_Qipan()
{
    printf("\033[33m   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15 \n\033[0m");
    printf("  -----------------------------------------------------------\n");
    for(int i = 0 ; i < QIPANNUM ; ++i)
    {
        printf("\033[33m%2d\033[0m" , i + 1);
        printf("|");
        for(int j = 0 ; j < QIPANNUM ; ++j)
        {
            if (qipan[i][j] == 1)
            {
                printf("\033[31m%d \033[0m| " , qipan[i][j]);
            }else if (qipan[i][j] == 2)
            {
                printf("\033[32m%d \033[0m| " , qipan[i][j]);
            }else
            {
                printf("%d | " , qipan[i][j]);
            }

        }
        printf("\n");
        printf("  ------------------------------------------------------------\n");
    }
}
int Full()
{
    int pd = 0;
    for(int i = 0 ; i < QIPANNUM ; ++i)
    {
        for(int j = 0 ; j < QIPANNUM ; ++j)
        {
            if (qipan[i][j] == 0)
            {
                ++pd;
            }
        }
    }
    return pd !=0 ? 0 : 1;
}
int main()
{
    int player = 1;
    int x , y , zy;
    int win = 0;
    Print_Qipan();
    while(1)
    {
        printf("enters coordinates:");
        scanf("%d,%d" , &x , &y);
        zy = Input_Qipan(x , y , player);
        while(zy == -1) //判断是否被占用
        {
            printf("The coordinates have been occupied, please re-enter:");
            scanf("%d,%d" , &x , &y);
            zy = Input_Qipan(x , y , player);
        }
        win = Jian_Cha(x , y , player);
        if(win == 1)
        {
            Print_Qipan();
            printf("Game over, you wins.\n"); 
            memset(qipan , 0 ,sizeof(qipan));
            continue;
        }
        int *location = AI_five(qipan,player,x,y);
        Input_Qipan(location[0]+1 , location[1]+1 , 2);
        win = Jian_Cha(location[0]+1 , location[1]+1 , 2);
        if(win == 1)
        {
            Print_Qipan();
            printf("Game over, AI wins.\n"); 
            memset(qipan , 0 ,sizeof(qipan));
            continue;
        }
        if(Full() == 1)
        {
            printf("Game over, the board is full.\n"); 
            memset(qipan , 0 ,sizeof(qipan));
            player = 1;
        }
        Print_Qipan();
        printf("AI location: %d,%d\n" , location[0]+1 , location[1]+1);
    }
    return 0;
}