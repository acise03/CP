#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
int memo[1000005];

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    memset(memo, -1, 1000001);
    memo[0] = 1;
    memo[1] = 1;
    cin >> N;
    int res = 1;
    for (int x = 2; x <= sqrt(double(N)); x++) {
        int c = 0;
        for (int w = 1; w <= double(x) / 2; w++) {
            c += memo[w] * (floor(x / w) - floor(x / (w + 1)));
        }
        if (c == 0) { c++; }
        memo[x] = c;
        res += c;
    }

    for (int y = 2; static_cast<double>(N) / static_cast<double>(y) > static_cast<double>(sqrt(N)); y++) {
        res += memo[N / y];
    }
    cout << res << endl;
}
