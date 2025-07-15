#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, S, sx, sy, vx, vy;
tuple<int, int, int,int> squirrels[15];
float memo[15][1 << 15];

float dp(int v, int mask, float x, float y) {
    if (mask == 0) {
        return 0;
    }
    if (memo[v][mask] != -1) {
        return memo[v][mask];
    }
    float res = INT_MAX;
    for (int sq = 0; sq < N; sq++) {
        sx = get<0>(squirrels[sq]);
        sy = get<1>(squirrels[sq]);
        vx = get<2>(squirrels[sq]);
        vy = get<3>(squirrels[sq]);
        if (mask & (1 << sq)) {
            float a = vx * vx + vy * vy - S * S;
            float b = 2 * sx * vx + 2 * sy * vy - 2 * x * vx - 2 * vy * y;
            float c = sx * sx + sy * sy - x * x - y * y - 2 * sx * x - 2 * sy * y;
            float k1 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
            float k2 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
            res = min({
                res, abs(k1) + dp(sq, mask & ~(1 << sq), sx + vx * k1, sy + vy * k1),
                abs(k2) + dp(sq, mask & ~(1 << sq), sx + vx * k2, sy + vy * k2)
            });
        }
    }    
    memo[v][mask] = res;
    return res;
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> sx >> sy >> vx >> vy;
        squirrels[i] = {sx, sy, vx, vy};
        for (int j = 0; j < 1 << 15; j++) {
            memo[i][j] = -1;
        }
    }

    cout << dp(0, ((1 << N) - 1), 0, 0) << endl;
}
