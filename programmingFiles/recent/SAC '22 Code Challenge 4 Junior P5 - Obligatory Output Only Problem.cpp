#include <bits/stdc++.h>
using namespace std;

int N, M;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    N = 100000;
    M = 2 * 100000;

    int c = 1;

    cout << N << " " << M << endl;
    while (M > 0) {
        int multiplier = floor(c / N);
        if (c > N * multiplier + multiplier) {
            cout << multiplier + 1 << " " << c - N * multiplier + 1 << " " << c << endl;
            M--;
        }

        c++;
    }
}
