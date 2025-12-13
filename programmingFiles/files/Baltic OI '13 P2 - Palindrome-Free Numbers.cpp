#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod;
string a, b;
int memo[20][2][2][11][11]; // number of numbers that: #digit, mod, tight?

int recurse(int pos, int firstPrev, int secondPrev, bool minTight, bool maxTight, int numDigits) {
    if (pos >= b.length()) {
        return 1;
    }
    if (memo[pos][minTight][maxTight][firstPrev][secondPrev] != -1)
        return memo[pos][minTight][maxTight][firstPrev][secondPrev];
    long long total = 0;
    int maxDigit = 9;
    int minDigit = 0;
    if (maxTight)
        maxDigit = b[pos] - '0';
    if (minTight)
        minDigit = a[pos] - '0';
    for (int i = minDigit; i <= maxDigit; i++) {
        int dig = numDigits;
        if (numDigits > 0) dig++;
        else if (i != 0) dig++;
        if (dig == 0) {
            total += recurse(pos + 1, firstPrev, secondPrev, minTight && i == minDigit, maxTight && i == maxDigit, dig);
        } else if (dig == 0 || (i != firstPrev && i != secondPrev))
            total += recurse(pos + 1, i, firstPrev, minTight && i == minDigit, maxTight && i == maxDigit, dig);
    }
    memo[pos][minTight][maxTight][firstPrev][secondPrev] = total;
    return memo[pos][minTight][maxTight][firstPrev][secondPrev];
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    memset(memo, -1, sizeof(memo));
    cin >> a >> b;
    while (a.length() < b.length())
        a = '0' + a;

    cout << recurse(0, 10, 10, true, true, 0) << endl;
}