#include <bits/stdc++.h>
using namespace std;

int H, k;
int houses[1005];
vector<int> linear;
vector<pair<int, int> > rangess;

int findK(int l) {
    int mini = INT_MAX;
    for (int startInd = 0; startInd < H; startInd++) {
        int checkPoint = startInd;
        int ind = startInd + 1;
        ind %= H;
        int kVal = 1;
        while (ind != startInd) {
            int d = houses[ind];
            if (ind < startInd) {
                d += 1000000;
            }
            if (d - houses[checkPoint] > l) {
                kVal++;
                checkPoint = ind;
            }
            ind++;
            ind %= H;
        }
        mini = min(mini, kVal);
    }
    return mini;
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> H;
    for (int i = 0; i < H; i++) {
        cin >> houses[i];
    }
    cin >> k;
    sort(houses, houses + H);
    int l = 0;
    int h = 5000000;
    while (l < h) {
        int m = (l + h) / 2;
        int x = findK(m);
        if (x > k) {
            l = m + 1;
        } else {
            h = m;
        }
    }
    cout << ceil((float) (h) / 2) << endl;
}