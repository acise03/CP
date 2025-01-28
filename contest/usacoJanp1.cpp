#include <bits/stdc++.h>
using namespace std;

int N, T, A, B;
int superImposed[1001][1001];
int firstPic[1001][1001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for (int testcase = 0; testcase < T; testcase++) {
        cin >> N >> A >> B;

        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < N; j++) {
                if (s[j] == 'W')
                    superImposed[i][j] = 0;
                else if (s[j] == 'G') superImposed[i][j] = 1;
                else superImposed[i][j] = 2;
                firstPic[i][j] = 0;
            }
        }

        int c = 0;
        for (int i = N - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                if (superImposed[i][j] > firstPic[i][j]) {
                    c++;
                    firstPic[i][j]++;

                    if (i - B >= 0 && j - A >= 0 && superImposed[i - B][j - A] > firstPic[i - B][j - A]) {
                        firstPic[i - B][j - A]++;
                        if (superImposed[i][j] > firstPic[i][j]) {
                            c++;
                            firstPic[i][j]++;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (firstPic[i][j] != superImposed[i][j]) {
                    c = -1;
                }
            }
        }
        cout << c << endl;
    }
}
