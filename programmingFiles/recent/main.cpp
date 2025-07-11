#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, M, R, C;
char g[2005][2005];

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> R >> C;

    if (R < C) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < M; j++) {
                g[i][j] = 'a';
            }
        }
        char nextt = 'b';       

        for (int i = 0; i < C; i++) {
            for (int j = 0; j < N; j++) {
                if (g[j][i] == 'a') {
                    g[N - j - 1][i] = 'a';
                } else {
                    g[j][i] = nextt;
                }
            }
            nextt++;
            if (nextt > 'z') {
                nextt = 'b';
            }
        }
    } else {
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < N; j++) {
                g[j][i] = 'a';
            }
        }
        char nextt = 'b';

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < M; j++) {
                if (g[i][j] == 'a') {
                    g[i][M - j - 1] = 'a';
                } else {
                    g[i][j] = nextt;
                }
            }
            nextt++;
            if (nextt > 'z') {
                nextt = 'b';
            }
        }
    }
    char nextletter = 'c';
    for (int i = 0; i < N; i++) {
        char letter = nextletter;
        nextletter = letter + 1;
        if (nextletter > 'z') {
            nextletter = 'c';
        }
        for (int j = 0; j < M; j++) {
            if (isblank(g[i][j])) {
                g[i][j] = letter;
                letter++;
                if (letter > nextletter + 2) {
                    letter = nextletter - 1;
                }
            }
        }
    }
    int rowCount = 0;
    int colCount = 0;
    for (int i = 0; i < N; i++) {
        bool isPalin = true;
        for (int j = 0; j <= ceil(M / 2); j++) {
            if (g[i][j] != g[i][M - j - 1]) {
                isPalin = false;
                break;
            }
        }
        if (isPalin)
            rowCount++;
    }
    for (int j = 0; j < M; j++) {
        bool isPalin = true;
        for (int i = 0; i <= ceil(N / 2); i++) {
            if (g[i][j] != g[N - i - 1][j]) {
                isPalin = false;
                break;
            }
        }
        if (isPalin)
            colCount++;
    }
    if (rowCount == R && colCount == C) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << g[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
