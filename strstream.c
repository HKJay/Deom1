#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
#include <windows.h>  
  
#define WIDTH 30
#define HEIGHT 30
#define TAIL 5
#define DELAY 1

void drawMatrix(char (*s)[WIDTH] , int n) {  
    char chars[] = "*               "; // 你可以添加更多字符  
    int index , h;
    int records[WIDTH] = {0};
    char c[WIDTH] = {' '};  
    for(int i = 0 ; i < WIDTH ; ++i)
    {
        if (records[i] != 0) continue; 
        index = rand() % (strlen(chars)); // 随机选择字符  
        s[n][i] = chars[index];
    }
    for(int i = 0 ; i < HEIGHT ; ++i)
    {
        h = (n + i) % HEIGHT;
        for(int j = 0 ; j < WIDTH ; ++j)
        {
            if (s[h][j] == '*' && records[j] == 0)
            {
                printf("\033[32m%c\033[0m" , s[h][j]);
                c[j] = s[h][j];
                records[j] = TAIL;
            }else if (records[j] != 0)
            {
                printf("\033[32m%c\033[0m" , c[j]);
                --records[j];
            }else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
 
}  
  
int main() {  
    int t = 0 , n = 0;
    char l[HEIGHT][WIDTH] = {' '};
    while (1) { // 无限循环  
        drawMatrix(l , n); // 绘制字符矩阵 
        --t;
        n = HEIGHT + t % HEIGHT - 1; //循环打印
        t = t % HEIGHT;
        Sleep(DELAY); // 等待一段时间  
        system("cls");
    }  
  
    return 0;  
}