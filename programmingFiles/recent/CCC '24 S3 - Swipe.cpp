#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
int A[300005];
int B[300005];

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    int aInd = 0;
    int bInd = 0;
    bool pos = true;

    vector<string> lefts;
    vector<string> rights;

    while (bInd < N) {
        if (aInd >= N) {
            pos = false;
            break;
        }
        while (aInd < N && A[aInd] != B[bInd]) {
            aInd++;
        }
        if (A[aInd] == B[bInd]) {
            int bStart = bInd;
            int bEnd = bStart;
            while (bEnd + 1 < N && B[bEnd + 1] == B[bStart])
                bEnd++;
            if (bStart < aInd) {
                lefts.push_back("L " + to_string(bStart) + ' ' + to_string(aInd));
            }
            if (bEnd > aInd) {
                rights.push_back("R " + to_string(aInd) + ' ' + to_string(bEnd));
            }
            aInd++;
            bInd = bEnd + 1;

            // fix order of moves;
        }
    }
    if (pos) {
        cout << "YES" << endl;
        cout << lefts.size() + rights.size() << endl;
        for (string s: lefts) {
            cout << s << endl;
        }
        for (int i = rights.size() - 1; i >= 0; i--) {
            cout << rights[i] << endl;
        }
    } else cout << "NO" << endl;
}
