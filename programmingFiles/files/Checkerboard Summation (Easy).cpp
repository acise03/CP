#include <bits/stdc++.h>
using namespace std;

int M, N, R, C, X, R_1, R_2, C_1, C_2;

int prefixGridWhite[3002][3002];
int prefixGridBlack[3002][3002];
int main()
{
    cin >> M >> N;
    cin >> R >> C >> X;
    while (!(R == 0 && C == 0 && X == 0))
    {
        if (R % 2 == C % 2)
            prefixGridWhite[R][C] = X;
        else
            prefixGridBlack[R][C] = X;
        cin >> R >> C >> X;
    }
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {

            prefixGridWhite[i][j] += prefixGridWhite[i - 1][j] + prefixGridWhite[i][j - 1] - prefixGridWhite[i - 1][j - 1];
            prefixGridBlack[i][j] += prefixGridBlack[i - 1][j] + prefixGridBlack[i][j - 1] - prefixGridBlack[i - 1][j - 1];
        }
    }
    cin >> R_1 >> C_1 >> R_2 >> C_2;

    while (!(R_1 == 0 && C_1 == 0 && R_2 == 0 && C_2 == 0))
    {
        R_1--;
        C_1--;
        int black = prefixGridBlack[R_2][C_2] - prefixGridBlack[R_1][C_2] - prefixGridBlack[R_2][C_1] + prefixGridBlack[R_1][C_1];
        int white = prefixGridWhite[R_2][C_2] - prefixGridWhite[R_1][C_2] - prefixGridWhite[R_2][C_1] + prefixGridWhite[R_1][C_1];
        if (R_1 % 2 == C_1 % 2)
            cout << white - black << endl;
        else
            cout << black - white << endl;
        cin >> R_1 >> C_1 >> R_2 >> C_2;
    }
}