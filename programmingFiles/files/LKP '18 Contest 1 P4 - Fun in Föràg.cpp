#include<bits/stdc++.h>
#define int long long
using namespace std;
int N, M, ai, bi, ci, A, B, C;
vector<tuple<int, int, int> > adjList[200005];
int dist[100005];
int func(int x, int maxi) {
    for (int v = 0; v < 100005; v++) {
        dist[v] = LONG_LONG_MAX;
    }
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> vals;
    vals.push({0, A});
    while (!vals.empty()) {
        int ddist = vals.top().first;
        int vertex = vals.top().second;
        vals.pop();
        if (dist[vertex] < ddist) {
            continue;;
        }

        for (auto t: adjList[vertex]) {
            ai = get<0>(t);
            bi = get<1>(t);
            ci = get<2>(t);
            if (ci > maxi) continue;
            if (dist[ai] > ddist + bi) {
                dist[ai] = ddist + bi;
                vals.push({ddist + bi, ai});
            }
        }
    }
    return dist[B];
}

signed main() {
    // binary search
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> ai >> bi >> ci;
        adjList[ai].push_back({bi, ci, i});
        adjList[bi].push_back({ai, ci, i});
    }
    cin >> A >> B >> C;

    int res = LONG_LONG_MAX;
    int l = 1;
    int r = M;
    while (l <= r) {
        int m = (l + r) / 2;
        int v = func(A, m);
        if (v <= C) {
            res = min(res, m);
            r = m - 1;
        } else
            l = m + 1;
    }
    if (res == LONG_LONG_MAX)res = -1;
    cout << res << endl;
}