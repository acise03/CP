#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, K, a, b, d, ss, start, endd;

vector<pair<int, int> > nextHills[200005];
int nextHillsPeople[200005];
vector<int> pandas;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

void rec(int breakpoint, int intervalS, int intervalE, int beforeBreakpoint) {
    // inc, inc.
    if (intervalE < intervalS) return;

    nextHillsPeople[breakpoint] = upper_bound(pandas.begin(), pandas.end(), intervalE) - lower_bound(
        pandas.begin(), pandas.end(), intervalS);


    auto n = nextHills[breakpoint].begin();
    while (n != nextHills[breakpoint].end()) {
        if (n->second == beforeBreakpoint) {
            nextHills[breakpoint].erase(n);

            break;
        }
        n++;
    }


    int left, right;
    for (int ind = 0; ind < nextHills[breakpoint].size(); ind++) {
        if (ind == 0) left = 1;
        else
            left = nextHills[breakpoint][ind].first - (
            nextHills[breakpoint][ind].first - nextHills[breakpoint][ind - 1].first) / 2;
        if (ind == nextHills[breakpoint].size() - 1) {
            right = 10e9;
        } else {
            right = (nextHills[breakpoint][ind].first + nextHills[breakpoint][ind + 1].first) / 2;
        }
        rec(nextHills[breakpoint][ind].second, max(intervalS, left), min(intervalE, right), breakpoint);
    }
    // insert n back into nextHills[breakpoint] ?
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i < N; i++) {
        cin >> a >> b >> d;
        nextHills[a].emplace_back(d, b);
    }
    nextHills[1].emplace_back(1, -1);

    for (int i = 1; i <= N; i++) {
        sort(nextHills[i].begin(), nextHills[i].end(), cmp);
    }
    for (int i = 0; i < K; i++) {
        cin >> ss;
        pandas.push_back(ss);
    }
  		  sort(pandas.begin(), pandas.end());

    rec(1, 1, 1000000000, -1);


    for (int i = 1; i < N; i++) {
        cout << nextHillsPeople[i] << " ";
    }
    cout << nextHillsPeople[N] << endl;
}
