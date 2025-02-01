#include <bits/stdc++.h>
using namespace std;

int T, m;

int factorial(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

int choose(int a, int b) {
    return (factorial(a) / factorial(b) / factorial(a - b));
}


int main() {
    cin >> T;

    for (int _ = 0; _ < T; _++) {
        cin >> m;
        int possibles = 0;
        string out = "";

        for (int k = 1; (choose(2 * (k), k) <= m); k++) {
            int lo = 2*k-1;
            int hi = 10000000000000000;
            int res = -1;

            while (lo <= hi) {
                int mid = (hi + lo) / 2;
                int v = choose(mid, k);
                if (v == m) {
                    res = mid;
                    break;
                } else if (v > hi) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            if (res != -1) {
                out += "(" + to_string(res) + "," + to_string(k) + ")\n";
                if (2 * k != res) {
                    out += "(" + to_string(res) + "," + to_string(res - k) + ")\n";
                }
                possibles++;
            }
        }
        cout << possibles << endl;
        cout << out;
    }
}
