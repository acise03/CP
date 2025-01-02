#include <bits/stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/tle17c4p3
*/
int N, M, D;
int itemCount[300000];
vector<int> recepies[300000];
vector<int> awating;
bool dfs(int v)
{
    bool tP = true;
    if (recepies[v].size() < 1)
        tP = false;
    for (int i : recepies[v])
    {
        bool possible;
        if (itemCount[i] < 1)
        {
            possible = dfs(i);
        }
        else
            possible = true;
        if (!possible)
        {
            tP = false;
            awating.push_back(i);
        }
    }
    if (tP)
    {
        for (int i : recepies[v])
        {
            itemCount[i]--;
        }
        itemCount[v]++;
    }
    return tP;
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
            recepies[t - 1].push_back(k - 1);
        }
    }
    awating.clear();
    for (int i = 0; i < D; i++)
    {
        int p;
        cin >> p;
        itemCount[p - 1]++;
        if (itemCount[0] < 1)
        {
            if (count(awating.begin(), awating.end(), p) > 0)
            {
                awating.erase(remove(awating.begin(), awating.end(), p));
                if (dfs(0))
                {
                    cout << i + 1 << endl;
                    return 0;
                }
            }
            else if (awating.size() == 0)
                if (dfs(0))
                {
                    cout << i + 1 << endl;
                    return 0;
                }
        }
        else
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}