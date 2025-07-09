#include <bits/stdc++.h>
using namespace std;
#define int long long

int needle[26];
int haystack[26];
string N, H;
unordered_set<int> poss1;
unordered_set<int> poss2;
int c;
const int M1 = 1000000009;
const int M2 = 1000000007;
int val1, val2;
int first = 1;
int second = 1;

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> H;
    if (H.length() < N.length()) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < N.size(); i++) {
        needle[N[i] - 'a']++;
        haystack[H[i] - 'a']++;
        val1 *= 26;
        val2 *= 26;
        val1 = val1 % M1;
        val2 = val2 % M2;
        val1 += ((H[i] - 'a')) % M1;
        val2 += ((H[i] - 'a')) % M2;
        val1 = val1 % M1;
        val2 = val2 % M2;

        if (i > 0) {
            first *= 26;
            first = first % M1;
            second *= 26;
            second = second % M2;
        }
    }
    bool pos = true;
    for (int i = 0; i < 26; i++) {
        if (haystack[i] != needle[i]) {
            pos = false;
            break;
        }
    }
    if (pos && (poss1.count(val1) == 0 || poss2.count(val2) == 0)) {
        poss1.insert(val1);
        poss2.insert(val2);
        c++;
    }

    for (int s = N.size(); s < H.size(); s++) {
        haystack[H[s - N.size()] - 'a']--;
        haystack[H[s] - 'a']++;

        val1 = (val1 - ((H[s - N.size()] - 'a') * first) % M1 + M1) % M1;
        val2 = (val2 - ((H[s - N.size()] - 'a') * second) % M2 + M2) % M2;
        val1 *= 26;
        val2 *= 26;
        val1 %= M1;
        val2 %= M2;

        val1 += (H[s] - 'a');
        val2 += (H[s] - 'a');
        val1 %= M1;
        val2 %= M2;

        pos = true;
        for (int i = 0; i < 26; i++) {
            if (haystack[i] != needle[i]) {
                pos = false;
                break;
            }
        }
        if (pos && (poss1.count(val1) == 0 || poss2.count(val2) == 0)) {
            poss1.insert(val1);
            poss2.insert(val2);
            c++;
        }
    }

    cout << c << endl;
}

