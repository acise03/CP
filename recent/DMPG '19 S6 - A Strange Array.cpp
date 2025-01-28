#include <bits/stdc++.h>
using namespace std;

int N, Q, l, r, x;
int numbersList[1000005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    int s = 0;
    for (int i = 1; i <= N; i++) {
        int xk;
        cin >> xk;
        numbersList[i] = numbersList[i - 1] + xk;
    }
    for (int i = 0; i < Q; i++) {
        cin >> l >> r >> x;
        int summ = numbersList[r] - numbersList[l - 1];
        if (summ % 2 == x % 2 && summ <= x) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
