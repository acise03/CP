#include <bits/stdc++.h>
using namespace std;
#define int long long

int K, N, M, A, B;
vector<tuple<int, int, int> > paths[2005]; // b, t, h
int times[2005][205];

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, t, h;
        cin >> a >> b >> t >> h;
        paths[a].push_back({b, t, h});
        paths[b].push_back({a, t, h});
    }
    cin >> A >> B;
    memset(times, -1, sizeof(times));
    times[A][K] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > nextIslands;
    // next island, tot time to get there, how much left after it is shaved
    nextIslands.push({0, K, A});
    while (!nextIslands.empty()) {
        int a, t, h;
        a = get<2>(nextIslands.top());
        t = get<0>(nextIslands.top());
        h = get<1>(nextIslands.top());
        nextIslands.pop();

        for (auto tup: paths[a]) {
            int b, tt, hh;
            b = get<0>(tup);
            tt = get<1>(tup);
            hh = get<2>(tup);
            if (h - hh <= 0) {
                continue;
            }
            if (times[b][h - hh] == -1 || t + tt < times[b][h - hh]) {
                nextIslands.push({t + tt, h - hh, b});
                times[b][h - hh] = t + tt;
            }
        }
    }
    int mini = INT_MAX;
    for (int i = 0; i < 205; i++) {
        if (times[B][i] != -1)
            mini = min(mini, times[B][i]);
    }
    if (mini == INT_MAX) {
        mini = -1;
    }
    cout << mini << endl;
}
