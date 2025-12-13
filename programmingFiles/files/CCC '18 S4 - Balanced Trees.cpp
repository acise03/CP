#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
unordered_map<int, int> memo;
int rec(int x) {
    if (memo.find(x) != memo.end()) {
        return memo[x];
    }
    int c = 0;
    int w = 2;
    while (w <= x) {
        int y = x / w;
        int n = x / y + 1;
        c += rec(y) * (n - w);
        w = n;
    }
    memo[x] = c;
    return c;
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    memo[1] = 1;
    cout << rec(N) << endl;
}