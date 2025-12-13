#include <bits/stdc++.h>
using namespace std;
#define int long long


int BIT[1000005];
int N, P;


int query(int pos) {
    int sum = 0;
    while (pos > 0) {
        sum += BIT[pos];
        pos -= pos & -pos;
    }
    return sum;
}

void update(int pos, int val) {
    while (pos <= 1000000) {
        BIT[pos] += val;
        pos += pos & -pos;
    }
}

vector<int> v;
vector<int> psa;

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int g;
        cin >> g;
        v.push_back(g);
    }
    cin >> P;
    vector<int> one;
    psa.push_back(0);
    one.push_back(0);
    for (int i = 1; i <= N; i++) {
        psa.push_back(psa[i - 1] + v[i - 1] - P);
        one.push_back(psa[i]);
    }
    sort(psa.begin(), psa.end());
    psa.erase(unique(psa.begin(), psa.end()), psa.end());

    int res = 0;
    update(lower_bound(psa.begin(), psa.end(), one[0]) - psa.begin() + 1, 1);
    for (int i = 1; i <= N; i++) {
        int kk = (lower_bound(psa.begin(), psa.end(), one[i]) - psa.begin()) + 1;
        res += query(kk);
        update(kk, 1);
    }
    cout << res << endl;
}