#include <bits/stdc++.h>
using namespace std;
#define int long long

int needle[26];
int haystack[26];
string N, H;
unordered_set<int> poss;

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> H;
    if (H.length() < N.length()) {
        cout << 0 << endl;
        return 0;
    }
    int val = 0;

    for (int i = 0; i < N.size(); i++) {
        needle[N[i] - 'a']++;
        haystack[H[i] - 'a']++;
        val += static_cast<long long>((H[i] - 'a') * powl(26, (i + 1))) % 1000000009LL;
    }
    bool pos = true;
    for (int i = 0; i < 26; i++) {
        if (haystack[i] != needle[i]) {
            pos = false;
            break;
        }
    }
    if (pos) {
        poss.insert(val);
    }
    for (int s = N.size(); s < H.size(); s++) {
        haystack[H[s - N.size()] - 'a']--;
        haystack[H[s] - 'a']++;
        val -= static_cast<long long>((H[s - N.size()] - 'a') * powl(26, (1LL))) % 1000000009LL;
        val /= 26;
        val %= 1000000009LL;
        val += static_cast<long long>((H[s] - 'a') * powl(26, (N.size()))) % 1000000009LL;
        val %= 1000000009LL;

        pos = true;
        for (int i = 0; i < 26; i++) {
            if (haystack[i] != needle[i]) {
                pos = false;
                break;
            }
        }
        if (pos) {
            poss.insert(val);
        }
    } 

    cout << poss.size() << endl;
}
