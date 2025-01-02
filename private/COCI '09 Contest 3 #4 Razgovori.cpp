#include <bits/stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/coci09c3p4
*/

long long N, M, P, C;
vector<pair<long long, long long>> poles;

bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{
    if (a.first < b.first)
        return true;
    return false;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    long long currCount = 0;
    long long totalCount = 0;
    for (long long i = 0; i < N; i++)
    {
        cin >> P >> C;
        poles.push_back({P, C});
    }
    sort(poles.begin(), poles.end(), cmp);
    for (pair<long long, long long> cp : poles)
    {
        P = cp.first;
        C = cp.second;
        if (C == currCount)
            continue;
        else if (C > currCount)
        {
            totalCount += (C - currCount);
            currCount = C;
        }
        else if (C < currCount)
        {
            currCount = C;
        }
    }

    cout << totalCount << endl;
}