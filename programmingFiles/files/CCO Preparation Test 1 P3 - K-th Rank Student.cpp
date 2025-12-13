#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
#define int long long
using namespace __gnu_pbds;
using namespace std;

template<class T>
using Tree = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
int a[100005];
int N, M, I, R, S, L, v;
int p[100005], height[100005], setSize[100005];
int numSets;
Tree<pair<int, int> > arr[100005];

void initialize() {
    for (int i = 1; i <= N; ++i) {
        p[i] = i;
        setSize[i] = 1;
    }
    numSets = N;
}

int findSet(int i) {
    if (p[i] == i) return i;
    p[i] = findSet(p[i]);
    return p[i];
}

bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

int numDisjointSets() {
    return numSets;
}

int sizeOfSet(int i) {
    return setSize[findSet(i)];
}

void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;
    int x = findSet(i);
    int y = findSet(j);
    if (height[x] > height[y]) swap(x, y);
    p[x] = y;
    if (height[x] == height[y]) height[y]++;
    if (arr[x].size() > arr[y].size()) swap(x, y);
    for (auto it = arr[x].begin(); it != arr[x].end(); ++it) {
        arr[y].insert(*it);
    }
    setSize[y] += setSize[x];
    numSets--;
}

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    initialize();
    for (int i = 1; i <= N; i++) {
        int k;
        cin >> k;
        a[i] = i;
        arr[i].insert({k, i});
    }
    for (int i = 1; i <= M; i++) {
        int x, y;
        cin >> x >> y;
        unionSet(x, y);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        char c;
        cin >> c;
        if (c == 'B') {
            int x, y;
            cin >> x >> y;
            unionSet(x, y);
        } else if (c == 'Q') {
            int x, k;
            cin >> x >> k;
            if (sizeOfSet(x) < k)
                cout << -1 << endl;
            else
                cout << arr[findSet(x)].find_by_order(k - 1)->second << endl;
        }
    }
}