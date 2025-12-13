#include <bits/stdc++.h>
using namespace std;
int N, M;
map<string, int> fruits;
vector<pair<int, int> > paths;
vector<long double> ratios;
long double d[505];
 
signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        fruits[s] = i;
    }
    for (int i = 0; i < M; i++) {
        string a, b;
        cin >> a >> b;
        long double exchangeRate;
        cin >> exchangeRate;
        paths.push_back({fruits[a], fruits[b]});
        ratios.push_back(exchangeRate);
    }
    d[fruits["APPLES"]] = 1;
    for (int v = 0; v < N; v++) {
        for (int s = 0; s < M; s++) {
            d[paths[s].second] = max(d[paths[s].second], d[paths[s].first] * ratios[s]);
        }
    }
    for (int i = 0; i < M; i++) {
        if (d[paths[i].second] < d[paths[i].first] * ratios[i]) {
            cout << "YA\n";
            return 0;
        }
    }
    cout << "NAW\n";
}