#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
#define int long long
using namespace __gnu_pbds;
using namespace std;

template<class T>
using Tree = tree<T, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update>;
int a[1000005];
int N, M, I, R, S, L, v;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    Tree<int> treeee;
    int nextInd = N + 1;
    for (int i = 1; i <= N; i++) {
        int k;
        cin >> k;
        treeee.insert(k);
    }
    int lastAns = 0;
    for (int i = 0; i < M; i++) {
        char c;
        cin >> c;
        cin >> v;
        v ^= lastAns;
        if (c == 'I') {
            treeee.insert(v);
            nextInd++;
        } else if (c == 'R') {
            if (*treeee.find_by_order(treeee.order_of_key(v)) == v) {
                treeee.erase(treeee.find_by_order(treeee.order_of_key(v)));
            }
        } else if (c == 'S') {
            lastAns = *treeee.find_by_order(v - 1);
            cout << lastAns << endl;
        } else if (c == 'L') {
            if (*treeee.find_by_order(treeee.order_of_key(v)) == v) {
                lastAns = 1 + treeee.order_of_key(v);
                cout << lastAns << endl;
            } else {
                lastAns = -1;
                cout << -1 << endl;
            }
        }
    }
    for (auto it = treeee.begin(); it != treeee.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}