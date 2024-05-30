/*
**调用头文件
*/
#include<stdio.h>
#include"module.h"
int main()
{
    int ab = func1();
    int b = func2();
    printf("The num:%d\n" , a);
    printf("Call function module_a():%d\n" , ab);
    printf("Call function module_b():%d\n" , b);
    return 0;
}