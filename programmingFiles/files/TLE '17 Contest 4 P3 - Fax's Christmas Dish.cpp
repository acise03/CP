#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M, D;
int d[300005];
vector<int> recipes[300005];

int dfs(int v) {
    int tp = -1;
    for (int i: recipes[v]) {
        tp = max(dfs(i), tp);
    }
    if (tp == -1)
        return d[v];
    return min(tp, d[v]);
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> D;

    for (int i = 0; i < M; i++) {
        int t, reqn;
        cin >> t >> reqn;
        for (int j = 0; j < reqn; j++) {
            int k;
            cin >> k;
            recipes[t].push_back(k);
        }
    }
    fill(d, d + 300001, INT_MAX);
    for (int i = 1; i <= D; i++) {
        int p;
        cin >> p;
        d[p] = min(d[p], i);
    }
    int xx = dfs(1);
    if (xx > D)
        cout << -1 << endl;
    else
        cout << xx << endl;
    return 0;
}
