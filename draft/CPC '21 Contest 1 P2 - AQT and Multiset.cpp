#include <bits/stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/tle17c4p3
*/

long long N, A, B;
long long As[400001];
long long Bs[400001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    N = 2 * N + 1;

    for (long long i = 0; i < N; i++)
    {
        cin >> As[i];
    }
    for (long long i = 0; i < N; i++)
    {
        cin >> Bs[i];
    }
    long long res = 0;
    for (long long i = 0; i < N; i++)
    {
        res ^= As[i];
        res ^= Bs[i];
    }

    bool valid = true;
    sort(As, As + N);
    sort(Bs, Bs + N);
    for (long long i = 0; i < N; i++)
    {
        long long r = As[i] ^ res;
        if (r != Bs[i])
        {
            valid = false;
            break;
        }
    }
    if (valid)

        cout << res;
    else
    {
        cout << -1;
    }
}