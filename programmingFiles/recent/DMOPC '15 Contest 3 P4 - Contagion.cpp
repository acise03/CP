#include <bits/stdc++.h>
using namespace std;
#define int long long


int N, M, x, y, source, Q;

pair<int, int> coordinates[3000];
vector<int> valids;
int dist[3000];
priority_queue<pair<int, int> > pq;


signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        coordinates[i] = {x, y};
    }
    cin >> source;
    fill_n(dist, N, LLONG_MAX);
    source--;

    dist[source] = 0;
    pq.push({0, source}); // dist, vertex

    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();

        if (x.first > dist[x.second]) continue;
        for (int i = 0; i < N; i++) {
            if (i == x.second) continue;
            int d = (coordinates[x.second].first - coordinates[i].first) * (
                        coordinates[x.second].first - coordinates[i].first) +
                    (coordinates[x.second].second - coordinates[i].second) * (
                        coordinates[x.second].second - coordinates[i].second);

            if (dist[x.second] + d < dist[i]) {
                dist[i] = dist[x.second] + d;
                pq.push({-dist[i], i});
            }
        }
    }
    for (int i = 0; i < N; i++) {
        valids.push_back(dist[i]);
    }
    sort(valids.begin(), valids.end());


    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int hours;
        cin >> hours;
        if (hours >= valids.back()) {
            cout << N << endl;
            continue;
        }
        int x = upper_bound(valids.begin(), valids.end(), hours) - valids.begin();
        cout << x << endl;
    }
}
