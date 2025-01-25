#include <bits/stdc++.h>
using namespace std;

int N, u, v;
vector<int> connections[500005];
int memo[500005][2];

int rec(int v, int p, int dir) {
    if (memo[v][dir] != -1) return memo[v][dir];
    int m = 0;
    int i = connections[v][dir];
    if (i == p) {
        dir = abs(dir - 1);
        i = connections[v][dir];
    }
    if (i != v && i != p) {
        if (connections[i][0] != p || (p == -1 && dir == 0))
            m = max(m, rec(i, v, 0) + 1);
        else
            m = max(m, rec(i, v, 1) + 1);
    }
    memo[v][dir] = m;
    return
            m;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        connections[u].push_back(v);
        connections[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        memset(memo, -1, 500005);
        cout << rec(i, -1, 0) + rec(i, -1, 1) << endl;
    }
}
