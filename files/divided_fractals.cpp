#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<bool>> grid;
void print()
{
    for (int i = 0; i < int(pow(3, n)); i++)
    {
        for (int j = 0; j < int(pow(3, n)); j++)
        {
            if (!grid[i][j])
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void Recurse(int Xstart, int Xend, int Ystart, int Yend)
{

    for (int i = (2 * Xstart + Xend) / 3; i < (2 * Xend + Xstart) / 3; i++)
    {
        for (int j = (2 * Ystart + Yend) / 3; j < (2 * Yend + Ystart) / 3; j++)
        {
            grid[i][j] = false;
        }
    }
    //    print();

    if (Xend - Xstart > 3 && Yend - Ystart > 3)
    {

        Recurse(Xstart, (2 * Xstart + Xend) / 3, Ystart, (2 * Ystart + Yend) / 3);
        Recurse(Xstart, (2 * Xstart + Xend) / 3, (2 * Ystart + Yend) / 3, (2 * Yend + Ystart) / 3);
        Recurse(Xstart, (2 * Xstart + Xend) / 3, (2 * Yend + Ystart) / 3, Yend);
        Recurse((2 * Xstart + Xend) / 3, (2 * Xend + Xstart) / 3, Ystart, (2 * Ystart + Yend) / 3);
        Recurse((2 * Xstart + Xend) / 3, (2 * Xend + Xstart) / 3, (2 * Yend + Ystart) / 3, Yend);
        Recurse((2 * Xend + Xstart) / 3, Xend, Ystart, (2 * Ystart + Yend) / 3);
        Recurse((2 * Xend + Xstart) / 3, Xend, (2 * Ystart + Yend) / 3, (2 * Yend + Ystart) / 3);
        Recurse((2 * Xend + Xstart) / 3, Xend, (2 * Yend + Ystart) / 3, Yend);
    }
}
int main()
{
    int d, b, t, l, r;

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> d;
    for (int i = 0; i < d; i++)
    {
        cin >> n >> b >> t >> l >> r;
        int size = pow(3, n);
        grid.resize(size, vector<bool>(size, true));

        Recurse(0, pow(3, n), 0, pow(3, n));
        for (int i = t - 1; i >= b-1; i--)
        {
            for (int j = l - 1; j < r-1; j++)
            {
                if (grid[i][j])
                    cout << "*";
                else
                    cout << " ";
                cout << " ";
            }
            if (grid[i][r - 1])
                cout << "*";
            else
                cout << " ";
            cout << endl;
        }
    }
}