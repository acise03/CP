
#include <bits/stdc++.h>
using namespace std;


long long N, K;
int numCount[1000001];
vector<int> arr;
int diffNumsCount = 0;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    long long countt = 0;
    long long x;
    for (long long i = 0; i < N; i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    diffNumsCount = 0;
    int l = 0;
    int r = 0;

    while (r < N)
    {
        numCount[arr[r]]++;
        if (numCount[arr[r]] == 1)
        {
            diffNumsCount++;
        }
        while (diffNumsCount >= K)
        {
            numCount[arr[l]]--;
            if (numCount[arr[l]] == 0)
                diffNumsCount--;
            l++;
        }
        countt += r - l + 1;
        r++;
    }
    cout << N * (N + 1) / 2 - countt << endl;
}