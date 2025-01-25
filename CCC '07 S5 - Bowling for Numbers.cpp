#include <bits/stdc++.h>
using namespace std;
long long t, n, k, w;
long long values[10];
long long memo[10][10];
int maximum;
int Recurse(int bowledCountLeft, int index)
{
    if (index >= n + 1)
    {
        return 0;
    }
    if (memo[index][bowledCountLeft] != -1)
    {
        return memo[index][bowledCountLeft];
    }
    memo[index][bowledCountLeft] = Recurse(bowledCountLeft, index + 1);
    if (bowledCountLeft >= 1)
    {
        int add = 0;
        for (int i = index; i <= min(index + w - 1, n - 1); i++)
            add += values[i];
        memo[index][bowledCountLeft - 1] = add + Recurse(bowledCountLeft, index + w-1);
    }
    return max(memo[index][bowledCountLeft], memo[index][bowledCountLeft - 1]);
}
int main()
{
    cin >> t;
    for (long long i = 0; i < t; i++)
    {
        cin >> n >> k >> w;
        values[0] = 0;
        values[n + 1] = 0;
        for (long long j = 0; j < n; j++)
        {
            cin >> values[j];
            for (int a = 0; a <= k + 1; a++)
                memo[j][a] = -1;
        }
        int asdf = Recurse(k, 0);
        cout << asdf << endl;
    }
}