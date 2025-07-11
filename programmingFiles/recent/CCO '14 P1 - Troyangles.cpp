#include <bits/stdc++.h>
using namespace std;
#define int long long

int N;
int d[2005][2005];

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                d[i][j] = 1;
            }
        }
    }
    int c = 0;
    for (int x = N; x > 0; x--) {
        for (int y = 1; y <= N; y++) {
            d[x][y] += d[x][y] * min({d[x + 1][y], d[x + 1][y - 1], d[x + 1][y + 1]});
            c += d[x][y];
        }
    }
    cout << c << endl;
}
