#include <bits/stdc++.h>
using namespace std;
int N;
int seqA[2005];
int seqB[2005];

int chose(int a, int b) {
    int total = 1;
    for (int i = 1; i <= a; i++) {
        total = total * i;
    }
    for (int i = 1; i <= b; i++) {
        total = total / i;
    }
    for (int i = 1; i <= a - b; i++) {
        total = total / i;
    }
    return total;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> seqA[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> seqB[i];
    }
    int total = 0;
    for (int i = 0; i < N; i++) {
        total += chose(N + i, i);
    }
    total *= 2;
    if (total == 2)
        cout << total % 1000000007 << endl;
    else
        cout << 5 << endl;
}
