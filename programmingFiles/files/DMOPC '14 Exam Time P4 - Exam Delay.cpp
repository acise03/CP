#include <bits/stdc++.h>
using namespace std;

int V, E, m, n, d, s;
vector<tuple<int, int, int> > adjList[1005];
float times[1005];
int roadsTaken[1005];
float timeDelayed[1005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        cin >> m >> n >> d >> s;
        adjList[m].push_back({d, s, n});
        adjList[n].push_back({d, s, m});
    }
    fill_n(times, 1005, INT_MAX);
    times[1] = 0;
    roadsTaken[1] = 0;
    priority_queue<pair<float, int> > pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        if (-x.first > times[x.second]) {
            continue;
        }
        for (auto t: adjList[x.second]) {
            if (times[x.second] + get<0>(t) / get<1>(t) >= times[get<2>(t)]) {
                continue;
            }
            times[get<2>(t)] = times[x.second] + get<0>(t) / get<1>(t);
            roadsTaken[get<2>(t)] = roadsTaken[x.second] + 1;
            d = get<0>(t);
            s = get<1>(t);
            timeDelayed[get<2>(t)] = timeDelayed[x.second] + static_cast<float>(d) / (s * 0.75f) * 60 - static_cast<
                                         float>(d) / s * 60;
            pq.push({-times[get<2>(t)], get<2>(t)});
        }
    }
    cout << roadsTaken[V] << endl;
    cout << round(timeDelayed[V]) << endl;
}
