#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
int memo[405][405];
int maxi = INT_MIN;


signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> memo[i][i + 1];
        if (i > 0) {
            if (memo[i][i + 1] == memo[i - 1][i]) {
                memo[i - 1][i + 1] = 2 * memo[i][i + 1];
            } else {
                memo[i - 1][i + 1] = -1;
            }
        }
    }

    for (int size = 2; size <= N; size++) {
        for (int l = 0; l + size <= N; l++) {
            int r = l + size;
            for (int i = l + 1; i < r; i++) {
                int x = memo[l][i];
                int y = memo[i][r];
                if (x == y && x != -1) {
                    memo[l][r] = x + y;
                }
            }
            for (int i = l + 1; i < r; i++) {
                for (int j = i + 1; j < r; j++) {
                    int x = memo[l][i];
                    int y = memo[i][j];
                    int z = memo[j][r];
                    if (x == z && x != -1 && y != -1) {
                        memo[l][r] = x + y + z;
                    }
                }
            }
            if (memo[l][r] == 0) {
                memo[l][r] = -1;
            }
        }
    }
    for (int i = 0; i < 405; i++) {
        for (int j = 0; j < 405; j++) {
            maxi = max(maxi, memo[i][j]);
        }
    }
    cout << maxi << endl;
}