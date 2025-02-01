#include <bits/stdc++.h>
using namespace std;
#define int long long
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


signed main() {
    cin >> T;

    for (int _ = 0; _ < T; _++) {
        cin >> m;
        int possibles = 0;
        string out = "";

        for (int k = 1; (choose(2 * (k), k) <= m); k++) {
            int lo = 2 * k - 1;
            int hi = 10;

            while (lo < hi) {
                int mid = lo + (hi - lo + 1) / 2;
                int v = choose(mid, k);
                if (v >= hi) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            if (choose(lo, k) == m) {
                out += "(" + to_string(lo) + "," + to_string(k) + ")\n";
                if (2 * k != lo) {
                    out += "(" + to_string(lo) + "," + to_string(lo - k) + ")\n";
                }
                possibles++;
            }
        }
        cout << possibles << endl;
        cout << out;
    }
}
