#include <bits/stdc++.h>
using namespace std;


int N, L, S, a, b, s;
vector<pair<int, int>> pointVSchangeDSA;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> S;

    for (int i = 0; i < N; i++)
    {
        cin >> a >> b >> s;
        pointVSchangeDSA.push_back({a, s});
        pointVSchangeDSA.push_back({b + 1, -1 * s});
    }
    pointVSchangeDSA.push_back({1, 0});
    pointVSchangeDSA.push_back({L + 1, 0});
    sort(pointVSchangeDSA.begin(), pointVSchangeDSA.end());

    int c = 0;
    int curr = 0;
    for (int i = 1; i < pointVSchangeDSA.size(); i++)
    {
        if (curr < S)
        {
            c += pointVSchangeDSA[i].first - pointVSchangeDSA[i - 1].first;
        }
        curr += pointVSchangeDSA[i].second;
    }
    cout << c << endl;
}