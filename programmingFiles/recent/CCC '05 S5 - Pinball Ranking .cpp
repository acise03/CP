#include <bits/stdc++.h>
using namespace std;
#define int long long
int r, c;
char grid[376][85];
int m;
set<pair<int, int> > path;

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }
    cin >> m;
    int vert = 0;
    int horiz = 0;
    int maxVert = 0;
    int maxHoriz = 0;
    int minVert = 0;
    int minHoriz = 0;
    char dir = 'N';
    for (int i = 0; i < m; i++) {
        char x;
        cin >> x;
        path.insert({vert, horiz});
        maxHoriz = max(maxHoriz, horiz);
        minHoriz = min(minHoriz, horiz);
        maxVert = max(maxVert, vert);
        minVert = min(minVert, vert);
        if (x == 'F') {
            if (dir == 'N') {
                vert--;
            } else if (dir == 'S') {
                vert++;
            } else if (dir == 'W') {
                horiz--;
            } else if (dir == 'E') {
                horiz++;
            }
        } else if (x == 'L') {
            if (dir == 'N') {
                dir = 'W';
            } else if (dir == 'S') {
                dir = 'E';
            } else if (dir == 'W') {
                dir = 'S';
            } else if (dir == 'E') {
                dir = 'N';
            }
        } else if (x == 'R') {
            if (dir == 'N') {
                dir = 'E';
            } else if (dir == 'S') {
                dir = 'W';
            } else if (dir == 'W') {
                dir = 'N';
            } else if (dir == 'E') {
                dir = 'S';
            }
        }
    }
    maxHoriz = max(maxHoriz, horiz);
    minHoriz = min(minHoriz, horiz);
    maxVert = max(maxVert, vert);
    minVert = min(minVert, vert);
    path.insert({vert, horiz});
    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            bool poss = true;
            for (auto p: path) {
                if (y + p.first < 0 || y + p.first >= r || x + p.second < 0 || x + p.second >= c || grid[y + p.first][
                        x + p.second] ==
                    'X') {
                    poss = false;
                    break;
                }
            }
            if (poss) {
                grid[y + vert][x + horiz] = '*';
            }
        }
    }
    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            bool poss = true;
            for (auto p: path) {
                if (y + p.second >= r || y + p.second < 0 || x - p.first < 0 || x - p.first >= c || grid[y + p.second][
                        x - p.first] == 'X') {
                    poss = false;
                    break;
                }
            }
            if (poss) {
                grid[y + horiz][x - vert] = '*';
            }
        }
    }

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            bool poss = true;
            for (auto p: path) {
                if (y - p.first < 0 || y - p.first >= r || x - p.second < 0 || x - p.second >= c || grid[y - p.first][
                        x - p.second] == 'X') {
                    poss = false;
                    break;
                }
            }
            if (poss) {
                grid[y - vert][x - horiz] = '*';
            }
        }
    }

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            bool poss = true;
            for (auto p: path) {
                if (y - p.second < 0 || y - p.second >= r || x + p.first >= c || x + p.first < 0 || grid[y - p.second][
                        x + p.first] == 'X') {
                    poss = false;
                    break;
                }
            }
            if (poss) {
                grid[y - horiz][x + vert] = '*';
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}
