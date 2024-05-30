#ifndef AIFIVE_H
#define AIFIVE_H
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define AIQIPANNUM 15
#define AINUM 5
//#define DESIRE_VICTORY 0.5


int* AI_five(int qipan[AIQIPANNUM][AIQIPANNUM] , int player , int x_put , int y_put)
{
    int *location = (int *) malloc(sizeof(int) * 2);
    int weight[AIQIPANNUM][AIQIPANNUM][2] = {0};
    int flag_x_1 = 0 , flag_y_1 = 0;
    int player_weight_1 = 0 , player_weight_2 = 0;
    int x , y;
    int return_x = 7 , return_y = 7;

    for(int i = 0 ; i < AIQIPANNUM ; ++i)
    {
    
        if(qipan[i][y_put - 1] == player)
        {
            if(flag_x_1 == 1)
            {
                player_weight_1 = 1;
                flag_x_1 = 0;
            }else
            {
                player_weight_1 += 1;
            }
        }else if(qipan[i][y_put - 1] == 0)
        {
            weight[i][y_put - 1][0] += player_weight_1 > 0 ? player_weight_1 : 0;
            --player_weight_1;
            flag_x_1 = 1;
        }else
        {
            player_weight_1 = 0;
            flag_x_1 = 0;
        }


        if(qipan[x_put - 1][i] == player)
        {
            if(flag_y_1 == 1)
            {
                player_weight_2 = 1;
                flag_y_1 = 0;
            }else
            {
                player_weight_2 += 1;
            }
        }else if(qipan[x_put - 1][i] == 0)
        {
            weight[x_put - 1][i][0] += player_weight_2 > 0 ? player_weight_2 : 0;
            --player_weight_2;
            flag_y_1 = 1;
        }else
        {
            player_weight_2 = 0;
            flag_y_1 = 0;
        }
    }
    flag_x_1 = 0;
    flag_y_1 = 0;
    player_weight_1 = 0;
    player_weight_2 = 0;


    for(int i = AIQIPANNUM - 1 ; i >= 0 ; --i)
    {
        if(qipan[i][y_put - 1] == player)
        {
            if(flag_x_1 == 1)
            {
                player_weight_1 = 1;
                flag_x_1 = 0;
            }else
            {
                player_weight_1 += 1;
            }
        }else if(qipan[i][y_put - 1] == 0)
        {
            weight[i][y_put - 1][0] += player_weight_1 > 0 ? player_weight_1 : 0;
            --player_weight_1;
            flag_x_1 = 1;
        }else
        {
            player_weight_1 = 0;
            flag_x_1 = 0;
        }


        if(qipan[x_put - 1][i] == player)
        {
            if(flag_y_1 == 1)
            {
                player_weight_2 = 1;
                flag_y_1 = 0;
            }else
            {
                player_weight_2 += 1;
            }
        }else if(qipan[x_put - 1][i] == 0)
        {
            weight[x_put - 1][i][0] += player_weight_2 > 0 ? player_weight_2 : 0;
            --player_weight_2;
            flag_y_1 = 1;
        }else
        {
            player_weight_2 = 0;
            flag_y_1 = 0;
        }
    }
    flag_x_1 = 0;
    flag_y_1 = 0;
    player_weight_1 = 0;
    player_weight_2 = 0;


    for(int i = 0 ; i < AIQIPANNUM ; ++i)
    {
        for(int j = 0 ; j < AIQIPANNUM ; ++j)
        {
            if(qipan[i][j] == player)
            {
                if(flag_x_1 == 1)
                {
                    player_weight_1 = 1;
                    flag_x_1 = 0;
                }else
                {
                    player_weight_1 += 1;
                }
            }else if(qipan[i][j] == 0)
            {
                weight[i][j][0] += player_weight_1 > 0 ? player_weight_1*player_weight_1 : 0;
                --player_weight_1;
                flag_x_1 = 1;
            }else
            {
                player_weight_1 = 0;
                flag_x_1 = 0;
            }

            if(qipan[j][i] == player)
            {
                if(flag_y_1 == 1)
                {
                    player_weight_2 = 1;
                    flag_y_1 = 0;
                }else
                {
                    player_weight_2 += 1;
                }
            }else if(qipan[j][i] == 0)
            {
                weight[j][i][0] += player_weight_2 > 0 ? player_weight_2*player_weight_2 : 0;
                --player_weight_2;
                flag_y_1 = 1;
            }else
            {
                player_weight_2 = 0;
                flag_y_1 = 0;
            }
        }
    }

    flag_x_1 = 0;
    flag_y_1 = 0;
    player_weight_1 = 0;
    player_weight_2 = 0;
    for(int i = AIQIPANNUM - 1 ; i >= 0 ; --i)
    {
        for(int j = AIQIPANNUM - 1 ; j >= 0 ; --j)
        {
            if(qipan[i][j] == player)
            {
                if(flag_x_1 == 1)
                {
                    player_weight_1 = 1;
                    flag_x_1 = 0;
                }else
                {
                    player_weight_1 += 1;
                }
            }else if(qipan[i][j] == 0)
            {
                weight[i][j][0] += player_weight_1 > 0 ? player_weight_1*player_weight_1 : 0;
                --player_weight_1;
                flag_x_1 = 1;
            }else
            {
                player_weight_1 = 0;
                flag_x_1 = 0;
            }

            if(qipan[j][i] == player)
            {
                if(flag_y_1 == 1)
                {
                    player_weight_2 = 1;
                    flag_y_1 = 0;
                }else
                {
                    player_weight_2 += 1;
                }
            }else if(qipan[j][i] == 0)
            {
                weight[j][i][0] += player_weight_2 > 0 ? player_weight_2*player_weight_2 : 0;
                --player_weight_2;
                flag_y_1 = 1;
            }else
            {
                player_weight_2 = 0;
                flag_y_1 = 0;
            }
        }
    }

    for(int i = 0 ; i < AIQIPANNUM ; ++i)
    {
        flag_x_1 = 0;
        flag_y_1 = 0;
        player_weight_1 = 0;
        player_weight_2 = 0;
        x = i;
        y = 0;
        while(x < AIQIPANNUM && y < AIQIPANNUM)
        {
            if(qipan[x][y] == player)
            {
                if(flag_x_1 == 1)
                {
                    player_weight_1 = 1;
                    flag_x_1 = 0;
                }else
                {
                    player_weight_1 += 1;
                }
            }else if(qipan[x][y] == 0)
            {
                weight[x][y][0] += player_weight_1 > 0 ? player_weight_1*player_weight_1 : 0;
                if (x - x_put == y - y_put)
                {
                    weight[x][y][0] += player_weight_1 > 0 ? player_weight_1 : 0;
                }
                --player_weight_1;
                flag_x_1 = 1;
            }else
            {
                player_weight_1 = 0;
                flag_x_1 = 0;
            }

            if(x == y)
            {
                ++x;
                ++y;
                continue;
            };
            if(qipan[y][x] == player)
            {
                if(flag_y_1 == 1)
                {
                    player_weight_2 = 1;
                    flag_y_1 = 0;
                }else
                {
                    player_weight_2 += 1;
                }
            }else if(qipan[y][x] == 0)
            {
                weight[y][x][0] += player_weight_2 > 0 ? player_weight_2*player_weight_2 : 0;
                if (x - x_put == y - y_put)
                {
                    weight[y][x][0] += player_weight_2 > 0 ? player_weight_2 : 0;
                }
                --player_weight_2;
                flag_y_1 = 1;
            }else
            {
                player_weight_2 = 0;
                flag_y_1 = 0;
            }
            ++x;
            ++y;
        }
    }

    for(int i = AIQIPANNUM - 1; i >= 0 ; --i)
    {
        flag_x_1 = 0;
        flag_y_1 = 0;
        player_weight_1 = 0;
        player_weight_2 = 0;
        x = i;
        y = AIQIPANNUM - 1;
        while(x >= 0 && y >= 0)
        {
            if(qipan[x][y] == player)
            {
                if(flag_x_1 == 1)
                {
                    player_weight_1 = 1;
                    flag_x_1 = 0;
                }else
                {
                    player_weight_1 += 1;
                }
            }else if(qipan[x][y] == 0)
            {
                weight[x][y][0] += player_weight_1 > 0 ? player_weight_1*player_weight_1 : 0;
                if (x - x_put == y - y_put)
                {
                    weight[x][y][0] += player_weight_1 > 0 ? player_weight_1 : 0;
                }
                --player_weight_1;
                flag_x_1 = 1;
            }else
            {
                player_weight_1 = 0;
                flag_x_1 = 0;
            }

            if(x == y)
            {
                --x;
                --y;
                continue;
            };
            if(qipan[y][x] == player)
            {
                if(flag_y_1 == 1)
                {
                    player_weight_2 = 1;
                    flag_y_1 = 0;
                }else
                {
                    player_weight_2 += 1;
                }
            }else if(qipan[y][x] == 0)
            {
                weight[y][x][0] += player_weight_2 > 0 ? player_weight_2*player_weight_2 : 0;
                if (x - x_put == y - y_put)
                {
                    weight[y][x][0] += player_weight_2 > 0 ? player_weight_2 : 0;
                }
                --player_weight_2;
                flag_y_1 = 1;
            }else
            {
                player_weight_2 = 0;
                flag_y_1 = 0;
            }
            --x;
            --y;
        }
    }

    for(int i = 0 ; i < AIQIPANNUM ; ++i)
    {
        flag_x_1 = 0;
        flag_y_1 = 0;
        player_weight_1 = 0;
        player_weight_2 = 0;
        x = i;
        y = AIQIPANNUM - 1;
        while(x < AIQIPANNUM && y >= 0)
        {
            if(qipan[x][y] == player)
            {
                if(flag_x_1 == 1)
                {
                    player_weight_1 = 1;
                    flag_x_1 = 0;
                }else
                {
                    player_weight_1 += 1;
                }
            }else if(qipan[x][y] == 0)
            {
                weight[x][y][0] += player_weight_1 > 0 ? player_weight_1*player_weight_1 : 0;
                if (x + y + 2 == x_put  + y_put)
                {
                    printf("a");
                    weight[x][y][0] += (player_weight_1 > 0 ? player_weight_1 : 0);
                }
                --player_weight_1;
                flag_x_1 = 1;
            }else
            {
                player_weight_1 = 0;
                flag_x_1 = 0;
            }

            if(x + y == AIQIPANNUM - 1)
            {
                ++x;
                --y;
                continue;
            };
            if(qipan[y][x] == player)
            {
                if(flag_y_1 == 1)
                {
                    player_weight_2 = 1;
                    flag_y_1 = 0;
                }else
                {
                    player_weight_2 += 1;
                }
            }else if(qipan[y][x] == 0)
            {
                weight[y][x][0] += player_weight_2 > 0 ? player_weight_2*player_weight_2 : 0;
                if (x + y + 2 == x_put  + y_put)
                {
                    weight[y][x][0] += player_weight_2 > 0 ? player_weight_2 : 0;
                }
                --player_weight_2;
                flag_y_1 = 1;
            }else
            {
                player_weight_2 = 0;
                flag_y_1 = 0;
            }
            ++x;
            --y;
        }
    }


    for(int i = 0 ; i < AIQIPANNUM ; ++i)
    {
        flag_x_1 = 0;
        flag_y_1 = 0;
        player_weight_1 = 0;
        player_weight_2 = 0;
        x = i;
        y = 0;
        while(x >= 0 && y < AIQIPANNUM)
        {
            if(qipan[x][y] == player)
            {
                if(flag_x_1 == 1)
                {
                    player_weight_1 = 1;
                    flag_x_1 = 0;
                }else
                {
                    player_weight_1 += 1;
                }
            }else if(qipan[x][y] == 0)
            {
                weight[x][y][0] += player_weight_1 > 0 ? player_weight_1*player_weight_1 : 0;
                if (x + y + 2 == x_put  + y_put)
                {
                    weight[x][y][0] += player_weight_1 > 0 ? player_weight_1 : 0;
                }
                --player_weight_1;
                flag_x_1 = 1;
            }else
            {
                player_weight_1 = 0;
                flag_x_1 = 0;
            }

            if(x + y == AIQIPANNUM - 1)
            {
                --x;
                ++y;
                continue;
            };
            if(qipan[y][x] == player)
            {
                if(flag_y_1 == 1)
                {
                    player_weight_2 = 1;
                    flag_y_1 = 0;
                }else
                {
                    player_weight_2 += 1;
                }
            }else if(qipan[y][x] == 0)
            {
                weight[y][x][0] += player_weight_2 > 0 ? player_weight_2*player_weight_2 : 0;
                if (x + y + 2 == x_put  + y_put)
                {
                    weight[y][x][0] += player_weight_2 > 0 ? player_weight_2 : 0;
                }
                --player_weight_2;
                flag_y_1 = 1;
            }else
            {
                player_weight_2 = 0;
                flag_y_1 = 0;
            }
            --x;
            ++y;
        }
    }

    player = player == 2 ? 1 : 2;
    flag_x_1 = 0;
    flag_y_1 = 0;
    player_weight_1 = 0;
    player_weight_2 = 0;
    for(int i = 0 ; i < AIQIPANNUM ; ++i)
    {
        for(int j = 0 ; j < AIQIPANNUM ; ++j)
        {
            if(qipan[i][j] == player)
            {
                if(flag_x_1 == 1)
                {
                    player_weight_1 = 1;
                    flag_x_1 = 0;
                }else
                {
                    player_weight_1 += 1;
                }
            }else if(qipan[i][j] == 0)
            {
                weight[i][j][1] += player_weight_1 > 0 ? player_weight_1*player_weight_1 : 0;
                --player_weight_1;
                flag_x_1 = 1;
            }else
            {
                player_weight_1 = 0;
                flag_x_1 = 0;
            }

            if(qipan[j][i] == player)
            {
                if(flag_y_1 == 1)
                {
                    player_weight_2 = 1;
                    flag_y_1 = 0;
                }else
                {
                    player_weight_2 += 1;
                }
            }else if(qipan[j][i] == 0)
            {
                weight[j][i][1] += player_weight_2 > 0 ? player_weight_2*player_weight_2 : 0;
                --player_weight_2;
                flag_y_1 = 1;
            }else
            {
                player_weight_2 = 0;
                flag_y_1 = 0;
            }
        }
    }

    flag_x_1 = 0;
    flag_y_1 = 0;
    player_weight_1 = 0;
    player_weight_2 = 0;
    for(int i = AIQIPANNUM - 1 ; i >= 0 ; --i)
    {
        for(int j = AIQIPANNUM - 1 ; j >= 0 ; --j)
        {
            if(qipan[i][j] == player)
            {
                if(flag_x_1 == 1)
                {
                    player_weight_1 = 1;
                    flag_x_1 = 0;
                }else
                {
                    player_weight_1 += 1;
                }
            }else if(qipan[i][j] == 0)
            {
                weight[i][j][1] += player_weight_1 > 0 ? player_weight_1*player_weight_1 : 0;
                --player_weight_1;
                flag_x_1 = 1;
            }else
            {
                player_weight_1 = 0;
                flag_x_1 = 0;
            }

            if(qipan[j][i] == player)
            {
                if(flag_y_1 == 1)
                {
                    player_weight_2 = 1;
                    flag_y_1 = 0;
                }else
                {
                    player_weight_2 += 1;
                }
            }else if(qipan[j][i] == 0)
            {
                weight[j][i][1] += player_weight_2 > 0 ? player_weight_2*player_weight_2 : 0;
                --player_weight_2;
                flag_y_1 = 1;
            }else
            {
                player_weight_2 = 0;
                flag_y_1 = 0;
            }
        }
    }

    for(int i = 0 ; i < AIQIPANNUM ; ++i)
    {
        flag_x_1 = 0;
        flag_y_1 = 0;
        player_weight_1 = 0;
        player_weight_2 = 0;
        x = i;
        y = 0;
        while(x < AIQIPANNUM && y < AIQIPANNUM)
        {
            if(qipan[x][y] == player)
            {
                if(flag_x_1 == 1)
                {
                    player_weight_1 = 1;
                    flag_x_1 = 0;
                }else
                {
                    player_weight_1 += 1;
                }
            }else if(qipan[x][y] == 0)
            {
                weight[x][y][1] += player_weight_1 > 0 ? player_weight_1*player_weight_1 : 0;
                --player_weight_1;
                flag_x_1 = 1;
            }else
            {
                player_weight_1 = 0;
                flag_x_1 = 0;
            }

            if(x == y)
            {
                ++x;
                ++y;
                continue;
            };
            if(qipan[y][x] == player)
            {
                if(flag_y_1 == 1)
                {
                    player_weight_2 = 1;
                    flag_y_1 = 0;
                }else
                {
                    player_weight_2 += 1;
                }
            }else if(qipan[y][x] == 0)
            {
                weight[y][x][1] += player_weight_2 > 0 ? player_weight_2*player_weight_2 : 0;
                --player_weight_2;
                flag_y_1 = 1;
            }else
            {
                player_weight_2 = 0;
                flag_y_1 = 0;
            }
            ++x;
            ++y;
        }
    }

    for(int i = AIQIPANNUM - 1; i >= 0 ; --i)
    {
        flag_x_1 = 0;
        flag_y_1 = 0;
        player_weight_1 = 0;
        player_weight_2 = 0;
        x = i;
        y = AIQIPANNUM - 1;
        while(x >= 0 && y >= 0)
        {
            if(qipan[x][y] == player)
            {
                if(flag_x_1 == 1)
                {
                    player_weight_1 = 1;
                    flag_x_1 = 0;
                }else
                {
                    player_weight_1 += 1;
                }
            }else if(qipan[x][y] == 0)
            {
                weight[x][y][1] += player_weight_1 > 0 ? player_weight_1*player_weight_1 : 0;
                --player_weight_1;
                flag_x_1 = 1;
            }else
            {
                player_weight_1 = 0;
                flag_x_1 = 0;
            }

            if(x == y)
            {
                --x;
                --y;
                continue;
            };
            if(qipan[y][x] == player)
            {
                if(flag_y_1 == 1)
                {
                    player_weight_2 = 1;
                    flag_y_1 = 0;
                }else
                {
                    player_weight_2 += 1;
                }
            }else if(qipan[y][x] == 0)
            {
                weight[y][x][1] += player_weight_2 > 0 ? player_weight_2*player_weight_2 : 0;
                --player_weight_2;
                flag_y_1 = 1;
            }else
            {
                player_weight_2 = 0;
                flag_y_1 = 0;
            }
            --x;
            --y;
        }
    }

    for(int i = 0 ; i < AIQIPANNUM ; ++i)
    {
        flag_x_1 = 0;
        flag_y_1 = 0;
        player_weight_1 = 0;
        player_weight_2 = 0;
        x = i;
        y = AIQIPANNUM - 1;
        while(x < AIQIPANNUM && y >= 0)
        {
            if(qipan[x][y] == player)
            {
                if(flag_x_1 == 1)
                {
                    player_weight_1 = 1;
                    flag_x_1 = 0;
                }else
                {
                    player_weight_1 += 1;
                }
            }else if(qipan[x][y] == 0)
            {
                weight[x][y][1] += player_weight_1 > 0 ? player_weight_1*player_weight_1 : 0;
                --player_weight_1;
                flag_x_1 = 1;
            }else
            {
                player_weight_1 = 0;
                flag_x_1 = 0;
            }
            if(x + y == AIQIPANNUM - 1)
            {
                ++x;
                --y;
                continue;
            };
            if(qipan[y][x] == player)
            {
                if(flag_y_1 == 1)
                {
                    player_weight_2 = 1;
                    flag_y_1 = 0;
                }else
                {
                    player_weight_2 += 1;
                }
            }else if(qipan[y][x] == 0)
            {
                weight[y][x][1] += player_weight_2 > 0 ? player_weight_2*player_weight_2 : 0;
                --player_weight_2;
                flag_y_1 = 1;
            }else
            {
                player_weight_2 = 0;
                flag_y_1 = 0;
            }
            ++x;
            --y;
        }
    }


    for(int i = 0 ; i < AIQIPANNUM ; ++i)
    {
        flag_x_1 = 0;
        flag_y_1 = 0;
        player_weight_1 = 0;
        player_weight_2 = 0;
        x = i;
        y = 0;
        while(x >= 0 && y < AIQIPANNUM)
        {
            if(qipan[x][y] == player)
            {
                if(flag_x_1 == 1)
                {
                    player_weight_1 = 1;
                    flag_x_1 = 0;
                }else
                {
                    player_weight_1 += 1;
                }
            }else if(qipan[x][y] == 0)
            {
                weight[x][y][1] += player_weight_1 > 0 ? player_weight_1*player_weight_1 : 0;
                --player_weight_1;
                flag_x_1 = 1;
            }else
            {
                player_weight_1 = 0;
                flag_x_1 = 0;
            }

            if(x + y == AIQIPANNUM - 1)
            {
                --x;
                ++y;
                continue;
            };
            if(qipan[y][x] == player)
            {
                if(flag_y_1 == 1)
                {
                    player_weight_2 = 1;
                    flag_y_1 = 0;
                }else
                {
                    player_weight_2 += 1;
                }
            }else if(qipan[y][x] == 0)
            {
                weight[y][x][1] += player_weight_2 > 0 ? player_weight_2*player_weight_2 : 0;
                --player_weight_2;
                flag_y_1 = 1;
            }else
            {
                player_weight_2 = 0;
                flag_y_1 = 0;
            }
            --x;
            ++y;
        }
    }


    double weight_all[AIQIPANNUM][AIQIPANNUM];
    for(int i = 0 ; i < AIQIPANNUM ; ++i)
    {
        for(int j = 0 ; j < AIQIPANNUM ; ++j)
        {
            weight_all[i][j] = (double)weight[i][j][0] * (1.0 - DESIRE_VICTORY) + (double)weight[i][j][1] * DESIRE_VICTORY;
        }    
    }

    
    for(int i = 0 ; i < AIQIPANNUM ; ++i)
    {
        for(int j = 0 ; j < AIQIPANNUM ; ++j)
        {
            printf("%d " , weight[i][j][0]);
        }
        printf("\n");   
    }

    for(int i = 0 ; i < AIQIPANNUM ; ++i)
    {
        for(int j = 0 ; j < AIQIPANNUM ; ++j)
        {
            if(weight_all[i][j] > weight_all[return_x][return_y])
            {
                return_x = i;
                return_y = j;
            }
        }    
    }
    location[0] = return_x;
    location[1] = return_y;
    return location;
}

#endif // !AIFIVE_H