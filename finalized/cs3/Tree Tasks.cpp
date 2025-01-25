#include <bits/stdc++.h>
using namespace std;

int N, u, v, w, maxi, mini;

vector<pair<int, int> > graph[500005]; // {vertex, weight}
int d[500005][2];
int before[500005];

// length, last vertex;

void dfs(int v, int p, int dI) {
    before[v] = p;
    for (pair<int, int> a: graph[v]) {
        if (a.first != p) {
            d[a.first][dI] = d[v][dI] + a.second;
            dfs(a.first, v, dI);
        }
    }
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    dfs(1, -1, 0);
    int e = 0;
    for (int i = 1; i <= N; i++) {
        if (d[i][0] > d[e][0])
            e = i;
    }
    d[e][0] = 0;
    dfs(e, 0, 0);
    int e2 = 0;
    for (int i = 1; i <= N; i++) {
        if (d[i][0] > d[e2][0])
            e2 = i;
    }
    dfs(e2, 0, 1);
    int vv = e;
    int r = INT_MAX;
    while (vv != 0) {
        r = min(r, max(d[vv][0], d[vv][1]));
        vv = before[vv];
    }
    cout << d[e2][0] << endl << r << endl;
}
