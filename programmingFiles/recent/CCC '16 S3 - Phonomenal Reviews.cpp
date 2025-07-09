#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, M;
bool RealRestaurants[100005];
set<pair<int, int> > adjList[100005];
bool visited[100005];
int totSum;
bool keep[100005];

void traverse(int n, int p) {
    if (keep[n]) {
        if (p != -1)
            totSum++;
        for (auto i: adjList[n]) {
            if (i.first != p) {
                traverse(i.first, n);
            }
        }
    }
}


pair<int, int> farthestNode(int loc, int prev) {
    // dist, nextNode
    pair<int, int> farthest = {0, loc};
    for (auto x: adjList[loc]) {
        if (x.first == prev || !keep[x.first]) continue;
        pair<int, int> p = farthestNode(x.first, loc);
        if (p.first + x.second > farthest.first) {
            farthest = {p.first + x.second, p.second};
        }
    }
    return farthest;
}


bool t(int x) {
    bool k = RealRestaurants[x];
    visited[x] = true;
    for (pair p: adjList[x]) {
        if (!visited[p.first] && t(p.first)) k = true;
    }
    if (k || RealRestaurants[x]) {
        keep[x] = true;
        return true;
    }
    return false;
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int n = 0;

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        RealRestaurants[x] = true;
        n = x;
        keep[x] = true;
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].insert({b, 1});
        adjList[b].insert({a, 1});
    }
    t(n);
    traverse(n, -1);
    pair<int, int> p = farthestNode(n, -1);
    int d = farthestNode(p.second, -1).first;
    cout << 2 * totSum - d << endl;
}
