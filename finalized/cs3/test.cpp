#include <bits/stdc++.h>
using namespace std;
int n, ans;
long long total;
vector<int> adjList[1000000];
int p[1000000], s[1000000], d[1000000];
long long ansTraffic = 1000000000000000000;
long long dfs(int vertex, int previous)
{
    long long mostTraffic = 0;
    long long totalTraffic = p[vertex];
    for (int u : adjList[vertex])
        if (u != previous)
        {
            long long t = dfs(u, vertex);
            mostTraffic = max(mostTraffic, t);
            totalTraffic += t;
        }
    mostTraffic = max(mostTraffic, total-totalTraffic);
    if (ansTraffic > mostTraffic)
    {
        ansTraffic = mostTraffic;
        ans = vertex;
    }
    return totalTraffic;
}
int LocateCentre(int N, int P[], int S[], int D[])
{
    for (int i = 0; i < N; i++)
    {
        total += P[i];
        p[i] = P[i];
    }
    for (int i = 0; i < N-1; i++)
    {
        adjList[S[i]].push_back(D[i]);
        adjList[D[i]].push_back(S[i]);
    }
    dfs(0,-1);
    return ans;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n-1; i++)
        cin >> s[i] >> d[i];
    cout << LocateCentre(n, p, s, d);
}