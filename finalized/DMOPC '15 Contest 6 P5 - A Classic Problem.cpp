
#include <bits/stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/dmopc15c6p5
*/

long long N, K;
long long numCount[1000001];
deque<pair<long long, long long>> maxMono;
deque<pair<long long, long long>> minMono;
void maxPush(long long val)
{
    long long countt = 0;
    while (!maxMono.empty() && maxMono.back().first < val)
    {
        countt += maxMono.back().second + 1;
        maxMono.pop_back();
    }
    maxMono.push_back({val, countt});
}
long long max()
{
    return maxMono.front().first;
}
void minPush(long long val)
{
    long long countt = 0;
    while (!minMono.empty() && minMono.back().first > val)
    {
        countt += minMono.back().second + 1;
        minMono.pop_back();
    }
    minMono.push_back({val, countt});
}
long long min()
{
    return minMono.front().first;
}
void remMax()
{
    if (maxMono.front().second > 0)
        maxMono.front().second--;
    else
        maxMono.pop_front();
}
void remMin()
{
    if (minMono.front().second > 0)
        minMono.front().second--;
    else
        minMono.pop_front();
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    long long countt = 0;
    long long l = 0;
    long long r = 1;
    long long i;
    cin >> i;
    maxPush(i);
    minPush(i);

    while (r <= N)
    {
        while (max() - min() > K)
        {
            l++;
            remMax();
            remMin();
        }
        countt += r - l;
        r++;
        cin >> i;
        maxPush(i);
        minPush(i);
    }
    cout << countt << endl;
}