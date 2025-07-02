#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, T;
vector<pair<int, int> > xVals;
vector<pair<int, int> > yVals;

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> T;

    for (int i = 0; i < T; i++) {
        int x, y;
        cin >> x >> y;
        xVals.push_back({x, y});
        yVals.push_back({y, x});
    }
    xVals.push_back({N + 1, 0});
    xVals.push_back({0, N + 1});
    xVals.push_back({0, 0});
    xVals.push_back({N + 1, N + 1});
    yVals.push_back({N + 1, 0});
    yVals.push_back({0, N + 1});
    yVals.push_back({0, 0});
    yVals.push_back({N + 1, N + 1});
    sort(xVals.begin(), xVals.end());
    sort(yVals.begin(), yVals.end());
    int lg = INT_MIN;
    for (int i = 0; i < xVals.size(); i++) {
        for (int j = 0; j < yVals.size(); j++) {
            int x = xVals[i].first;
            int y = yVals[j].first;
            int Xdiff = N - x + 1;
            for (int ii = 0; ii < xVals.size(); ii++) {
                int x2 = xVals[ii].first;
                int y2 = xVals[ii].second;
                if (x == x2 && y == y2) {
                    continue;
                }
                if (abs(y2 - y) <= abs(x2 - x) && x2 > x && y2 > y) {
                    Xdiff = min(Xdiff, x2 - x);
                }
            }
            int Ydiff = N - y + 1;
            for (int ii = 0; ii < yVals.size(); ii++) {
                int y2 = yVals[ii].first;
                int x2 = yVals[ii].second;
                if (x == x2 && y == y2) continue;
                if (abs(y2 - y) >= abs(x2 - x) && x2 > x && y2 > y) {
                    Ydiff = min(Ydiff, y2 - y);
                }
            }
            int v = min(Xdiff - 1, Ydiff - 1);
            if (v > lg)
                lg = v;
        }
    }
    cout << lg << endl;
}
