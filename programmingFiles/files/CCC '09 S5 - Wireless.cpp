#include <bits/stdc++.h>
using namespace std;
long long grid[30005][1005];

int main()
{
    long long M, N, K;

    cin >> M >> N >> K;
    long long maximum = 0;
    for (long long i = 0; i < K; i++)
    {
        long long x, y, R, B;
        cin >> y >> x >> R >> B;
        for (long long xx = max((long long)1, x - R); xx <= min(M, x + R); xx++)
        {
            long long change = floor(sqrt(R * R - (xx - x) * (xx - x)));
            long long start = max((long long)1, (long long)(y - change));
            long long end = min(N, (long long)(y + change)) + 1;
            grid[xx][start] += B;
            grid[xx][end] -= B;
        }
    }
    long long count = 0;
    for (long long x = 1; x <= M; x++)
    {
        long long sum = 0;
        for (long long y = 1; y <= N; y++)
        {
            sum += grid[x][y];
            if (maximum < sum)
            {
                maximum = sum;
                count = 1;
            }
            else if (maximum == sum)
            {
                count++;
            }
        }
    }
    cout << maximum << endl;

    cout << count << endl;
}