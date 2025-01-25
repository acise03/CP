#include <bits/stdc++.h>
using namespace std;

int L, n, ind;

map<string, int> nameToInd;
int prevs[1000];
string alphaWord;
vector<int> paths[1000];

int rec(int v, int p, int c) {
    if (paths[v].empty()) {
        return 0;
    }
    int m = 0;
    for (int vv: paths[v]) {
        if (vv != v && vv != p) {
            m = max(m, rec(vv, v, c) + 1);
        }
    }
    return m;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> L;

    for (int i = 0; i < L; i++) {
        cin >> n;

        int longest = 0;

        vector<string> currNames;
        int prev = -1;
        alphaWord = "{";

        nameToInd.clear();
        memset(prevs, -1, 500);
        for (int j = 0; j < 1000; j++) {
            paths[j].clear();
        }
        int lastest = 0;

        for (int j = 0; j < n; j++) {
            string name;
            cin >> name;
            if (name < alphaWord) {
                alphaWord = name;
            }
            int v = ind;

            if (nameToInd.count(name) == 0) {
                nameToInd[name] = v;
                ind++;

                prevs[v] = prev;
                if (prev != -1) {
                    paths[prev].push_back(v);
                    paths[v].push_back(prev);
                }
                prev = v;
            } else {
                v = nameToInd[name];
                prev = v;
                paths[v].push_back(prev);
                paths[prev].push_back(v);
            }
            lastest = v;
        }
        longest = rec(lastest, -1, 0);
        cout << 10 * n - 10 * longest * 2 << endl;
    }
}
