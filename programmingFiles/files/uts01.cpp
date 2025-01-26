#include <bits/stdc++.h>
using namespace std;

long long N, K;

string s;

int rec(string s) {
    int c = 0;
    if (s[0] != '0') {
        if (s[1] == '0') {
            s[0] = '0';
            c++;
        }
    }
    if (s[s.length() - 1] != '0') {
        if (s[s.length() - 2] == '0') {
            s[s.length() - 1] = '0';
            c++;
        }
    }
    if (s[0] && s[s.length() - 1] == '0') {
        int loc1 = 0;
        while (loc1 < s.length()) {
            if (s[loc1] == '0') {
                loc1++;
            } else {
                loc1--;
                int loc2 = loc1 + 1;
                while (s[loc2] == '1') {
                    loc2++;
                }
                if ((loc2 - loc1) % 2 == '1') {
                    return -1;
                } else {
                    c += (loc2 - loc1 - 1) * 2 - 1;
                    loc1 = loc2;
                }
            }
        }
        return c;
    } else return -1;
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    cin >> s;
    cout << rec(s) << endl;
}
