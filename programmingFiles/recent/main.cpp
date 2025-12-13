#include <bits/stdc++.h>
using namespace std;
int N, M;
double finicky = 0;
map<string, int> fruits;
vector<pair<int, double> > adjList[505];
vector<int> revAdjList[505];
bool visited[505];
double values[505];
bool canConnectBackToApple[505];
bool poss = false;

void connectToApple() {
    queue<int> qq;
    qq.push(fruits["APPLES"]);
    canConnectBackToApple[fruits["APPLES"]] = true;
    while (!qq.empty()) {
        int vv = qq.front();
        qq.pop();
        for (auto k: adjList[vv]) {
            if (!canConnectBackToApple[k.first]) {
                canConnectBackToApple[k.first] = true;
                qq.push(k.first);
            }
        }
    }
}


void findCycle() {
    queue<pair<int, double> > q;
    q.push({fruits["APPLES"], 1});
    visited[fruits["APPLES"]] = true;
    values[fruits["APPLES"]] = 1;
    while (!q.empty()) {
        pair p = q.front();
        q.pop();
        int v = p.first;
        double val = p.second;
        for (auto pp: adjList[v]) {
            if (visited[pp.first]) {
                if (values[pp.first] < val * pp.second + finicky) {
                    if (canConnectBackToApple[pp.first]) {
                        poss = true;
                        break;
                    }
                }
            } else {
                visited[pp.first] = true;
                values[pp.first] = values[v] * pp.second;
                q.push({pp.first, values[pp.first]});
            }
        }
    }
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        fruits[s] = i;
    }
    for (int i = 0; i < M; i++) {
        string a, b;
        cin >> a >> b;
        double exchangeRate;
        cin >> exchangeRate;
        adjList[fruits[a]].push_back({fruits[b], exchangeRate});
        revAdjList[fruits[b]].push_back(fruits[a]);
    }


    connectToApple();
    findCycle();

    if (poss) {
        cout << "YA\n";
    } else cout << "NAW\n";
}
