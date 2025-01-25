#include <bits/stdc++.h>
using namespace std;

#define int long long

int N, i, j, leng;
vector<int> graph[400005];
bool visited[400005];
int maxi = 0;
int maxiInd;
int startV;
int VV;
set<pair<int, int>> valids;

void dfs(int v, int prev, int l)
{
    bool c = false;
    int m = 0;
    for (int k : graph[v])
        if (k != prev && k != v)
        {
            dfs(k, v, l + 1);
            c = true;
        }
    if (!c)
    {
        if (maxi < l)
        {
            maxiInd = v;
            maxi = l;
        }
    }
}

void dfs2(int v, int prev, int l, int startVV)
{
    bool c = false;
    int m = 0;
    for (int k : graph[v])
        if (k != prev && k != v)
        {
            dfs2(k, v, l + 1, startVV);
            c = true;
        }
    if (!c)
    {
        if (leng == l)
        {
            if (startVV > v)
                valids.insert({v, startVV});
            else
                valids.insert({startVV, v});
            if (!visited[v])
            {
                visited[v] = true;
                dfs2(v, 0, 1, v);
            }
        }
    }
}
signed main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int x = 0; x < N - 1; x++)
    {
        cin >> i >> j;
        graph[i].push_back(j);
        graph[j].push_back(i);
    }
    dfs(1, 0, 1);
    startV = maxiInd;
    dfs(startV, 0, 1);
    int endV = maxiInd;
    leng = maxi;
    VV = startV;
    dfs2(VV, 0, 1, VV);

    // VV = endV;

    //  dfs2(VV, 0, 1);

    //  if (startV > endV)
    //    swap(startV, endV);
    //  valids.insert({startV, endV});

    cout << leng << " " << valids.size() << endl;
}