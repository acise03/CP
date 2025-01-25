#include <bits/stdc++.h>
using namespace std;

int N, u, v, w, maxi, mini;

vector<pair<int, int> > graph[500005]; // {vertex, weight}
int d[500005][2];

// length, last vertex;
pair<int, int> rec(int v, int p, int length) {
    if (graph[v].empty() || (graph[v].size() == 1 && graph[v][0].first == p)) {
        return {0, v};
    }
    pair<int, int> maxi = {length, v};
    for (auto pa: graph[v]) {
        if (pa.first != p) {
            int s = length + pa.second;
            auto res = rec(pa.first, v, 0);
            s += res.first;
            if (s > maxi.first) {
                maxi = {s, res.second};
            }
        }
    }
    return maxi;
}




pair<int, int> r(int v, int p, int length) {
    if (graph[v].empty() || (graph[v].size() == 1 && graph[v][0].first == p)) {
        return {0, v};
    }
    pair<int, int> maxi = {length, v};
    for (auto pa: graph[v]) {
        if (pa.first != p) {
            int s = length + pa.second;
            auto res = r(pa.first, v, 0);
            s += res.first;
            if (s < maxi.first) {
                maxi = {s, res.second};
            }
        }
    }
    return maxi;
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

    int k = rec(1, -1, 0).second;
    auto maxL = rec(k, -1, 0);
    cout << maxL.first << endl;

    int k2 = maxL.second;

    int mini = maxL.first;

    do {
        auto res = r(k2, -1, 0);
        if (res.first < mini)
            mini = res.first;
        k2 = res.second;
    } while (k2 != k);
    cout << mini << endl;
}