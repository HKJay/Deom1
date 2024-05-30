/*
 * 2024.4.13
 * ∞Àª ∫ÛŒ Ã‚
 */
#include<stdio.h>
int main()
{
    int Eight_queen(int qp[8][8] , int n);
    int qipan[8][8] = {0};
    int num = Eight_queen(qipan,7);
    printf("total:%d",num);
    return 0;
}
int Eight_queen(int qp[8][8] , int n)
{
    int nums = 0 ; 
    if (n != 0)
    {
        int new_qp[8][8];
        int z , y , k;
        for(int i = 0 ; i < 8 ; ++i)
        {
            z = 0 ;
            y = 0 ;
            for(int i = 0 ; i < 8 ; ++i)
            {
                for(int j = 0 ; j < 8 ; ++j)
                {
                    new_qp[i][j] = qp[i][j];
                }
            }
            if(new_qp[n][i] == 0)
            {
                z = i - 1;
                y = i + 1;
                k = n - 1 ;
                for(int l = n ; l >= 0 ; --l)
                {
                    new_qp[l][i] = 2;
                }
                while(z != -1 && k != -1)
                {
                    new_qp[k][z] = 2;
                    --z;
                    --k;
                }
                k = n -1;
                while(y != 8 && k != -1)
                {
                    new_qp[k][y] = 2;
                    ++y;
                    --k;
                }
                new_qp[n][i] = 1;
                nums += Eight_queen(new_qp,n-1);
            }
        }
    }else
    {
        for(int i = 0 ; i < 8 ; ++i)
        {
            if(qp[0][i] == 0)
            {
                nums += 1;
                qp[0][i] = 1;
                for(int i = 0 ; i < 8 ; ++i)
                {
                    for(int j = 0 ; j < 8 ; ++j)
                    {
                        if (qp[i][j] == 1)
                        {
                            printf("\033[31m*\033[0m");
                        }else
                        {
                            printf("0");
                        }
                    }
                    printf("\n");
                }
                printf("\n");
            }
        }
    }
    return nums;
}