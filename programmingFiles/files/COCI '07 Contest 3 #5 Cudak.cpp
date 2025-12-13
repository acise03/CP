#include<bits/stdc++.h>
using namespace std;
#define int long long
int S;
string A, B;
pair<string, int> memo[20][140][2][2]; // number of numbers that: #digit, mod, tight?

pair<string, int> recurse(int pos, int val, bool minTight, bool maxTight) {
    if (pos == B.size()) {
        return {"", val == 0};
    }
    if (memo[pos][val][minTight][maxTight].second != -1)
        return memo[pos][val][minTight][maxTight];
    long long total = 0;
    int maxDigit = 9;
    int minDigit = 0;
    if (maxTight)
        maxDigit = B[pos] - '0';
    if (minTight)
        minDigit = A[pos] - '0';
    string mini = "-1";
    for (int i = minDigit; i <= maxDigit; i++) {
        if (i <= val) {
            auto x = recurse(pos + 1, val - i, minTight && i == minDigit, maxTight && i == maxDigit);
            total += x.second;
            if (x.second > 0 && mini == "-1") {
                mini = to_string(i) + x.first;
            }
        }
    }
    memo[pos][val][minTight][maxTight] = make_pair(mini, total);
    return memo[pos][val][minTight][maxTight];
}


signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i <= 16; i++)
        for (int j = 0; j < 140; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    memo[i][j][k][l] = {"", -1};
    cin >> A >> B >> S;
    while (A.length() < B.length())
        A = '0' + A;
    auto res = recurse(0, S, true, true);
    string outX = res.first;
    while (outX[0]=='0') {
        outX=outX.substr(1);
    }
    cout << res.second << endl << outX << endl;
}