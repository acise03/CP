#include <bits/stdc++.h>
using namespace std;
int N, M, K, V, t;
int fastExp(int a, int n)
{
    int ans = 1;
    while (n > 0)
    {
        if (n & 1)
            ans = (ans * a) % M;
        a = (a * a) % M;
        n >>= 1;
    }
    return ans;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K >> V;
    t = (fastExp(2, N) + M - 1) % M;
    int count1 = __builtin_popcountll(V);
    int count2 = K - count1;
    cout << fastExp(2, K * (N - 1)) << "\n";
    cout << fastExp(t, count1) << "\n";
    cout << fastExp(t, count2) << "\n";
}