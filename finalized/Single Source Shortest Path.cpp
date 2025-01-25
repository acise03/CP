#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M, u, v, w;
set<int> containing;
vector<pair<int, int> > adjList[1005];
int dist[1005];

signed main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        adjList[v].push_back({u, w});
        adjList[u].push_back({v, w});
    }
    fill_n(dist, 1005, INT_MAX);
    dist[1] = 0;

    for (int i = 1; i <= N; i++) {
        int vv = -1;
        int minI = -1;
        for (int ii = 0; ii < adjList[i].size(); ii++) {
            if (containing.count(adjList[i][ii].first) < 1 && dist[adjList[i][ii].first] > dist[i] + adjList[i][ii].
                second) {
                dist[adjList[i][ii].first] = dist[i] + adjList[i][ii].second;
                if (adjList[i][ii].second < adjList[i][minI].second) {
                    minI = adjList[i][ii].first;
                }
            }
        }
        if (minI != -1) {
            containing.insert(minI);
            for (auto e: adjList[minI]) {
                if (dist[minI] + e.second < dist[e.first]) {
                    dist[e.first] = dist[minI] + e.second;
                }
            }
        }
    }
    for (int lastV = 1; lastV <= N; lastV++) {
        if (dist[lastV] == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << dist[lastV] << endl;
        }
    }
}
