#include <bits/stdc++.h>
using namespace std;
int i, S;
int BIT[1025][1025];

void update(int x, int y, int v) {
    while (x < S) {
        for (int n = y; n < S; n += n & -n) {
            BIT[x][n] += v;
        }
        x += x & -x;
    }
}

int query(int x, int y) {
    int s = 0;
    while (x > 0) {
        for (int n = y; n > 0; n -= n & -n) {
            s += BIT[x][n];
        }
        x -= x & -x;
    }
    return s;
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> i;
    while (i != 3) {
        if (i == 0) {
            cin >> S;
            S++;
        }
        if (i == 1) {
            int x, y, a;
            cin >> x >> y >> a;
            update(x + 1, y + 1, a);
        }
        if (i == 2) {
            int l, b, r, t;
            cin >> l >> b >> r >> t;
            cout << query(r + 1, t + 1) - query(r + 1, b) - query(l, t + 1) + query(l, b)
                    << endl;
        }
        cin >> i;
    }
}

/////
