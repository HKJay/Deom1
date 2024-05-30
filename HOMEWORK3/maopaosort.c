/*
 * 2024.4.13
 * ·ÇµÝ¹é°æ±¾µÄÃ°ÅÝÅÅÐò
 */
#include<stdio.h>
void sort(int* list , int len)
{
    int zj , i = 0 , flag = 0;
    while(i < len - 1 && flag == 0)
    {
        flag = 1;
        for(int j = 0 ; j < len - i - 1 ; ++j )
        {
            if(list[j] > list[j + 1])
            {
                zj = list[j];
                list[j] = list[j + 1];
                list[j + 1] = zj;
                flag = 0;
            }
        }
        ++i;
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