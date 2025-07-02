#include <bits/stdc++.h>
using namespace std;
#define int long long

int N;
string S;

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        int c = 2;
        int l = S.length() - 1;
        while (l > 0) {
            int st = S.length() - l;
            while (st >= 0) {
                if (S.find(S.substr(st, l)) == st) {
                    c++;
                }
                st--;
            }
            st = S.length() - l;
            while (st >= 0) {
                if (S.find(S.substr(st, l)) == st) {
                    st--;
                } else {
                    S = S.substr(0, st + l);
                    st = S.length() - l - 1;
                }
            }
            l--;
        }
        cout << c << endl;
    }
}
