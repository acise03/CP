#include <bits/stdc++.h>
using namespace std;
int grid[130][130];
set<int> gridCount[130][130];
int main()
{
    int count = 0;

    for (int i = 0; i < 130; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 130; j++)
        {
            grid[i][j] = s[j];
        }
    }
    for (int i = 0; i < 130; i++)
    {

        for (int j = 0; j < 130; j++)
        {
            if (i == 89 && j == 74)
            {
                continue;
            }
            if (grid[i][j] != '#')
            {
                grid[i][j] = '#';
                for (int a = 0; a < 130; a++)
                {
                    for (int b = 0; b < 130; b++)
                    {
                        gridCount[a][b].clear();
                    }
                }
                int loc1 = 89;
                int loc2 = 74;
                int dir = 0; // 0: up; 1: right; 2: down; 3: left

                while (loc1 >= 0 && loc1 < 130 && loc2 < 130 && loc2 >= 0)
                {

                           if (gridCount[loc1][loc2].count(dir) > 0)
                   // if (gridCount[loc1][loc2].empty())
                    {
                        count++;
                        break;
                    }
                    else
                    {
                        gridCount[loc1][loc2].insert(dir);
                    }
                    if (dir == 0)
                    {
                        loc1--;
                        if (loc1 < 130 && loc1 >= 0)
                        {
                            if (grid[loc1][loc2] == '#')
                            {
                                dir++;
                                dir = dir % 4;

                                loc2++;
                                loc1++;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    else if (dir == 1)
                    {
                        loc2++;
                        if (loc2 < 130 && loc2 >= 0)
                        {
                            if (grid[loc1][loc2] == '#')
                            {
                                dir++;
                                dir = dir % 4;
                                loc1++;
                                loc2--;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    else if (dir == 2)
                    {
                        loc1++;
                        if (loc1 < 130 && loc1 >= 0)
                        {
                            if (grid[loc1][loc2] == '#')
                            {
                                dir++;
                                dir = dir % 4;
                                loc2--;
                                loc1--;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    else if (dir == 3)
                    {
                        loc2--;
                        if (loc2 < 130 && loc2 >= 0)
                        {
                            if (grid[loc1][loc2] == '#')
                            {
                                dir++;
                                dir = dir % 4;
                                loc1--;
                                loc2++;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }

                grid[i][j] = '.';
            }
        }
    }

    cout << count;
}