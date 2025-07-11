#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
int psa[605];
int val = INT_MIN;

int Alice2(int l, int r) {
    if (l >= r) {
        return psa[r] - psa[l - 1];
    }
    int res = psa[r] - psa[l - 1];

    for (int i = l; i < r; i++) {
        res = max(res, psa[i] - psa[l - 1]);
        res = max(res, psa[r] - psa[i]);
    }
    return res;
}

int Bob(int l, int r) {
    if (l >= r) {
        return psa[r] - psa[l - 1];
    }
    int mini = max(Alice2(l, l), Alice2(l + 1, r));
    for (int i = l; i < r; i++) {
        mini = min(mini, max(Alice2(l, i), Alice2(i + 1, r)));
    }
    return mini;
}

int Alice(int l, int r) {
    if (l >= r) {
        return psa[r] - psa[l - 1];
    }
    int res = psa[r] - psa[l - 1];

    for (int i = l; i < r; i++) {
        res = max(res, min(max(Bob(i + 1, r), Alice2(l, i)), max(Bob(l, i), Alice2(i + 1, r))));
    }
    return res;
}


signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        psa[i + 1] = psa[i] + x;
        val = max(val, psa[i + 1]);
    }
    for (int i = 0; i < N; i++) {
        val = max(val, psa[N] - psa[i]);
    }

    cout << max(val, Alice(1, N)) << endl;
}
