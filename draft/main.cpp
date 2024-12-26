#include <bits/stdc++.h>
using namespace std;
long long K;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> K;
    if (K == 0)
        cout << "1\n1\n";
    else
    {
        long long x = 0;
        long long y = 1000001;
        long long t;
        do
        {
            t = (x * x - x + y * y - y) / 2;
            if (t > K)
                y--;
            else if (t < K)
                x++;
            else
                break;
        } while (x <= y);
        if (t != K || x + y > 1000001)
            cout << "-1\n";
        else
        {
            cout
                << x + y - 1 << "\n";
            int prefix = 0;
            y--;
            bool printedStuff = false;
            if (x > 0)
            {
                cout << 1;
                x--;
                prefix++;
                printedStuff = true;
            }
            while (x > 0)
            {
                cout << "1";
                prefix++;
                if (prefix % 2 == 1)
                    x--;
                else
                    y--;
            }
            if (y > 0)
            {
                if (printedStuff)
                    cout << "0";
                else
                    cout << "0";
                y--;
            }
            while (y > 0)
            {
                cout << "0";
                y--;
            }
            cout << "\n";
        }
    }
}