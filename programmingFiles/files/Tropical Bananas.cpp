#include <bits/stdc++.h>
using namespace std;

long long arr[200005];
long long diffArrA[200005];
long long diffArrB[200005];
long long N, Q;
int main()
{
    cin >> N >> Q;

    for (long long i = 0; i < Q; i++)
    {
        long long cmd;
        cin >> cmd;
        long long l, r, a, b;
        cin >> l >> r >> a >> b;
        if (cmd == 0)
        {
            diffArrA[l] += a;
            diffArrA[r + 1] -= a + b * (r - l + 1);
            diffArrB[l] += b;
            diffArrB[r + 1] -= b;
        }
        if (cmd == 1)
        {
            diffArrA[l] += a + b * (r - l + 2);
            diffArrA[r + 1] -= a + b;
            diffArrB[l] -= b;
            diffArrB[r + 1] += b;
        }
    }
    long long curr = 0;

    for (long long i = 1; i <= N; i++)
    {
        diffArrB[i] += diffArrB[i - 1];
        diffArrA[i] += diffArrA[i - 1] + diffArrB[i];
        cout << diffArrA[i] << endl;
    }
}