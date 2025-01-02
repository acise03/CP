#include <bits/stdc++.h>
using namespace std;
int N;
bool visited[3][3];
int totall;
bool checkPossibleTravel(int x1, int y1, int x2, int y2)
{
    if (!visited[x2][y2] && !(x1 == x2 && y1 == y2))
    {
        if ((abs(x1 - x2) == 2 && abs(y1 - y2) == 2) || (abs(x1 - x2) == 0 && abs(y1 - y2) == 2) || (abs(x1 - x2) == 2 && abs(y1 - y2) == 0))
        {
            if (visited[(x1 + x2) / 2][(y1 + y2) / 2])
                return true;
            return false;
        }
        else
            return true;
    }
    return false;
}
int Rec(int x, int y, int stepsLeft)
{
    if (stepsLeft == 0)
        return 1;
    int currCount = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (!(i == x && j == y) && checkPossibleTravel(x, y, i, j))
            {
                visited[i][j] = true;
                currCount += Rec(i, j, stepsLeft - 1);
                visited[i][j] = false;
            }
        }
    }
    return currCount;
}
int main()
{
    for (int tcc = 0; tcc < 5; tcc++)
    {
        int m;
        cin >> m;
        totall = 0;

        for (int cc = 1; cc <= m; cc++)
        {
            N = cc;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    visited[i][j] = true;
                    totall += Rec(i, j, N);
                    visited[i][j] = false;
                }
            }
        }
        cout << totall << endl;
    }
}