#include <bits/stdc++.h>
using namespace std;

int n, x, y;
//         cout << " " << Xm1 << " " << Ym1 << " " << Xm1 << " " << Ym2 << " " << Xm2 << " " << Ym1 << " " << Xm2 << " " << Ym2 << endl;
/*
Recurse(x1, y1, Xm1, Ym1);
Recurse(Xm1, y1, x2, Ym1);
Recurse(x1, Ym1, Xm1, y2);
Recurse(Xm1, Ym1, x2, y2);
        */
void Recurse(int x1, int y1, int x2, int y2, int X, int Y) // all inclusive
{
    if (x2 - x1 == 1)
    {
        string s = "";
        if (!(X == x1 && Y == y1))
        {
            s += to_string(x1) + " " + to_string(y1) + " ";
        }
        if (!(X == x2 && Y == y1))
        {
            s += to_string(x2) + " " + to_string(y1) + " ";
        }
        if (!(X == x2 && Y == y2))
        {
            s += to_string(x2) + " " + to_string(y2) + " ";
        }
        if (!(X == x1 && Y == y2))
        {
            s += to_string(x1) + " " + to_string(y2) + " ";
        }
        cout << s.substr(0, s.length() - 1) << endl;
        return;
    }
    int Xm1 = (x1 + x2 - 1) / 2;
    int Xm2 = (x1 + x2 + 1) / 2;
    int Ym1 = (y1 + y2 - 1) / 2;
    int Ym2 = (y1 + y2 + 1) / 2;

    if (X < Xm2 && Y < Ym2)
    {
        cout << Xm1 << " " << Ym2 << " " << Xm2 << " " << Ym1 << " " << Xm2 << " " << Ym2 << endl;
        Recurse(x1, y1, Xm1, Ym1, X, Y);
        Recurse(Xm2, y1, x2, Ym1, Xm2, Ym1);
        Recurse(x1, Ym2, Xm1, y2, Xm1, Ym2);
        Recurse(Xm2, Ym2, x2, y2, Xm2, Ym2);
    }
    else if (X < Xm2 && Y > Ym1)
    {
        cout << Xm1 << " " << Ym1 << " " << Xm2 << " " << Ym1 << " " << Xm2 << " " << Ym2 << endl;
        Recurse(x1, y1, Xm1, Ym1, Xm1, Ym1);
        Recurse(Xm2, y1, x2, Ym1, Xm2, Ym1);
        Recurse(x1, Ym2, Xm1, y2, X, Y);
        Recurse(Xm2, Ym2, x2, y2, Xm2, Ym2);
    }
    else if (X > Xm1 && Y < Ym2)
    {

        cout << Xm1 << " " << Ym1 << " " << Xm1 << " " << Ym2 << " " << Xm2 << " " << Ym2 << endl;
        Recurse(x1, y1, Xm1, Ym1, Xm1, Ym1);
        Recurse(Xm2, y1, x2, Ym1, X, Y);
        Recurse(x1, Ym2, Xm1, y2, Xm1, Ym2);
        Recurse(Xm2, Ym2, x2, y2, Xm2, Ym2);
    }
    else if (X > Xm1 && Y > Ym1)
    {

        cout << Xm1 << " " << Ym1 << " " << Xm1 << " " << Ym2 << " " << Xm2 << " " << Ym1 << endl;
        Recurse(x1, y1, Xm1, Ym1, Xm1, Ym1);
        Recurse(Xm2, y1, x2, Ym1, Xm2, Ym1);
        Recurse(x1, Ym2, Xm1, y2, Xm1, Ym2);
        Recurse(Xm2, Ym2, x2, y2, X, Y);
    }
}

int main()
{
    cin >> n >> x >> y;
    Recurse(0, 0, pow(2, n) - 1, pow(2, n) - 1, x, y);
}