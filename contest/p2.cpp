#include <bits/stdc++.h>
using namespace std;

int n, r, x_1, x_2, y_1, y_2;

bool grid[10005][10005];
int peri;
int maxX = 0;
int maxY = 0;


void expand(int startX, int startY, int xx, int y) {
    bool a = false;

    if (xx + 1 < maxX && !visited[xx + 1][y] && !grid[xx + 1][y]) {
        visited[xx + 1][y] = true;
        expand(startX, startY, xx + 1, y);
        a = true;
    }
    if (y + 1 < maxY && !visited[xx][y + 1] && !grid[xx][y + 1]) {
        visited[xx][y + 1] = true;
        expand(startX, startY, xx, y + 1);
        a = true;
    }
    if (!a) {
        peri -= 2 * (xx - startX + y - startY);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r;

    int minX = 10000;
    int minY = 10000;
    if (r == 1) {
        for (int i = 0; i < n; i++) {
            cin >> x_1 >> y_1 >> x_2 >> y_2;
            maxX = max(maxX, x_2);
            maxY = max(maxY, y_2);

            for (int x = x_1; x < x_2; x++) {
                for (int y = y_1; y < y_2; y++) {
                    grid[x][y] = true;
                }
            }
        }
        int area = 0;
        for (int k = 0; k <= maxX; k++) {
            for (int j = 0; j <= maxX; j++) {
                if (grid[k][j]) {
                    area++;
                }
            }
        }
        cout << area << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cin >> x_1 >> y_1 >> x_2 >> y_2;
            maxX = max(maxX, x_2);
            maxY = max(maxY, y_2);
            minX = min(minX, x_1);
            minY = min(minY, y_1);

            for (int x = x_1; x < x_2; x++) {
                for (int y = y_1; y < y_2; y++) {
                    grid[x][y] = true;
                }
            }
        }
        int area = 0;
        for (int k = 0; k <= maxX; k++) {
            for (int j = 0; j <= maxX; j++) {
                if (grid[k][j]) {
                    area++;
                }
            }
        }
        cout << area << endl;
        peri = 2 * (maxX + maxY - minX - minY);
        for (int k = 0; k <= maxX; k++) {
            for (int j = 0; j <= maxX; j++) {
                if (!visited[k][j] && !grid[k][j]) {
                    visited[k][j] = true;
                    expand(k, j, k, j);
                }
            }
        }
        cout << peri << endl;
    }
}
