/*
 * 2024.4.13
 * æÿ’Û≥À∑®
 */
#include<stdio.h>
#define FOR(a,b) for(int a = 0 ; a < b ; ++a) 
void matrix_multi(double A[3][4], double B[4][5], double C[3][5])
{
    double zj;
    for(int i = 0 ; i < 3 ; ++i)
    {
        for(int j = 0 ; j < 5 ; ++j)
        {
            zj = 0;
            for(int k = 0 ; k < 4 ; ++k)
            {
                zj += A[i][k] * B[j][i];
                //printf("\033[31m A %f  , B %lf\n\033[0m" , A[i][k] , B[k][j]);
            }
            C[i][j] = zj;
        }
    }
}
int main()
{
    double list_A[3][4] , list_B[4][5] , list_C[3][5];
    printf("Input A\n");
    FOR(i , 3)
    {
        FOR(j , 4)
        {
            scanf("%lf" , &list_A[i][j]);
        }
    }
    printf("Input B\n");
    FOR(i , 4)
    {
        FOR(j , 5)
        {
            scanf("%lf" , &list_B[i][j]);
        }
    }
    matrix_multi(list_A , list_B , list_C);
    printf("C:\n");
    FOR(i , 3)
    {
        FOR(j , 5)
        {
            printf("%f  " , list_C[i][j]);
        }
        printf("\n");
    }
}