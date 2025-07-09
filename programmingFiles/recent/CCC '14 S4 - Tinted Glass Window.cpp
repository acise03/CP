#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, T, xl, yt, xr, yb, ti;
vector<tuple<int, int, int, int> > valids;
int grid[2005];
vector<int> coordCompress;
int tot;
vector<tuple<int, int, int, int, int> > input;

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> xl >> yt >> xr >> yb >> ti;
        input.push_back({xl, yt, xr, yb, ti});
        coordCompress.push_back(yt);
        coordCompress.push_back(yb);
    }
    coordCompress.push_back(0);
    sort(coordCompress.begin(), coordCompress.end());
    auto u = unique(coordCompress.begin(), coordCompress.end());
    coordCompress.erase(u, coordCompress.end());

    for (int i = 0; i < N; i++) {
        xl = get<0>(input[i]);
        yt = get<1>(input[i]);
        xr = get<2>(input[i]);
        yb = get<3>(input[i]);
        ti = get<4>(input[i]);
        yt = find(coordCompress.begin(), coordCompress.end(), yt) - coordCompress.begin();
        yb = find(coordCompress.begin(), coordCompress.end(), yb) - coordCompress.begin();
        valids.push_back({xl, ti, yt, yb});
        valids.push_back({xr, -ti, yt, yb});
    }

    sort(valids.begin(), valids.end());
    int prevLoc = 0;
    int countt = 0;
    for (int i = 0; i < valids.size(); i++) {
        int x = get<0>(valids[i]);
        tot += (x - prevLoc) * countt;
        int val = get<1>(valids[i]);
        int yStart = get<2>(valids[i]);
        int yEnd = get<3>(valids[i]);
        for (int y = yStart; y < yEnd; y++) {
            if (grid[y] >= T) {
                countt -= coordCompress[y + 1] - coordCompress[y];
            }
            grid[y] += val;
            if (grid[y] >= T) {
                countt += coordCompress[y + 1] - coordCompress[y];
            }
        }
        prevLoc = x;
    }
    cout << tot << endl;
}
