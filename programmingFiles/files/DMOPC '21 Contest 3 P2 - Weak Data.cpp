// Not finalized



























#include <bits/stdc++.h>
using namespace std;

long long K;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> K;
    if (K == 0)
    {
        cout << 1 << endl;
        cout << 1 << endl;
    }
    else
    {
        long long a = 0;
        long long b = 100001;
        long long t;
        while (a <= b)
        {
            t = (a * a - a + b * b - b) / 2;
            if (t > K)
            {
                b--;
            }
            else if (t < K)
            {
                a++;
            }
            else
                break;
        }
        if (t != K || a + b > 1000000)
        {
            cout << -1 << endl;
        }
        cout << a+b - 1 << endl;
        int p = 0;
        b--;
       
    }
}