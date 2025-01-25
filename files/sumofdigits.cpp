#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        int m, a;
        cin >> m >> a;
        int value = m*a;
        cout << value;
    }
    else if (n == 2)
    {
        int d, t;
        cin >> d >> t;
        int value = d/t;
        cout << value;
    }
}