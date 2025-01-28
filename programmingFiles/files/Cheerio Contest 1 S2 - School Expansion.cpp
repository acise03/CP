#include <bits/stdc++.h>
using namespace std;

long long N, A, B;
priority_queue<tuple<long long, long long, long long>> stories;
int main()
{
    cin >> N >> A >> B;
    long long cost = 0;

    for (long long i = 1; i <= N; i++)
    {
        stories.push({-1 * A * i - B, i, 1});
    }

    for (long long i = 0; i < N; i++)
    {
        tuple<long long, long long, long long> k = stories.top();
        stories.pop();
        cost += -1 * get<0>(k);
        stories.push({get<0>(k) - B, get<1>(k), get<2>(k) + 1});
    }
    cout << cost << endl;
}