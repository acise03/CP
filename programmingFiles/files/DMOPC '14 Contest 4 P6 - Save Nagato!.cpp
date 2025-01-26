#include <bits/stdc++.h>
using namespace std;

int N, u, v;
vector<int> connections[500005];
int memo[500005];

int rec(int v, int p) {
    if (memo[v] != -1) return memo[v];
    int m = 0;
    for (int i: connections[v]) {
        if (i != v && i != p) {
            m = max(m, rec(i, v) + 1);
        }
    }
    memo[v] = m;
    return m;
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
        cout << rec(i, -1) + 1 << endl;
    }
}