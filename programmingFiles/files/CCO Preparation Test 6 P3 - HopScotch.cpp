#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, Q;
int values[200005];
int nextChunckSquare[200005];
int blocking[200005];
int blockSize;

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }
    cin >> Q;

    blockSize = llroundl(sqrt(N));

    for (int i = N - 1; i >= 0; i--) {
        int pos = i + values[i];
        int c = 1;
        if (pos < N && pos / blockSize == i / blockSize) {
            c += blocking[pos];
            pos = nextChunckSquare[pos];
        }
        blocking[i] = c;
        nextChunckSquare[i] = pos;
    }
    for (int i = 0; i < Q; i++) {
        int n;
        cin >> n;
        if (n == 1) {
            int x;
            cin >> x;
            int pos = x;
            int c = 0;
            while (pos < N) {
                c += blocking[pos];
                pos = nextChunckSquare[pos];
            }
            cout << c << "\n";
        } else if (n == 2) {
            int x, v;
            cin >> x >> v;
            values[x] = v;
            for (int i = x; i >= floor(x / blockSize) * blockSize; i--) {
                int pos = i + values[i];
                int c = 1;
                if (pos < N && pos / blockSize == i / blockSize) {
                    c += blocking[pos];
                    pos = nextChunckSquare[pos];
                }
                blocking[i] = c;
                nextChunckSquare[i] = pos;
            }
        }
    }
}