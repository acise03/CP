#include <bits/stdc++.h>
using namespace std;

int R, C, s_x, s_y, d_x, d_y;
int floodTime[50][50];
int minutes[50][50];
char grid[50][50];

void floodFill(int x, int y, int time) {
    if (grid[x][y] != 'X' && grid[x][y] != 'D' && floodTime[x][y] > time) {
        floodTime[x][y] = time;
        if (x > 0) {
            floodFill(x - 1, y, time + 1);
        }
        if (x < R - 1) {
            floodFill(x + 1, y, time + 1);
        }
        if (y > 0) {
            floodFill(x, y - 1, time + 1);
        }
        if (y < C - 1) {
            floodFill(x, y + 1, time + 1);
        }
    }
}


int main() {
    cin >> R >> C;

    for (int i = 0; i < 50; ++i) {
        fill(floodTime[i], floodTime[i] + 50, INT_MAX);
        fill(minutes[i], minutes[i] + 50, INT_MAX);
    }

    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            grid[i][j] = s[j];
            if (grid[i][j] == 'S') {
                s_x = i;
                s_y = j;
            }
            if (grid[i][j] == 'D') {
                d_x = i;
                d_y = j;
            }
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == '*') {
                floodFill(i, j, 0);
            }
        }
    }

    deque<pair<int, int> > coord;

    coord.push_back({s_x, s_y});
    minutes[s_x][s_y] = 0;

    while (!coord.empty()) {
        auto p = coord.front();
        coord.pop_front();

        int x = p.first;
        int y = p.second;

        if (grid[x][y] != 'X' && grid[x][y] != '*' && minutes[x][y] < floodTime[x][y]) {
            if (x > 0) {
                if (minutes[x][y] + 1 < minutes[x - 1][y]) {
                    minutes[x - 1][y] = minutes[x][y] + 1;
                    coord.push_back({x - 1, y});
                }
            }
            if (x < R - 1) {
                if (minutes[x][y] + 1 < minutes[x + 1][y]) {
                    minutes[x + 1][y] = minutes[x][y] + 1;
                    coord.push_back({x + 1, y});
                }
            }
            if (y > 0) {
                if (minutes[x][y] + 1 < minutes[x][y - 1]) {
                    minutes[x][y - 1] = minutes[x][y] + 1;
                    coord.push_back({x, y - 1});
                }
            }
            if (y < C - 1) {
                if (minutes[x][y] + 1 < minutes[x][y + 1]) {
                    minutes[x][y + 1] = minutes[x][y] + 1;
                    coord.push_back({x, y + 1});
                }
            }
        }
    }
    if (minutes[d_x][d_y] == INT_MAX) {
        cout << "KAKTUS" << endl;
    } else if (minutes[d_x][d_y] < floodTime[d_x][d_y]) {
        cout << minutes[d_x][d_y] << endl;
    } else
        cout << "KAKTUS" << endl;
}
