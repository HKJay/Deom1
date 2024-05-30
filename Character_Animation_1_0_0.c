/*
** 2024.4
** Character Animation
** Verson 1.0.0
**/


#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define NUMBER_OF_COMMAND 5
#define MAX_OF_STEP 100
#define CLEAR "cls"

//延迟函数
void Delay(int times)
{
    clock_t start_time = clock();
    while(clock() < start_time + times);
}

//读入
int Read(int (*s)[NUMBER_OF_COMMAND] , int step)
{
    char mov[] = "mov" , change[] = "change" , color[] = "color" , flicker[] = "flicker" , unflicker[] = "unflicker" , record[] = "record" , show[] = "show" , restart[] = "restart";
    char change_char;
    char color_char;
    char command[10];
    int x = 0 , y = 0;
    int str , colors;
    int flag = 0; // 1表示mov，2表示change，3表示color，4表示flicker，5表示record，6表示show
    scanf("%s" , command);
    if(strcmp(command , mov) == 0)
    {
        flag = 1;
        scanf("%d" , &x);
        scanf("%d" , &y);
        s[step][0] += x;
        s[step][1] += y;
    }else if(strcmp(command , change) == 0)
    {
        flag = 2;
        change_char = getchar();
        while (change_char == ' ')
        {
            change_char = getchar();
        }
        switch(change_char)
        {
            case 'T':
                str = 0;
                s[step][2] = str;
                break;
            case 'E':
                str = 1;
                s[step][2] = str;
                break;
            case 'L':
                str = 2;
                s[step][2] = str;
                break;
            default:
                printf("Please Input \'T\' or \'E\' or \'L\'! \n");
                flag = -1;
                break;
        }
    }else if(strcmp(command , color) == 0)
    {
        flag = 3;
        color_char = getchar();
        while (color_char == ' ')
        {
            color_char = getchar();
        }
        switch(color_char)
        {
            case 'W':
                colors = 0;
                s[step][3] = colors;
                break;
            case 'R':
                colors = 1;
                s[step][3] = colors;
                break;
            case 'G':
                colors = 2;
                s[step][3] = colors;
                break;
            case 'Y':
                colors = 3;
                s[step][3] = colors;
                break;
            default:
                printf("Please Input \'W\' or \'R\' or \'G\' or \'Y\'! \n");
                flag = -1;
                break;

        }
    }else if(strcmp(command , flicker) == 0)
    {
        flag = 4;
    }else if(strcmp(command , unflicker) == 0)
    {
        flag = 5;
    }else if(strcmp(command , record) == 0)
    {
        flag = 6;
    }else if(strcmp(command , show) == 0)
    {
        flag = 7;
    }else if(strcmp(command , restart) == 0)
    {
        flag = 8;
    }else
    {
        printf("invalid command!\n");
        flag = -1;
    }
    return flag;
}


//打印T
int Show_T(int x , int y , int colors)
{
    //printf("\033[s");
    system(CLEAR);
    switch (colors)
    {
    case 0:
        printf("\033[0m");
        break;
    case 1:
        printf("\033[31m");
        break;
    case 2:
        printf("\033[32m");
        break;
    case 3:
        printf("\033[33m");
        break;
    default:
        break;
    }
    for(int i = 0 ; i < y ; ++i)
    {
        printf("\n");
    }
    for(int j = 0 ; j < x ; ++j)
    {
        printf(" ");
    }
    printf("* * * * * * * * *\n");
    for(int i = 0 ; i < 6 ; ++i)
    {
        for(int j = 0 ; j < x ; ++j)
        {
            printf(" ");
        }
        printf("        *        \n");
    }
    printf("\033[0m");
    return 0;
}

//打印E
int Show_E(int x , int y , int colors)
{
    //printf("\033[s");
    system(CLEAR);
    switch (colors)
    {
    case 0:
        printf("\033[0m");
        break;
    case 1:
        printf("\033[31m");
        break;
    case 2:
        printf("\033[32m");
        break;
    case 3:
        printf("\033[33m");
        break;
    default:
        break;
    }
    for(int i = 0 ; i < y ; ++i)
    {
        printf("\n");
    }
    for(int j = 0 ; j < x ; ++j)
    {
        printf(" ");
    }
    printf("* * * * * * * * *\n");
    for(int i = 0 ; i < 2 ; ++i)
    {
        for(int j = 0 ; j < x ; ++j)
        {
            printf(" ");
        }
        printf("*\n");
    }
    for(int j = 0 ; j < x ; ++j)
    {
        printf(" ");
    }
    printf("* * * * * * * * *\n");
    for(int i = 0 ; i < 2 ; ++i)
    {
        for(int j = 0 ; j < x ; ++j)
        {
            printf(" ");
        }
        printf("*\n");
    }
    for(int j = 0 ; j < x ; ++j)
    {
        printf(" ");
    }
    printf("* * * * * * * * *\n");
    printf("\033[0m");
    return 0;
}

//打印L
int Show_L(int x , int y , int colors)
{
    //printf("\033[s");
    system(CLEAR);
    switch (colors)
    {
    case 0:
        printf("\033[0m");
        break;
    case 1:
        printf("\033[31m");
        break;
    case 2:
        printf("\033[32m");
        break;
    case 3:
        printf("\033[33m");
        break;
    default:
        break;
    }
    for(int i = 0 ; i < y ; ++i)
    {
        printf("\n");
    }
    for(int i = 0 ; i < 7 ; ++i)
    {
        for(int j = 0 ; j < x ; ++j)
        {
            printf(" ");
        }
        printf("*\n");
    }
    for(int j = 0 ; j < x ; ++j)
    {
        printf(" ");
    }
    printf("* * * * * *\n");
    printf("\033[0m");
    return 0;
}

