#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > adjList[100005];
int distances[100005];
int roadCount[100005];


int N, M, a, b, t;

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> t;
        adjList[a].push_back({b, t});
        adjList[b].push_back({a, t});
    }
    fill_n(roadCount, N + 1, INT_MAX);
    fill_n(distances, N + 1, INT_MAX);
    roadCount[1] = 0;
    distances[1] = 0;
    deque<int> dq;
    dq.push_back(1);
    while (!dq.empty()) {
        int vertex = dq.front();
        dq.pop_front();
        for (auto p: adjList[vertex]) {
            if (distances[vertex] + p.second < distances[p.first]) {
                distances[p.first] = distances[vertex] + p.second;
                roadCount[p.first] = roadCount[vertex] + 1;
                if (p.second == 1)
                    dq.push_back(p.first);
                else
                    dq.push_front(p.first);
            } else if (distances[vertex] + p.second == distances[p.first] && roadCount[vertex] + 1 < roadCount[p.
                           first]) {
                roadCount[p.first] = roadCount[vertex] + 1;
                dq.push_back(p.first);
            }
        }
    }
    if (distances[N] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << distances[N] << " " << roadCount[N] << endl;
    }
}
