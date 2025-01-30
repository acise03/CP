#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, M, a, b;
long long K;
int rows[200001];
int first[200001];
int second[200001];

signed main() {
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        first[a]--;
        first[b + 1]++;
    }
    int k = 0;
    for (int i = 1; i <= N; i++) {
        k += first[i];
        second[i] += k;
    }
    if (K == 0) {
        cout << 0 << endl;
        return 0;
    }

    int start = 1;
    int end = 1;

    int mini = INT_MAX;
    int currSUm = M + second[end];
    while (end <= N) {
        if (currSUm >= K) {
            mini = min(mini, end - start + 1);
            start++;
            currSUm -= (M + second[start - 1]);
        } else {
            end++;
            if (end <= N)
                currSUm += (M + second[end]);
        }
    }
    if (mini == INT_MAX) {
        mini = -1;
    }
    cout << mini << endl;
}
