#include <bits/stdc++.h>
using namespace std;

int w, h, rW, rH, k;
bool grid[20][20];

int rec(int x, int y, string prevDir) {
    if (prevDir == "up") {
        if (!grid[x-1][y]) rec(x-1, y, "up");
    }
}

int main() {
    cin >> w >> h;
    cin >> rW >> rH;
    cin >> k;

    for (int i = 0; i < rW; i++) {
        for (int j = 0; j < rH; j++) {
            grid[i][j] = true;
        }
    }
    for (int i = 0; i < rW; i++) {
        for (int j = h - rH; j < h; j++) {
            grid[i][j] = true;
        }
    }
    for (int i = w - rW; i < w; i++) {
        for (int j = 0; j < rH; j++) {
            grid[i][j] = true;
        }
    }
    for (int i = w - rW; i < w; i++) {
        for (int j = h - rH; j < h; j++) {
            grid[i][j] = true;
        }
    }

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    // start: [rW-w][0]
}
