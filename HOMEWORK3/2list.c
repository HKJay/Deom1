/*
 * 2024.4.13
 * ����ά�����ڴ澵��
 */
#include<stdio.h>
void Oprint( int A[6] )
{
    for(int i = 0 ; i < 6 ; ++i)
    {
        printf("%d" , A[i]);
    }
}
int main()
{
    int A[2][3] = {{1,2,3},{4,5,6}};
    Oprint(A);
    return 0;

}