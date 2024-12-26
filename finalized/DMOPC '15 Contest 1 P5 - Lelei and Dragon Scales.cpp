#include <bits/stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/dmopc15c1p5
*/
int W, H, N;
int grid[255][255];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> W >> H >> N;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            int x;
            cin >> x;
            grid[i][j] = x + grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
        }
    }
    int maximum = -1;
    for (int i = 1; i <= W; i++)
    {
        for (int j = i; j <= W; j++)
        {
            int rem = (N / (j - i + 1));
            for (int k = 1; k <= H; k++)
            {
                int prev = grid[min(k + rem - 1, H)][j] - grid[k - 1][j] - grid[min(k + rem - 1, H)][i - 1] + grid[k - 1][i - 1];
                maximum = max(maximum, prev);
            }
        }
    }
    cout << maximum << endl;
}