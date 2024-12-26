#include <bits/stdc++.h>
using namespace std;

long long r, s, a, b;
long long grid[505][505];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> s >> a >> b;
    for (long long i = 1; i <= r; i++)
    {
        for (long long j = 1; j <= s; j++)
        {
            int x;
            cin >> x;
            grid[i][j] = grid[i][j - 1] + x;
        }
    }
    if (a > b)
        swap(a, b);

    long long minDistance = abs(grid[0][0] - a) + abs(grid[0][0] - b);

    for (long long start = 1; start <= r; start++)
    {
        for (long long end = start; end <= r; end++)
        {
            long long left = 1;
            long long right = 1;

            int sum = 0;
            sum += grid[start][end];
        }
    }
    cout << minDistance << endl;
}