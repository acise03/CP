#include <bits/stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/tle17c4p3
*/

#define int long long

long long N, M, K, V;

int f(int x, int y)
{
    int a = 1;
    while (y > 0)
    {
        if (y & 1)
        {
            a = (a * x) % M;
        }
        x = x * x % M;
        y >>= 1;
    }
    return a;
}

signed main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K >> V;

    int num_of_1s = __builtin_popcountll(V);
    int num_of_0s = K - num_of_1s;

    int res = (f(2, N) + M - 1) % M;

    // 1
    cout << f(2, K * N - K) << endl;

    // 2
    cout << (f(res, num_of_1s)) % M << endl;

    // 3
    cout << (f(res, num_of_0s)) % M << endl;
}