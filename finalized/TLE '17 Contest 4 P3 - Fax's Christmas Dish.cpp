#include <bits/stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/tle17c4p3
*/
int N, M, D;
int itemCount[300000];
vector<int> recepies[300000];
int nextt;

bool dfs(int v)
{
    return nextt;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> D;

    for (int i = 0; i < M; i++)
    {
        int t, reqn;
        cin >> t >> reqn;
        for (int j = 0; j < reqn; j++)
        {
            int k;
            cin >> k;
            recepies[t].push_back(k);
        }
    }
    for (int i = 0; i < D; i++)
    {
        int p;
        cin >> p;
        itemCount[p]++;

        if (p <= nextt)
            if (dfs(1))
        {
              cout << i+1<<endl;
        break;
              }

    }
    cout << -1 << endl;
    return 0;
}