#include <bits/stdc++.h>
using namespace std;


int C, D, E;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> C >> D >> E;

    int cc = 1;

    if (D & E)
        cout << 0;
    else
    {
        for (int i = 30; i >= 0; i--)
        {
            int c_dig = (C >> i) & 1;
            int d_dig = (D >> i) & 1;
            int e_dig = (E >> i) & 1;
            if (d_dig == 1)
                continue;

            if (c_dig == 0)
                continue;

            if (e_dig == 0)
                continue;
            else
                cc = cc * 2;
        }
        cout << cc << endl;
    }
}