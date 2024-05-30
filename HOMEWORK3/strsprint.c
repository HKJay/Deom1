/*
 * 2024.4.13
 * 输出不确定字符
 */
#include<stdio.h>
int main()
{
    int Print_E() , Print_F() , Print_L();//声明函数
    char letter;
    letter = getchar();//获取字符
    printf("\033[s");
    while(letter == 'E' || letter == 'F' || letter == 'L')
    {
        if(letter == 'E')//字符判断
        {
            Print_E();
        }else if(letter == 'F')
        {
            Print_F();
        }else if(letter == 'L')
        {
            Print_L();
        }
        letter = getchar();
    }
    printf("\033[7B");
    return 0;
}

/*
 * 打印E
 */
int Print_E()
{
    printf("\033[u");
    printf("\033[u\033[1B\033[31m*********\n");
    printf("\033[u\033[2B\033[31m*\n");
    printf("\033[u\033[3B\033[31m*\n");
    printf("\033[u\033[4B\033[31m*********\n");
    printf("\033[u\033[5B\033[31m*\n");
    printf("\033[u\033[6B\033[31m*\n");
    printf("\033[u\033[7B\033[31m*********\033[0m");
    printf("\033[1C\033[7A\033[s");
    return 0 ;   
}

/*
 * 打印F
 */
int Print_F()
{
    printf("\033[u");
    printf("\033[31m");
    printf("\033[u\033[1B\033[31m*********");
    printf("\033[u\033[2B\033[31m*");
    printf("\033[u\033[3B\033[31m*");
    printf("\033[u\033[4B\033[31m*********");
    printf("\033[u\033[5B\033[31m*");
    printf("\033[u\033[6B\033[31m*");
    printf("\033[u\033[7B\033[31m*\033[0m");
    printf("\033[9C\033[7A\033[s");
    return 0 ;   
}

/*
 * 打印L
 */
int Print_L()
{
    printf("\033[u");
    printf("\033[31m");
    printf("\033[u\033[1B\033[31m*\n");
    printf("\033[u\033[2B\033[31m*\n");
    printf("\033[u\033[3B\033[31m*\n");
    printf("\033[u\033[4B\033[31m*\n");
    printf("\033[u\033[5B\033[31m*\n");
    printf("\033[u\033[6B\033[31m*\n");
    printf("\033[u\033[7B\033[31m*********\033[0m");
    printf("\033[1C\033[7A\033[s");
    return 0 ;   
}