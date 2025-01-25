#include <bits/stdc++.h>
using namespace std;

int N, M;
int grid[1005][1005];
int minCookies[1005][1005];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            grid[i][j] = 0;
            if (s[j] == 'C') {
                grid[i][j] = 1;
            }
        }
    }

    memset(minCookies, -1, sizeof(minCookies));
    minCookies[0][0] = grid[0][0];
    deque<pair<int, int> > nexts;
    nexts.push_back({0, 0});
    while (!nexts.empty()) {
        auto p = nexts.front();
        int x = p.first;
        int y = p.second;
        nexts.pop_front();

        if (p.first == N - 1 && p.second == M - 1) {
            break;
        }

        if (x > 0) {
            if (minCookies[x - 1][y] == -1) {
                if (grid[x - 1][y] == 0) {
                    minCookies[x - 1][y] = minCookies[x][y];
                    nexts.push_front({x - 1, y});
                } else {
                    minCookies[x - 1][y] = minCookies[x][y] + 1;
                    nexts.push_back({x - 1, y});
                }
            }
        }
        if (x < N - 1) {
            if (minCookies[x + 1][y] == -1) {
                if (grid[x + 1][y] == 0) {
                    minCookies[x + 1][y] = minCookies[x][y];
                    nexts.push_front({x + 1, y});
                } else {
                    minCookies[x + 1][y] = minCookies[x][y] + 1;
                    nexts.push_back({x + 1, y});
                }
            }
        }
        if (y > 0) {
            if (minCookies[x][y - 1] == -1) {
                if (grid[x][y - 1] == 0) {
                    minCookies[x][y - 1] = minCookies[x][y];
                    nexts.push_front({x, y - 1});
                } else {
                    minCookies[x][y - 1] = minCookies[x][y] + 1;
                    nexts.push_back({x, y - 1});
                }
            }
        }
        if (y < M - 1) {
            if (minCookies[x][y + 1] == -1) {
                if (grid[x][y + 1] == 0) {
                    minCookies[x][y + 1] = minCookies[x][y];
                    nexts.push_front({x, y + 1});
                } else {
                    minCookies[x][y + 1] = minCookies[x][y] + 1;
                    nexts.push_back({x, y + 1});
                }
            }
        }
    }
    cout << minCookies[N - 1][M - 1];
}
