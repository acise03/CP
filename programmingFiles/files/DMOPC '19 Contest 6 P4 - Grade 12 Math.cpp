#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
#define int long long
using namespace __gnu_pbds;
using namespace std;

template<class T>
using Tree = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
int a[500005];
int N, Q, x, l, r, c;

signed main() {
    cin >> N >> Q;
    Tree<pair<int, int> > mytreee;
    for (int i = 1; i <= N; i++) {
        mytreee.insert({0, i});
    }
    for (int i = 0; i < Q; i++) {

        int questionNumber;
        cin >> questionNumber;
        if (questionNumber == 1) {
            cin >> x;
            mytreee.erase({a[x], x});
            a[x]++;
            mytreee.insert({a[x], x});
        } else if (questionNumber == 2) {
            cin >> x;
            mytreee.erase({a[x], x});
            a[x]--;
            mytreee.insert({a[x], x});
        } else if (questionNumber == 3) {
            cin >> l >> r >> c;
            cout << mytreee.order_of_key({c, r + 1}) - mytreee.order_of_key({c, l}) << endl;
        }
    }
}