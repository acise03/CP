#include <bits/stdc++.h>
using namespace std;
#define int long long

int N;
int findLargestFactor(int x) {
    for (int i = 2; i <= x; i++) {
        if (x % i == 0) {
            return x / i;
        }
    }
    return 1;
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int cost = 0;
    while (N != 1) {
        int f = findLargestFactor(N);
        cost += (N / f - 1);
        N = f * (N / f - 1);
    }
    cout << cost << endl;
}