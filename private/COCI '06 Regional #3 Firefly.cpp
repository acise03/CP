// AC
#include <bits\stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/crci06p3
*/
int N, H;
vector<int> bottoms;
vector<int> tops;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> H;
    int mini;
    for (int i = 0; i < N; i++)
    {
        int sizes;
        cin >> sizes;
        if (i % 2 == 0)
        {
            tops.push_back(sizes);
        }
        else
        {
            bottoms.push_back(sizes);
        }
    }
    mini = INT_MAX;
    sort(tops.begin(), tops.end());
    sort(bottoms.begin(), bottoms.end());
    int countt = 0;
    for (int i = 1; i <= H; i++)
    {
        int k;
        k = upper_bound(tops.begin(), tops.end(), H - i) - tops.begin();
        int val1 = tops.size() - k;
        int val2 = bottoms.size() - ((lower_bound(bottoms.begin(), bottoms.end(), i) - bottoms.begin()));
        int tot = val1 + val2;
        if (tot == mini)
        {
            countt++;
        }
        else if (tot < mini)
        {
            countt = 1;
            mini = tot;
        }
    }
    cout << mini << " " << countt << endl;
}