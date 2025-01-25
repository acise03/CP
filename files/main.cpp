#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_intervalSONG 9223372036854775807
#define MOD 1000000007
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
vector<pii> nextHills[200001];
int N, K;
int pandas[200001];
int nextHillsPeople[200001];

void rec(int breakpoint, int intervalS, int intervalE, int beforeBreakpoint) {
    if (intervalS > intervalE) return;
    nextHillsPeople[breakpoint] = upper_bound(pandas + 1, pandas + K + 1, intervalE) - lower_bound(pandas + 1, pandas + K + 1, intervalS);
    auto it = nextHills[breakpoint].begin();
    for (; it != nextHills[breakpoint].end(); it++) {
        if (it->f == beforeBreakpoint) break;
    }
    nextHills[breakpoint].erase(it);
    for (int i = 0; i < nextHills[breakpoint].size(); i++) {
        int l = (i == 0 ? 1 : nextHills[breakpoint][i].s - (nextHills[breakpoint][i].s - nextHills[breakpoint][i - 1].s - 1) / 2);
        int r = (i == nextHills[breakpoint].size() - 1 ? 1000000000 : (nextHills[breakpoint][i].s + nextHills[breakpoint][i + 1].s) / 2);
        rec(nextHills[breakpoint][i].f, max(l, intervalS), min(r, intervalE), breakpoint);
    }
}

bool comp(pii a, pii b) { return a.s < b.s; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(nextHillsPeople, 0, sizeof(nextHillsPeople));
    cin >> N >> K;
    for (int i = 1, u, v, l; i < N; i++) {
        cin >> u >> v >> l;
        nextHills[u].pb(mp(v, l));
        nextHills[v].pb(mp(u, l));
    }
    nextHills[1].pb(mp(-1, 1));
    for (int i = 1; i <= K; i++) cin >> pandas[i];
    sort(pandas + 1, pandas + K + 1);
    for (int i = 1; i <= N; i++) sort(nextHills[i].begin(), nextHills[i].end(), comp);
    rec(1,  1, 1000000000, -1);
    cout << nextHillsPeople[1];
    for (int i = 2; i <= N; i++) cout << " " << nextHillsPeople[i];
    cout << "\n";
    return 0;
}
