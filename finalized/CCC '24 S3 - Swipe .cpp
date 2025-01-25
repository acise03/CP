#include <bits/stdc++.h>
using namespace std;

int N;
int A[300005], B[300005];


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    bool possible = true;
    string output = "";
    int swipeCount = 0;

    for (int ind = 0; ind < N; ind++) {
        if (A[ind] == B[ind]) continue;

        int Find = -1;
        for (int i = ind + 1; i < N; i++) {
            if (A[i] == B[ind]) {
                Find = i;
                break;
            }
        }


        if (Find != -1) {
            swipeCount++;
        } else {
            possible = false;
        }
    }
    if (possible) {
        cout << "YES" << endl;
        cout << swipeCount << endl;
        cout << output << endl;
    }
}
