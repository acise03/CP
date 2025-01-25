#include <bits/stdc++.h>
using namespace std;

bool contains[50][50];
char grid[50][50];
int main()
{
    for (int i = 0; i < 50; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 50; j++)
        {
            grid[i][j] = s[j];
        }
    }
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (grid[i][j] != '.')
            {
                char k = grid[i][j];
                for (int x = 0; x < 50; x++)
                {
                    for (int y = 0; y < 50; y++)
                    {
                        if (grid[x][y] == k && !(x == i && y == j))
                        {
                            int rise = y - j;
                            int run = x - i;

                            int gcdd = gcd(rise, run);
                            rise = rise / gcdd;
                            run = run / gcdd;

                            int x_val = i;
                            int y_val = j;

                            while (x_val >= 0 && x_val < 50 && y_val < 50 && y_val >= 0)
                            {
                                contains[x_val][y_val] = true;
                                x_val = x_val - run;
                                y_val = y_val - rise;
                            }

                            x_val = i;
                            y_val = j;

                            while (x_val >= 0 && x_val < 50 && y_val < 50 && y_val >= 0)
                            {
                                contains[x_val][y_val] = true;
                                x_val = x_val + run;
                                y_val = y_val + rise;
                            }
                        }
                    }
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (contains[i][j])
                count++;
        }
    }
    cout << count;
}