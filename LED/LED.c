#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"LED.h"


char * cut(char * a , int n )
{
    char * re = (char *)malloc(sizeof(char)*(n+1));
    for (int i = 0 ; i < n ; ++i)
    {
        re[i] = a[i];
    }
    re[n] = '\0';
    return re;
}
void Delay(int times)
{
    clock_t start_time = clock();
    while(clock() < start_time + times);
}

char * plus(char* a , int num)
{
    int alen = strlen(a);
    char * re = (char *)malloc(sizeof(char)*(alen+num+1));
    for(int i = 0 ; i < alen; ++i)
    {
        re[i] = a[i];
    }
    for(int i = 0 ; i < num ; ++i)
    {
        re[alen + i] = ' ';
    }
    re[alen+num] = '\0';
    return re;
}

char * newcat(char* a , int num)
{
    int len = strlen(a);
    char * re = (char *)malloc(sizeof(char)*(len + 1));
    for(int i = num ; i < len ; ++i)
    {
        re[i - num] = a[i];
    }
    for(int j = 0 ; j < num ; ++j)
    {
        re[len - num + j] = a[j];
    }
    re[len] = '\0';
    return re;
}

char * cat(char* a , char* b)
{
    int alen = strlen(a);
    int blen = strlen(b);
    char * re = (char *)malloc(sizeof(char)*(alen+blen+1));
    for(int i = 0 ; i <= alen ; ++i)
    {
        re[i] = a[i];
    }
    for(int i = 0 ; i <= blen ; ++i)
    {
        re[i + alen] = b[i];
    }
    re[alen+blen] = '\0';
    //free(a);
    return re;
}


int main()
{
    char input;
    char print1[] = "\0";
    char print2[] = "\0";
    char print3[] = "\0";
    char print4[] = "\0";
    char print5[] = "\0";
    char print6[] = "\0";
    char print7[] = "\0";
    char * print[7] ={print1,print2,print3,print4,print5,print6,print7};
    input = getchar();
    while(input != '\n')
    {
        char (*append)[14];
        switch (input)
        {
        case ' ':
            append = NO;
            break;
        case 'A':
            append = A;
            break;
        case 'B':
            append = B;
            break;
        case 'C':
            append = C;
            break;
        case 'D':
            append = D;
            break;
        case 'E':
            append = E;
            break;
        case 'F':
            append = F;
            break;
        case 'G':
            append = G;
            break;
        case 'H':
            append = H;
            break;
        case 'I':
            append = I;
            break;
        default:
            break;
        }
        for(int i = 0 ; i < 7 ; ++i)
        {
            print[i] = cat(print[i] , append[i]);
        }
        input = getchar();
    }
    int all_len = strlen(print[0]);
    for(int i = 0 ; i <7 ; ++i)
    {
        if(all_len < 101)
        {
            print[i] = plus(print[i] , 101-all_len);
        }
    }
    char *cutp;
    while(1)
    {
        for(int i = 0 ; i < all_len  ; ++i)
        {
            system("cls");
            for(int j = 0 ; j < 7 ; ++j)
            {
                cutp = cut(print[j] , 101);
                print[j] = newcat(print[j] , 1);
                printf("\033[31m");
                printf("%s\n" , cutp);
                printf("\033[0m");
            }
            Delay(100);
        }
    }

}