#include <bits/stdc++.h>
using namespace std;
#define int long long


int BIT[10005];
int C;

int query(int pos) {
    int sum = 0;
    while (pos > 0) {
        sum += BIT[pos];
        pos -= pos & -pos;
    }
    return sum;
}

void update(int pos, int val) {
    while (pos <= 10000) {
        BIT[pos] += val;
        pos += pos & -pos;
    }
}

unordered_map<string, int> rocks;


signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> C;
    int rockCount = 1;

    for (int i = 0; i < C; i++) {
        char k;
        cin >> k;
        if (k == 'A') {
            string R;
            cin >> R;
            if (rocks.count(R) > 0) {
                cout << "Can't add " << R << endl;
            } else {
                rocks[R] = rockCount;
                int mass = 0;
                for (int letter = 0; letter < R.length(); letter++) {
                    mass += R[letter] - 'a' + 1;
                }
                update(rockCount, mass);
                rockCount++;
            }
        } else if (k == 'S') {
            string X, Y;
            cin >> X >> Y;
            int Xmass = 0;
            for (int letter = 0; letter < X.length(); letter++) {
                Xmass += X[letter] - 'a' + 1;
            }
            int Ymass = 0;
            for (int letter = 0; letter < Y.length(); letter++) {
                Ymass += Y[letter] - 'a' + 1;
            }
            update(rocks[X], Ymass - Xmass);
            update(rocks[Y], Xmass - Ymass);
            int temp = rocks[X];
            rocks[X] = rocks[Y];
            rocks[Y] = temp;
        } else if (k == 'M') {
            string X, Y;
            cin >> X >> Y;
            if (rocks[X] > rocks[Y]) {
                swap(X, Y);
            }
            cout << query(rocks[Y]) - query(rocks[X] - 1) << endl;
        } else if (k == 'R') {
            string X, Y;
            cin >> X >> Y;
            int Xmass = 0;
            for (int letter = 0; letter < X.length(); letter++) {
                Xmass += X[letter] - 'a' + 1;
            }
            int Ymass = 0;
            for (int letter = 0; letter < Y.length(); letter++) {
                Ymass += Y[letter] - 'a' + 1;
            }
            update(rocks[X], Ymass - Xmass);
            rocks[Y] = rocks[X];
            rocks.erase(X);
        } else if (k == 'N') {
            cout << rockCount - 1 << endl;
        }
    }
}