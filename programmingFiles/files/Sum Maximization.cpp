#include <bits/stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/tle17c4p3
*/

long long Q, N, M;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> Q;

    for (long long i = 0; i < Q; i++)
    {
        cin >> N >> M;
        string currNum = "";
        bool dec = false;
        string mm = to_string(M);
        string nn = to_string(N);

        while (nn.length() < mm.length())
        {
            nn = '0' + nn;
        }
        for (long long j = 0; j < mm.length(); j++)
        {
            if (nn[j] < mm[j] && !dec)
            {
                currNum += (mm[j] - 1);
                for (long long k = j + 1; k < mm.length(); k++)
                {
                    currNum += '9';
                }
                break;
            }
            currNum += (mm[j]);
        }

        long long summ1 = 0;
        long long summ3 = 0;
        for (long long j = 0; j < currNum.length(); j++)
        {
            summ1 += currNum[j] - '0';
            summ3 += mm[j] - '0';
        }

        summ3 = max(summ1, summ3);
        cout << summ3 << endl;
    }
}