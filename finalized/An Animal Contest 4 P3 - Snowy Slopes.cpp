#include <bits/stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/aac4p3
*/
long long N, M;
long long countt, x, y, k, d, v, c;

pair<long long, long long> coords[100001];

struct pair_hash
{
    size_t operator()(const pair<long long, long long> &v) const
    {
        return v.first * 31 + v.second;
    }
};

unordered_set<pair<long long, long long>, pair_hash> simplifiedSlopes;

int main()
{
    cin >> N >> M;

    for (long long i = 0; i < N; i++)
    {
        cin >> x >> y;
        coords[i].first = x;
        coords[i].second = y;
    }

    for (long long i = 0; i < M; i++)
    {
        cin >> k >> d;
        if (d < 0)
        {
            k = -k;
            d = -d;
        }
        priority_queue<long long> slopes;
        if (simplifiedSlopes.count({k / gcd(k, d), d / gcd(k, d)}) > 0)
        {
            continue;
        }
        simplifiedSlopes.insert({k / gcd(k, d), d / gcd(k, d)});
        for (long long j = 0; j < N; j++)
        {
            slopes.push(k * coords[j].first - d * coords[j].second);
        }
        while (!slopes.empty())
        {
            v = slopes.top();
            c = 1;
            slopes.pop();
            while (!slopes.empty() && slopes.top() == v)
            {
                slopes.pop();
                c++;
            }
            countt += c * (c - 1) / 2;
        }
    }
    cout << countt << endl;
}