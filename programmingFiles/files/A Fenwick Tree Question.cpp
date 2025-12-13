#include <bits/stdc++.h>
using namespace std;
#define int long long


int BIT[30][100005];
int N, Q;

int query(int i, int pos) {
    int sum = 0;
    while (pos > 0) {
        sum += BIT[i][pos];
        pos -= pos & -pos;
    }
    return sum;
}

void update(int i, int pos, int val) {
    while (pos <= N) {
        BIT[i][pos] += val;
        pos += pos & -pos;
    }
}


signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        int k;
        cin >> k;
        for (int b = 0; b < 30; b++) {
            if (k & (1 << b)) {
                update(b, i, 1);
            }
        }
    }
    for (int i = 0; i < Q; i++) {
        int k;
        cin >> k;
        if (k == 1) {
            int p, x;
            cin >> p >> x;
            for (int b = 0; b < 30; b++) {
                if (x & (1 << b)) {
                    if (query(b, p) - query(b, p - 1) == 0)
                        update(b, p, 1);
                } else if (query(b, p) - query(b, p - 1) == 1)
                    update(b, p, -1);
            }
        } else if (k == 2) {
            int l, r;
            cin >> l >> r;
            if (l == r) cout << 0 << endl;
            else {
                int res = 0;
                for (int j = 0; j <= 29; j++) {
                    if (query(j, r) - query(j, l - 1) > 0) {
                        int tot = (r - l + 1) * (r - l) / 2;
                        int o = query(j, r) - query(j, l - 1);
                        int z = (r - l + 1) - o;
                        res += (1LL << j) * (tot - (z * (z - 1) / 2));
                    }
                }
                cout << res << endl;
            }
        } else if (k == 3) {
            int l, r;
            cin >> l >> r;
            if (l == r) cout << 0 << endl;
            else {
                int res = 0;
                for (int j = 0; j <= 29; j++) {
                    int valids = (query(j, r) - query(j, l - 1));
                    res += (1LL << j) * (valids) * (valids - 1) / 2;
                }
                cout << res << endl;
            }
        } else if (k == 4) {
            int l, r;
            cin >> l >> r;
            if (l == r) cout << 0 << endl;
            else {
                int res = 0;
                for (int j = 0; j <= 29; j++) {
                    int ones = (query(j, r) - query(j, l - 1));
                    int zeros = r - l + 1 - ones;
                    res += (1LL << j) * ones * zeros;
                }
                cout << res << endl;
            }
        }
    }
}