#include <bits/stdc++.h>
using namespace std;

long long N;
bool adjMatrix[1000][1000];
bool visited[1000];
vector<int> curr;

void dfs(int v)
{
    for (int i = 0; i < N; i++)
    {
        if (!visited[i] && adjMatrix[v][i])
        {
            visited[i] = true;
            curr.push_back(i);
            dfs(i);
        }
    }
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
        for (int j = 0; j < N; j++)
        {
            bool k;
            cin >> k;
            adjMatrix[i][j] = k;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            curr.clear();
            visited[i] = true;
            curr.push_back(i);
            dfs(i);
            sort(curr.begin(), curr.end());
            for (int j = 0; j < curr.size(); j++)
            {
                cout << curr[j] + 1 << " ";
            }
            cout << endl;
        }
    }
}