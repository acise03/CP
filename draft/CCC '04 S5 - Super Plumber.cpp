#include <bits/stdc++.h>

using namespace std;
int m, n;
int arr[101][101];
int costs[101][101];
bool visitt[101][101];
bool possible[101][101];

void Recurse(int x, int y, string prev)
{ // start: m-1, 0 | end: m-1, n-1
    if (visitt[x][y])
        return;
    if (possible[x][y])
        visitt[x][y] = true;
    else
        return;
    if (x == m - 1 && y == n - 1)
    {
        return;
    }
    if (prev == "right")
    {
        if (y + 1 < n && possible[x][y])
        {
            if (arr[x][y + 1] == '.')
                Recurse(x, y + 1, "right");
            else
                Recurse(x, y + 1, "right");
        }
        if (x < m - 1 && possible[x + 1][y])
        {
            if (arr[x + 1][y] == '.')
                Recurse(x + 1, y, "down");
            else
                Recurse(x + 1, y, "down");
        }
        if (x > 0 && possible[x - 1][y])
        {
            if (arr[x - 1][y] == '.')
                Recurse(x - 1, y, "up");
            else
                Recurse(x - 1, y, "up");
        }
    }
    if (prev == "up")
    {
        if (x > 0 && possible[x - 1][y])
        {
            if (arr[x - 1][y] == '.')
                Recurse(x - 1, y, "up");
            else
                Recurse(x - 1, y, "up");
        }
        if (y < n - 1 && possible[x][y])
        {
            if (arr[x][y + 1] == '.')
                Recurse(x, y + 1, "right");
            else
                Recurse(x, y + 1, "right");
        }
    }
    if (prev == "down")
    {
        if (x < m - 1 && possible[x + 1][y])
        {
            if (arr[x + 1][y] == '.')
                Recurse(x + 1, y, "down");
            else
                Recurse(x + 1, y, "down");
        }
        if (y < n - 1 && possible[x][y])
        {
            if (arr[x][y + 1] == '.')
                Recurse(x, y + 1, "right");
            else
                Recurse(x, y + 1, "right");
        }
    }
}
int main()
{
    cin >> m >> n;
    while (!(m == 0 && n == 0))
    {
        for (int i = 0; i < m; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++)
            {
                char val = s[j];
                possible[i][j] = true;
                visitt[i][j] = false;

                if (val == '.')
                    arr[i][j] = 0;
                else if (val == '*')
                {
                    possible[i][j] = false;
                    arr[i][j] = 0;
                }
                else
                {
                    arr[i][j] = val - '0';
                }
                costs[i][j] = 0;
            }
        }
        Recurse(m - 1, 0, "up");
        if (visitt[m - 1][0])
            costs[m - 1][0] = arr[m - 1][0];
        for (int i = m - 2; i >= 0; i--)
        {
            if (visitt[i][0])
                costs[i][0] = arr[i][0] + costs[i + 1][0];
        }
        for (int j = 1; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                if (visitt[i][j] && visitt[i][j - 1])
                {
                    int v = costs[i][j - 1] + arr[i][j];
                    costs[i][j] = max(v, costs[i][j]);
                    int prev = v;
                    for (int x = i - 1; x >= 0; x--)
                    {
                        if (visitt[x][j])
                        {
                            if (costs[x][j] < prev + arr[x][j])
                                costs[x][j] = prev + arr[x][j];
                            prev = prev + arr[x][j];
                        }
                        else
                            break;
                    }
                    prev = v;
                    for (int x = i + 1; x < m; x++)
                    {
                        if (visitt[x][j])
                        {
                            if (costs[x][j] < prev + arr[x][j])
                                costs[x][j] = prev + arr[x][j];
                            prev = prev + arr[x][j];
                        }
                        else
                            break;
                    }
                }
            }
        }
        cout << costs[m - 1][n - 1] << endl;
        cin >> m >> n;
    }
}