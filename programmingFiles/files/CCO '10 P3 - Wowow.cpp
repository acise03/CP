#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
#define int long long
using namespace __gnu_pbds;
using namespace std;

template<class T>
using Tree = tree<T, null_type, greater<>, rb_tree_tag, tree_order_statistics_node_update>;
int a[1000005];
int N, X, R, Q, K;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    Tree<pair<int, int> > treeee;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == 'N') {
            cin >> X >> R;
            treeee.insert({R, X});
            a[X] = R;
        } else if (c == 'M') {
            cin >> X >> R;
            treeee.erase({a[X], X});
            a[X] = R;
            treeee.insert({R, X});
        } else if (c == 'Q') {
            cin >> K;
            cout << treeee.find_by_order(K - 1)->second << "\n";
        }
    }
}