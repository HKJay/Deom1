/*
 * 2024.4.13
 * ¶şÎ¬Êı×éÅÅĞò
 */
#include<stdio.h>
void X_Sort(char *xlist , int len)
{
    int min = 0 ;
    char zj;
    for(int k = 0 ; k < len ; ++k)
    {
        for(int i = k ; i < len ; ++i)
        {
            if((int)xlist[i] < (int)xlist[min])
            {
                min = i;
            }
        }
        zj = xlist[k];
        xlist[k] = xlist[min];
        xlist[min] = zj;
        min=k+1;
    }
}
void Y_Sort(int *key , int *value , int len)
{
    int min = 0 , zj1 , zj2;
    for(int i = 0 ; i < len ; ++i)
    {
        for(int k = i ; k < len ; ++k)
        {
            if(value[k] < value[min])
            {
                min = k;
            }
        }
        zj1 = value[i];
        zj2 = key[i];
        value[i] = value[min];
        value[min] = zj1;
        key[i] = key[min];
        key[min] = zj2;
        min = i+1;
    }
}
int main()
{
    int x , y;
    printf("input x:");
    scanf("%d",&x);
    printf("input y:");
    scanf("%d",&y);
    int key[x] , value[x];
    char list[x][y];
    for(int i = 0 ; i < x ; ++i)
    {
        for(int j = 0 ; j < y ; ++j)
        {
            scanf("%c",&list[i][j]);
            while(list[i][j] == '\n' || list[i][j] == ' ')
            {
                list[i][j] = getchar();
            }
            value[i] += (int)list[i][j];
        }
    }
    for(int i = 0 ; i < x ; ++i)
    {
        X_Sort(list[i] , y);
    }
    for(int i = 0 ; i < x ; ++i)
    {
        key[i] = i;
    }
    Y_Sort(key , value , x);
    for(int i = 0 ; i < x ; ++i)
    {
        for(int j = 0 ; j < y ; ++j)
        {
            printf("%c  ",list[key[i]][j]);
        }
        printf("\n");
    }
}
/*
S D U Y E S 
C H I N A ! 
A F T E R X 
h e r o a b 
C y y D S ! 
*/