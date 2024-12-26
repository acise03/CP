// AC
#include <bits/stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/dmopc14c5p4
*/
long long N, M;
long long S, P;
vector<long long> ones;
vector<long long> twos;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    vector<pair<long long, long long>> arr;
    for (long long i = 0; i < N; i++)
    {
        cin >> S >> P;
        if (P == 1)
            ones.push_back(S);
        else
            twos.push_back(S);
    }
    sort(ones.begin(), ones.end());
    sort(twos.begin(), twos.end());

    long long ind1 = 0;
    long long ind2 = 0;
    long long tot = 0;
    while (ind1 < ones.size() || ind2 < twos.size())
    {
        if (ind1 < ones.size() && ind2 < twos.size())
        {
            if (2 * ones[ind1] < twos[ind2] && M >= ones[ind1])
            {
                M -= ones[ind1];
                tot++;
                ind1++;
            }
            else if (M >= twos[ind2])
            {
                M -= twos[ind2];
                tot += 2;
                ind2++;
            }
            else if (M >= ones[ind1])
            {
                M -= ones[ind1];
                tot++;
                ind1++;
            }
            else
                break;
        }
        else if (ind1 >= ones.size() && M >= twos[ind2])
        {
            M -= twos[ind2];
            tot += 2;
            ind2++;
        }
        else if (ind2 >= twos.size() && M >= ones[ind1])
        {
            M -= ones[ind1];
            tot++;
            ind1++;
        }
        else
        {
            break;
        }
    }
    cout << tot << endl;
}