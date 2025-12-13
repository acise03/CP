#include<bits/stdc++.h>
#define int long long
using namespace std;
int N, M, A, B, xi, yi, L, C, Q, D;
vector<tuple<int, int, int> > adjList[200005];
vector<tuple<int, int, int> > adjListReverse[200005];
int distA[100005]; // for each point, store closest dist to A, closest dist to B
int distB[100005]; // for each point, store closest dist to A, closest dist to B
bool partOfGrid[100005];
bool visited[100005];
int psa[100005];


void func() {
    for (int v = 0; v < 100005; v++) {
        distA[v] = LONG_LONG_MAX;
        distB[v] = LONG_LONG_MAX;
    }
    distA[A] = 0;
    distB[B] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > vals;
    vals.push({0, A});
    while (!vals.empty()) {
        int ddist = vals.top().first;
        int vertex = vals.top().second;
        vals.pop();
        if (distA[vertex] < ddist) {
            continue;;
        }

        for (auto t: adjList[vertex]) {
            if (distA[get<0>(t)] > ddist + get<1>(t)) {
                distA[get<0>(t)] = ddist + get<1>(t);
                vals.push({ddist + get<1>(t), get<0>(t)});
            }
        }
    }
    vals.push({0, B});
    while (!vals.empty()) {
        int ddist = vals.top().first;
        int vertex = vals.top().second;
        vals.pop();
        if (distB[vertex] < ddist) {
            continue;;
        }

        for (auto t: adjListReverse[vertex]) {
            if (distB[get<0>(t)] > ddist + get<1>(t)) {
                distB[get<0>(t)] = ddist + get<1>(t);
                vals.push({ddist + get<1>(t), get<0>(t)});
            }
        }
    }
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> A >> B;
    for (int i = 1; i <= M; i++) {
        cin >> xi >> yi >> L >> C;
        adjList[xi].push_back({yi, L, C});
        adjListReverse[yi].push_back({xi, L, C});
    }

    func();
    cin >> Q;
    vector<pair<int, int> > edgeVals;
    for (int v = 1; v <= N; v++) {
        for (auto t: adjList[v]) {
            int n = get<0>(t);
            if (distA[v] + distB[n] + get<1>(t) <= 1000000000 && distA[v] + distB[n] + get<1>(t) >= 0 && distA[v] >= 0
                && distB[n] >= 0 && distA[v] <= 1000000000 && distB[n] <= 1000000000)
                edgeVals.push_back({distA[v] + distB[n] + get<1>(t), get<2>(t)});
        }
    }
    sort(edgeVals.begin(), edgeVals.end());
    for (int i = 1; i <= edgeVals.size(); i++) {
        psa[i] = psa[i - 1] + edgeVals[i - 1].second;
    }
    for (int i = 0; i < Q; i++) {
        cin >> D;
        int ij = upper_bound(edgeVals.begin(), edgeVals.end(), make_pair(D,LONG_LONG_MAX)) - edgeVals.begin();
        cout << psa[ij] <<
                endl;
    }
}