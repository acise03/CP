#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[1000000];
int PP[1000000];
int anst, ans, total;
int dfs(int vertex, int prev) // returns total # of fans in branch
{
    int currPeople = PP[vertex];
    int most = 0;
    for (int n : adjList[vertex])
    {
        if (n != prev)
        {
            int x = dfs(n, vertex);
            most = max(most, x);
            currPeople += x;
        }
    }
    most = max(most, total - currPeople);
    if (anst > most)
    {
        anst = most;
        ans = vertex;
    }
    return currPeople;
}

int LocateCentre(int N, int P[1000000], int S[1000000], int D[1000000])
{
    for (int i = 0; i < N - 1; i++)
    {
        adjList[S[i]].push_back(D[i]);
        adjList[D[i]].push_back(S[i]);
        total += P[i];
        PP[i] = P[i];
    }
    PP[N - 1] = P[N - 1];
    total += P[N - 1];
    anst = total;

    dfs(0, 0);
    return ans;
}
