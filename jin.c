#include<stdio.h>
#include<string.h>
#define NUM 3
int qipan[NUM][NUM] = {0};
int Input_Qipan(int x , int y , int player)
{
    extern int qipan[NUM][NUM];
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
    for(int i = 0 ; i < NUM ; ++i )
    {
        if (qipan[x-1][i] == player)
        {
            ++xt;
        }
        if (qipan[i][y-1] == player)
        {
            ++yt;
        }
    }
    for(int i = 0 ; i < NUM ; ++i)
    {
        if(qipan[i][i] == player)
        {
            ++xyt;
        }
        if(qipan[i][2-i] == player)
        {
            ++fxyt;
        }
    }
    if (xt == NUM || yt == NUM || xyt == NUM || fxyt == NUM)
    {
        return 1;
    }else{
        return 0;
    }
}
void Print_Qipan()
{
    printf("------------\n");
    for(int i = 0 ; i < NUM ; ++i)
    {
        printf("|");
        for(int j = 0 ; j < NUM ; ++j)
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
        printf("------------\n");
    }
}
int Full()
{
    int pd = 0;
    for(int i = 0 ; i < NUM ; ++i)
    {
        for(int j = 0 ; j < NUM ; ++j)
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
    while(1)
    {
        printf("Player %d enters coordinates:",player);
        scanf("%d,%d" , &x , &y);
        zy = Input_Qipan(x , y , player);
        while(zy == -1) //判断是否被占用
        {
            printf("The coordinates have been occupied, please re-enter:");
            scanf("%d,%d" , &x , &y);
            zy = Input_Qipan(x , y , player);
        }
        Print_Qipan();
        win = Jian_Cha(x , y , player);
        if(win == 1)
        {
            printf("Game over, player %d wins.\n",player); 
            memset(qipan , 0 ,sizeof(qipan));
            player = 1;
        }else{
            player = player % 2 + 1;
        }
        if(Full() == 1)
        {
            printf("Game over, the board is full.\n"); 
            memset(qipan , 0 ,sizeof(qipan));
            player = 1;
        }
    }
    return 0;
}