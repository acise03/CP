#include <bits/stdc++.h>
using namespace std;

int L, n, ind;

map<string, int> nameToInd;
int prevs[105];
int grid[105];
string alphaWord;
vector<int> paths[105];

int rec(int v, int p, int c)
{
    if (paths[v].empty())
    {
        return 0;
    }
    int m = 0;
    for (int vv : paths[v])
    {
        if (vv != v)
        {
            m = max(m, rec(vv, v, c) + 1);
        }
    }
    return m;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> L;

    for (int i = 0; i < L; i++)
    {
        cin >> n;

        int longest = 0;

        vector<string> currNames;
        int prev = -1;
        alphaWord = "{";

        for (int j = 0; j < n; j++)
        {
            string name;
            cin >> name;
            if (name < alphaWord)
            {
                alphaWord = name;
            }
            int v = ind;

            if (nameToInd.count(name) == 0)
            {
                nameToInd[name] = v;
                ind++;

                prevs[v] = prev;
                paths[prev].push_back(v);

                prev = v;
            }
            else
            {
                v = nameToInd[name];
                prev = v;
                paths[v].push_back(prev);
            }
        }
        int longest = rec(nameToInd[name], -1, 0);
        cout << longest << endl;
    }
}
