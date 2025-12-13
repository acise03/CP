#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, D, id, col, C;
vector<int> children[305];
set<pair<int,int> > memo[305];
int color[305];
int highests[305];
bool updated[305];
int currD;


signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> D;
    int tot = 0;
    for (int i = 0; i < N; i++) {
        cin >> id >> col >> C;
        if (col == 1) {
            color[id] = 1;
        } else {
            color[id] = -1;
        }
        tot += color[id];
        for (int j = 0; j < C; j++) {
            int id2;
            cin >> id2;
            children[id].push_back(id2);
        }
    }

    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < N; i++) {
            if (updated[i]) continue;
            changed = true;
            bool allUpdated = true;
            for (int x: children[i]) {
                if (!updated[x]) allUpdated = false;
            }
            if (!allUpdated) continue;
            updated[i] = true;
            if (children[i].size() == 0) {
                memo[i].insert({color[i], 1});
                memo[i].insert({0, 0});
                highests[i] = color[i];
            } else if (children[i].size() == 1) {
                for (auto p: memo[children[i][0]]) {
                    memo[i].insert(p);
                }
                memo[i].insert({highests[children[i][0]] + color[i], 1});
                highests[i] = highests[children[i][0]] + color[i];
            } else {
                for (auto p: memo[children[i][1]]) memo[i].insert(p);
                for (auto p: memo[children[i][0]]) {
                    memo[i].insert(p);
                    for (auto u: memo[children[i][1]]) {
                        memo[i].insert({p.first + u.first, p.second + u.second});
                    }
                }
                memo[i].insert({highests[children[i][0]] + highests[children[i][1]] + color[i], 1});
                highests[i] = highests[children[i][0]] + highests[children[i][1]] + color[i];
            }
        }
    }
    int mini = INT_MAX;
    for (int i = 0; i < N; i++) {
        for (auto a: memo[i]) {
            if (tot - a.first == D)
                mini = min(mini, a.second);
        }
    }
    if (mini == INT_MAX) mini=-1;
    cout << mini << endl;
}