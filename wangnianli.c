#include<stdio.h>


int mounth_day[13] = {0,31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};


int Ping_Run_Year(int year)
{
    if(year % 100 == 0)
    {
        return year % 400 == 0 ? 1 : 0;
    }
    else {
        return year % 4 == 0 ? 1 : 0;
    }
}


int First_Of_Month(int year , int month)
{
    extern int mounth_day[13];
    int alldays = 0;
    for(int i = 1 ; i < year ; ++i)
    {
        alldays += 365+Ping_Run_Year(i);
    }
    for(int i = 1 ; i < month ; ++i)
    {
        if (i == 2)
        {
            alldays += Ping_Run_Year(year);
        }
        alldays += mounth_day[i];
    }
    return (alldays+1) % 7 ;  //周日�?0
}


int Days(int year , int month)
{
    extern int mounth_day[13];
    if (month != 2)
    {
        return mounth_day[month];
    }else{
        return 28+Ping_Run_Year(year);
    }
}


int main()
{
    int year , month;
    printf("input the year:");
    scanf("%d",&year);
    printf("\ninput the month:");
    scanf("%d",&month);
    while (year > 0 && month > 0 && month < 13)
    {
        int day = First_Of_Month(year,month);
        int days = Days(year , month);
        printf(" Sun Mon Tue Wed Thu Fir Sat  \n");
        for(int j = 0 ; j < day ; ++j)
        {
            printf("    ");
        }
        for(int i = 1 ; i <= days ; ++i)
        {
            day%7 == 0 ? printf("\n%4d",i) : printf("%4d", i);
            ++day;
        }
        printf("\n");
        printf("input the year:");
        scanf("%d",&year);
        printf("\ninput the month:");
        scanf("%d",&month);
    }
    return 0;
}