//记录
int Record(int (*s)[NUMBER_OF_COMMAND] , int step)
{
    ++step;
    int zj;
    for(int i = 0 ; i < NUMBER_OF_COMMAND ; ++i)
    {
        zj = s[step-1][i];
        s[step][i] = zj;
    }
    s[step][4] = 0;
    return step;
}

//闪烁
int Flicker(int (*s)[NUMBER_OF_COMMAND] , int step)
{
    //printf("\033[s");
    int zj = s[step][3];
    for(int i = 0 ; i < 3 ; ++i)
    {
        s[step][3] = i;
        switch (s[step][2])
        {
            case 0:
                //printf("\033[u");
                Show_T(s[step][0] , s[step][1] , s[step][3]);
                break;
            case 1:
                //printf("\033[u");
                Show_E(s[step][0] , s[step][1] , s[step][3]);
                break;
            case 2:
                //printf("\033[u");
                Show_L(s[step][0] , s[step][1] , s[step][3]);
                break;
            default:
                break;
        }
        Delay(500);
    }
    s[step][3] = zj;
    //printf("\033[u");
    switch (s[step][2])
    {
        case 0:
            Show_T(s[step][0] , s[step][1] , s[step][3]);
            break;
        case 1:
            Show_E(s[step][0] , s[step][1] , s[step][3]);
            break;
        case 2:
            Show_L(s[step][0] , s[step][1] , s[step][3]);
            break;
        default:
            break;
    }
    return 0;
}

//取消闪烁
int UnFlicker(int (*s)[NUMBER_OF_COMMAND] , int step)
{
    s[step][4] = 0;
    switch (s[step][2])
    {
        case 0:
            Show_T(s[step][0] , s[step][1] , s[step][3]);
            break;
        case 1:
            Show_E(s[step][0] , s[step][1] , s[step][3]);
            break;
        case 2:
            Show_L(s[step][0] , s[step][1] , s[step][3]);
            break;
        default:
            break;
    }
    return 0;
}

//播放
int Show(int (*s)[NUMBER_OF_COMMAND] , int step , int speed)
{
    if(step == 0)
    {
        printf("You haven\'t record anything!");
        Delay(3000);
        return -1;
    }
    for(int i = 0 ; i < step ; ++i)
    {
        switch (s[i][2])
        {
            case 0:
                Show_T(s[i][0] , s[i][1] , s[i][3]);
                break;
            case 1:
                Show_E(s[i][0] , s[i][1] , s[i][3]);
                break;
            case 2:
                Show_L(s[i][0] , s[i][1] , s[i][3]);
                break;
            default:
                break;
        }
        if(s[i][4] == 1)
        {
            Flicker(s , i);
        }
        Delay(speed);
    }
    return 0;
}

//重新开始
int Restart(int (*s)[NUMBER_OF_COMMAND])
{
    for(int i = 0 ; i < NUMBER_OF_COMMAND ; ++i)
    {
        s[0][i] = 0;
    }
    switch (s[0][2])
    {
        case 0:
            Show_T(s[0][0] , s[0][1] , s[0][3]);
            break;
        case 1:
            Show_E(s[0][0] , s[0][1] , s[0][3]);
            break;
        case 2:
            Show_L(s[0][0] , s[0][1] , s[0][3]);
            break;
        default:
            break;
    }
    return 0;
}


int main()
{
    int flag = 0; // 1表示mov，2表示change，3表示color，4表示flicker，5表示unflicker ，6表示record，7表示show
    int s[MAX_OF_STEP][NUMBER_OF_COMMAND] = {0};  //分别存入x,y,str,color,flicker
    int step = 0 , speed = 500;
    char waste; //用于清空缓冲区
    Show_T(s[step][0] , s[step][1] , s[step][3]);
    while (1)
    {
        //读入命令
        flag = Read(s , step);
        if(flag == -1)
        {
            continue;
        }

        //执行命令
        switch(flag)
        {
            case 1:
            case 2:
            case 3:
                switch (s[step][2])
                {
                    case 0:
                        Show_T(s[step][0] , s[step][1] , s[step][3]);
                        break;
                    case 1:
                        Show_E(s[step][0] , s[step][1] , s[step][3]);
                        break;
                    case 2:
                        Show_L(s[step][0] , s[step][1] , s[step][3]);
                        break;
                    default:
                        break;
                }
                break;
            case 4:
                s[step][4] = 1;
                Flicker(s , step);
                break;
            case 5:
                UnFlicker(s , step);
                break;
            case 6:
                step = Record(s , step);
                switch (s[step][2])
                {
                    case 0:
                        Show_T(s[step][0] , s[step][1] , s[step][3]);
                        break;
                    case 1:
                        Show_E(s[step][0] , s[step][1] , s[step][3]);
                        break;
                    case 2:
                        Show_L(s[step][0] , s[step][1] , s[step][3]);
                        break;
                    default:
                        break;
                }
                break;
            case 7:
                Show(s , step , speed);
                break;
            case 8:
                step = Restart(s);
                break;


        }
        while(scanf("%c" , &waste ) && waste != '\n');
    }
    return 0;
}