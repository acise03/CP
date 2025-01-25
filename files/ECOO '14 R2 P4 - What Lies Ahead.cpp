#include <bits/stdc++.h>
using namespace std;

char grid[6][6];
bool visited[6][6][4];
pair<int, int> currLoc;
// UP 0, LEFT 1, DOWN 2, RIGHT 3, CLOCKWISE 4, COUNTERCLOCKWISE 5, T 6, S 7


bool clear(int i, int j) {
    return (i >= 0 && i < 6 && j >= 0 && j < 6 && grid[i][j] != '.');
}

void dfs(int i0, int j0, int dir);

void move(char c, int i, int j, int dir) {
    if (c == 'U') {
        dfs(i - 1, j, dir);
    } else if (c == 'D') {
        dfs(i + 1, j, dir);
    } else if (c == 'L') {
        dfs(i, j - 1, dir);
    } else if (c == 'R') {
        dfs(i, j + 1, dir);
    } else if (c == 'C') {
        dfs(i, j, (dir + 1) % 4);
    } else if (c == 'B') {
        dfs(i, j, (dir + 3) % 4);
    }
}


void dfs(int i0, int j0, int dir) {
    if (!clear(i0, j0) || visited[i0][j0][dir])
        return;
    visited[i0][j0][dir] = true;
    if (grid[i0][j0] == 'T')
        return;

    int i = i0, j = j0;


    if (grid[i][j] == 'S') {
        if (dir == 0) {
            i--;
            while (clear(i, j)) {
                if (grid[i][j] == 'U') {
                    move(grid[i][j], i0, j0, dir);
                }
                i--;
            }
        }
    } else {
        if (dir == 0)
            i--;
        else if (dir == 1)
            j++;
        else if (dir == 2)
            i++;
        else if (dir == 3)
            j--;
        while (clear(i, j)) {
            move(grid[i][j], i0, j0, dir);
            if (dir == 0)
                i--;
            else if (dir == 1)
                j++;
            else if (dir == 2)
                i++;
            else if (dir == 3)
                j--;
        }
    }
}

int S;

int main() {
    for (int t = 0; t < 10; t++) {
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < 6; i++) {
            scanf("%s", grid[i]);
        }

        for (int i = 0; i < 6; i++) {
            if (grid[5][i] == 'S') {
                S = i;
                break;
            }
        }
        dfs(5, S, 0);
        for (int x = 0; x < 6; x++) {
            for (int y = 0; y < 6; y++) {
                if (grid[x][y] == 'T') {
                    bool found = false;

                    for (int k = 0; k < 4 && !found; k++) {
                        if (visited[x][y][k]) {
                            found = true;
                        }
                    }
                    if (found) cout << "T";
                    else cout << "F";
                }
            }
        }
        cout << endl;
    }
}
