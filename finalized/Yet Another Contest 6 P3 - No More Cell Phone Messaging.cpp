#include <bits/stdc++.h>
using namespace std;
int N, M;
int d1, d2, d3, d4, d;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    cout << "? " << 1 << " " << 1 << endl;
    cout << flush;
    cin >> d1;

    cout << "? " << N << " " << 1 << endl;
    cout << flush;
    cin >> d2;

    cout << "? " << N << " " << M << endl;
    cout << flush;
    cin >> d3;

    cout << "? " << 1 << " " << M << endl;
    cout << flush;

    cin >> d4;

    pair<int, int> p1 = {abs((d1 - d2 + N + 1) / (2)), abs(-1 * abs((d1 - d2 + N + 1) / (2)) + d1 + 2)};
    pair<int, int> p2 = {abs((M + 2 * N - d3 - d2 - 1) / (2)), abs(abs((M + 2 * N - d3 - d2 - 1) / (2)) + d2 - N + 1)};
    pair<int, int> p3 = {abs((N + 1 - d3 + d4) / (2)), abs(-1 * abs((N + 1 - d3 + d4) / (2)) + M + N - d3)};
    pair<int, int> p4 = {abs((d1 + 3 - M + d4) / (2)), abs(abs((d1 + 3 - M + d4) / (2)) + M - 1 - d4)};

    if (((d1 - d2 + N + 1) % 2 != 0) || ((N + 1 - d3 + d4) % 2 != 0) || p1.first < 1 || p1.second < 1 || p3.first < 1 || p3.second < 1 || p1.first > N || p3.first > N || p1.second > M || p3.second > M)
        cout << "! " << p2.first << " " << p2.second << " " << p4.first << " " << p4.second << endl;
    else if (((M + 2 * N - d3 - d2 - 1) % 2 != 0) || ((d1 + 3 - M + d4) % 2 != 0) || p2.first < 1 || p2.second < 1 || p4.first < 1 || p4.second < 1 || p2.first > N || p4.first > N || p2.second > M || p3.second > M)
        cout << "! " << p1.first << " " << p1.second << " " << p3.first << " " << p3.second << endl;
    else
    {
        cout << "? " << p1.first << " " << p1.second << endl;
        cout << flush;
        cin >> d;
        if (d == 0)
        {
            cout << "! " << p1.first << " " << p1.second << " " << p3.first << " " << p3.second << endl;
        }
        else
        {
            cout << "! " << p2.first << " " << p2.second << " " << p4.first << " " << p4.second << endl;
        }
    }
    cout << flush;
}