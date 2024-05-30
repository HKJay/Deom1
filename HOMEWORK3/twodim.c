/*
 * 2024.4.13
 * 对二维数组任意元素A[m,n]的访问
 */
#include<stdio.h>
int two_dim_array_access(int *x,int i, int j, int m ,int n,int C)
{
    int l = 0;
    for(int i = 0 ; i < m ; ++i)
    {
        l += C;
    }
    l += n;
    return x[l];
}
int main()
{
    int x , y , i , j , m , n ;
    printf("Input X:");
    scanf("%d" , &x);
    printf("Input Y:");
    scanf("%d" , &y);
    int list[x][y];
    for(int i = 0 ; i < x ; ++i)
    {
        for(int j = 0 ; j < y ; ++j)
        {
            scanf("%d" , &list[i][j]);
        }
    }
    printf("Input i:");
    scanf("%d" , &i);
    printf("Input j:");
    scanf("%d" , &j);
    printf("Input m:");
    scanf("%d" , &m);
    printf("Input n:");
    scanf("%d" , &n);
    printf("%d\n" , two_dim_array_access(list , i , j , m , n , y));
    return 0;
}