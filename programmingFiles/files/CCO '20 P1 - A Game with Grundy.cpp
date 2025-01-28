#include <bits/stdc++.h>
using namespace std;


long long N, L, R, Y, x, v, h;
vector<pair<long long, long long>> dsa;
map<long long, long long> viewwersVScountPSA;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R >> Y;
    for (long long i = 0; i < N; i++)
    {
        cin >> x >> v >> h;
        double y_11 = (double)(Y * h + (v)*x) / v;
        double y_22 = (double)(Y * h - (v)*x) / -v;
        if (y_22 < y_11)
        {
            swap(y_22, y_11);
        }
        long long y1 = (long long)(floor(y_11)) + 1; // non inclusive
        long long y2 = (long long)(ceil(y_22));      // non inclusive
        if (y1 >= L)
            dsa.push_back({y1, 1});
        else
            dsa.push_back({L, 1});
        if (y2 >= L && y2 <= R)
            dsa.push_back({y2, -1});
        else
            dsa.push_back({R + 1, -1});
    }
    dsa.push_back({L, 0});
    dsa.push_back({R + 1, 0});

    sort(dsa.begin(), dsa.end());

    long long cc = 0;
    for (long long i = 0; i < dsa.size() - 1; i++)
    {
        viewwersVScountPSA[cc] += -dsa[i].first + dsa[i + 1].first;
        cc += dsa[i + 1].second;
    }
    cout << viewwersVScountPSA[0] << endl;
    for (long long i = 1; i <= N; i++)
    {
        viewwersVScountPSA[i] += viewwersVScountPSA[i - 1];
        cout << viewwersVScountPSA[i] << endl;
    }
}