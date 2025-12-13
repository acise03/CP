#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > roads[18];
int memo[18][1 << 18];

pair<bool, int> dp(int v, int mask) {
    if (v == n - 1) {
        return {true, 0};
    }
    if (memo[v][mask] != -1) {
        return {true, memo[v][mask]};
    }
    int res = 0;
    bool changed = false;
    for (auto p: roads[v]) {
        if (mask & (1 << p.first)) {
            auto v = dp(p.first, mask & ~(1 << p.first));
            if (v.first) {
                res = max(res, p.second + v.second);
                changed = true;
            }
        }
    }
    if (!changed) {
        return {false, -1};
    }

    memo[v][mask] = res;
    return {true, res};
}

int s, d, l;

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> s >> d >> l;
        roads[s].push_back({d, l});
    }

    memset(memo, -1, sizeof(memo));
    cout << dp(0, (((1 << n) - 1) & ~(1 << 0))).second << endl;
}