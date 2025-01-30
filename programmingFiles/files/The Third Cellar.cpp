#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, l, r;
bool primes[1000001];
int prefixArr[1000005];

signed main() {
    memset(primes, true, sizeof(primes));
    primes[0] = false;
    primes[1] = false;
    cin >> N;

    for (int i = 2; i < 1000001; i++) {
        if (primes[i]) {
            for (int j = 2 * i; j < 1000001; j += i) {
                primes[j] = false;
            }
        }
    }
    for (int i = 1; i < 1000001; i++) {
        prefixArr[i] = prefixArr[i - 1] + primes[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> l >> r;
        cout << prefixArr[r - 1] - prefixArr[l - 1] << endl;
    }
}
