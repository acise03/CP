#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, K, a, b, d, s;

vector<pair<int, int>> nextHills[10];
int nextHillsPeople[10];

void rec(int v, int s)
{
    nextHillsPeople[v]++;

    if (nextHills[v].empty())
        return;

    int higher = lower_bound(nextHills[v].begin(), nextHills[v].end(), make_pair(s, (int)0)) - nextHills[v].begin();
    int lower = higher - 1;
    while (lower > 0)
    {
        if (nextHills[v][lower - 1].second == nextHills[v][lower].second)
            lower--;
        else
            break;
    }

    if (higher < N && abs(nextHills[v][higher].second - s) < abs(nextHills[v][lower].second - s))
    {
        auto nv = nextHills[v][higher];
        nextHills[v].erase(nextHills[v].begin() + higher);

        rec(nv.second, s);
        nextHills[v].insert(nextHills[v].begin() + higher, nv);
        sort(nextHills[nv.second].begin(), nextHills[nv.second].end());
    }
    else if (lower >= 0)
    {
        auto nv = nextHills[v][lower];
        nextHills[v].erase(nextHills[v].begin() + lower);
        rec(nv.second, s);
        nextHills[v].insert(nextHills[v].begin() + lower, nv);
    }
}

signed main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b >> d;
        nextHills[a].push_back({d, b});
        nextHills[b].push_back({d, b});
    }
    for (int i = 0; i < N - 1; i++)
    {
        sort(nextHills[i].begin(), nextHills[i].end());
    }
    for (int i = 0; i < K; i++)
    {
        cin >> s;
        rec(1, s);
    }
    for (int i = 1; i <= N; i++)
    {
        cout << nextHillsPeople[i] << " ";
    }
    cout << endl;
}