#include <bits/stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/tle17c4p3
*/
int N, M, D;
int itemCount[300000];
vector<int> recepies[300000];
int nextt = 1;

bool dfs(int v) {
    bool tP = true;
    if (recepies[v].size() < 1) {
        nextt = max(nextt, v);
        tP = false;
    }
    for (int i: recepies[v]) {
        bool possible;
        if (itemCount[i] < 1) {
            possible = dfs(i);
        } else
            possible = true;
        if (!possible) {
            nextt = max(nextt, i);
            tP = false;
            break;
        }
    }
    if (tP) {
        for (int i: recepies[v]) {
            itemCount[i]--;
        }
        itemCount[v]++;
    }
    return tP;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> D;

    for (int i = 0; i < M; i++) {
        int t, reqn;
        cin >> t >> reqn;
        for (int j = 0; j < reqn; j++) {
            int k;
            cin >> k;
            recepies[t].push_back(k);
        }
    }
    for (int i = 0; i < D; i++) {
        int p;
        cin >> p;
        itemCount[p]++;
        if (p >= nextt) {
            nextt = 0;
            if (dfs(1)) {
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
