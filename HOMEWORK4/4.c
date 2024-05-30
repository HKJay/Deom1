/*
**输出单词数量
**/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char endp[] = "END";
    char endh[] = "E_N_D";
    char* lists[100][100];
    char* wordlist[100];
    int wordnum = -1;
    int flag;
    int n = 0 , i = 0;
    while(1)
    {
        flag = 0;
        char *p = (char*)malloc(sizeof(char)*101);
        char *m = (char*)malloc(sizeof(char)*101);
        scanf("%s" , p);
        scanf("%c" , m);
        if(strcmp(p , endp) == 0)
        {
            break;
        }
        lists[n][i] = p;
        for(int j = 0 ; j <= wordnum ; ++j)
        {
            if(strcmp(wordlist[j] , p) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            ++wordnum;
            wordlist[wordnum] = p;
        }
        ++i;
        if(*m == '\n')
        {
            lists[n][i] = "E_N_D";
            ++n;
            i = 0;
        }
    } 
    int nums[n+1][wordnum+1];
    int znum[wordnum+1];
    memset(nums , 0 ,sizeof(nums));
    memset(znum , 0 ,sizeof(znum));
    for (int i = 0 ; i < n ; ++i)
    {
        for(int j = 0 ; strcmp(lists[i][j] , endh) != 0 ; ++j)
        {
            for(int k = 0 ; k <= wordnum ; ++k)
            {
                if(strcmp(lists[i][j] , wordlist[k]) == 0)
                {
                    nums[i][k] += 1;
                    znum[k] += 1;
                }
            }
        }
    }
    for(int i = 0 ; i < n ; ++i)
    {
        for(int k = 0 ; k <= wordnum ; ++k)
        {
            if(nums[i][k] != 0)
            {
                printf("The line %d:word %s:%d\n" , i+1 , wordlist[k] , nums[i][k]);
            }
        }
    }
     for(int k = 0 ; k <= wordnum ; ++k)
    {
        if(nums[i][k] != 0)
        {
            printf("word %s:%d\n" , wordlist[k] , znum[k]);
        }
    }
    return 0;
}