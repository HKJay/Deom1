/*
 *2024.4.13 
 *非递归版本的选择排序
 */
#include<stdio.h>
void sort(int* list , int len)
{
    int min = 0 , zj;
    for(int i = 0 ; i < len-1 ; ++i)
    {
        for(int j = i ; j < len ; ++j)
        {
            if(list[j] < list[min])
            {
                min = j;
            }
        }
        zj = list[i];
        list[i] = list[min];
        list[min] = zj;
        min = i + 1;
    } 
}
int main()
{
    int len;
    printf("Input the len:");
    scanf("%d" , &len);
    int list[len];
    for(int i = 0 ; i < len ; ++i)
    {
        scanf("%d",&list[i]);
    }
    sort(list , len);
    for(int i = 0 ; i < len ; ++i)
    {
        printf("%d ",list[i]);
    }
    return 0;
}