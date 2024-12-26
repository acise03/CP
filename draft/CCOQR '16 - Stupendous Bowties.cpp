#include <bits/stdc++.h>

using namespace std;
map<long long, vector<long long>> oneList;
map<long long, vector<long long>> twoList;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long N;
    cin >> N;

    for (long long i = 0; i < N; i++)
    {
        long long x_i, y_i;
        cin >> x_i >> y_i;
        oneList[x_i].push_back(y_i);
        twoList[y_i].push_back(x_i);
    }

    for (auto i = oneList.begin(); i != oneList.end(); i++)
        sort(i->second.begin(), i->second.end());

    for (auto i = twoList.begin(); i != twoList.end(); i++)
        sort(i->second.begin(), i->second.end());

    long long countt = 0;
    auto i = oneList.begin();
    i++;
    while ((next(i, 1)) != (oneList.end()))
    {
        if (i->second.size() >= 3)
        {
            for (long long j = 1; j <= (long long)i->second.size() - 2; j++)
            {
                if (twoList[i->second[j]].size() >= 3)
                {
                    auto x = i->first;
                    auto y = i->second[j];

                    auto theArray = twoList[y];
                    long long one = (j * ((long long)i->second.size() - j - 1));
                    long long twoone = (lower_bound((theArray.begin()), (theArray.end()), x) - theArray.begin());
                    long long twotwo = (theArray.size() - (upper_bound((theArray.begin()), (theArray.end()), x) - theArray.begin()));
                    countt += 2 * one * twoone * twotwo;
                }
            }
        }
        i++;
    }

    cout << countt << endl;
}