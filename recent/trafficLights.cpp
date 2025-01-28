#include <bits/stdc++.h>
using namespace std;

int N, K, s, e, t, g, r;
vector<pair<int, int> > adjList[100005];
priority_queue<pair<int, int> > pq;
int dist[100005];

int red[1005];
int green[1005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    fill_n(dist, N + 1, INT_MAX);

    for (int i = 1; i <= N; i++) {
        cin >> s >> e >> t;
        adjList[s].push_back({e, t});
        adjList[e].push_back({s, t});
    }

    for (int i = 1; i <= K; i++) {
        cin >> g >> r;
        green[i] = g;
        red[i] = r;
    }

    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        if (x.second == K) {
            break;
        }
        for (auto t: adjList[x.second]) {
            int mod = green[x.second] + red[x.second];
            int waitTime;

            if (mod != 0) {
                waitTime = dist[x.second] % (mod);
                if (waitTime >= green[x.second]) {
                    // > or >=?
                    waitTime = green[x.second] + red[x.second] - waitTime;
                } else waitTime = 0;
            } else {
                waitTime = 0;
            }

            if (dist[x.second] + t.second + waitTime >= dist[t.first])
                continue;
            dist[t.first] = dist[x.second] + t.second + waitTime;
            pq.push({-dist[t.first], t.first});
        }
    }
    cout << dist[K] << endl;
}
