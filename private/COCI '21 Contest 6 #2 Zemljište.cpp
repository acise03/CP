#include <bits\stdc++.h>
using namespace std;

long long r, s, a, b;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> s >> a >> b;
    long long grid[r][s];
    for (long long i = 0; i < r; i++)
    {
        for (long long j = 0; j < s; j++)
        {
            cin >> grid[i][j];
        }
    }
    long long minDistance = abs(grid[0][0] - a) + abs(grid[0][0] - b);
    long long sum = 0;

    for (long long start = 0; start < r; start++)
    {
        for (long long end = start; end < r; end++)
        {
            long long left = 0;
            long long right = 0;
            sum = 0;
        
            while (left < s)
            {
                while (sum < (minDistance + max(a, b)) && right < s)
                {
                    for (long long i = start; i <= end; i++)
                    {
                        sum += grid[i][right];
                    }

                    minDistance = min(abs(sum - a) + abs(sum - b), minDistance);
                    right++;
                }
                for (long long i = start; i <= end; i++)
                {
                    sum -= grid[i][left];
                }
                left++;
            }
        }
    }
    cout << minDistance << endl;
}