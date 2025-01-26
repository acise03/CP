#include <bits/stdc++.h>

using namespace std;
long long parents[200001];
pair<long long, long long> sorted_elements[200001];
int heights[200001];

long long find(long long x)
{
    if (parents[x] == x)
    {
        return x;
    }
    parents[x] = find(parents[x]);
    return parents[x];
}

void unionSet(long long i, long long j)
{
    long long ii = find(i);
    long long jj = find(j);
    if (heights[ii] > heights[jj])
    {
        swap(ii, jj);
    }
    parents[ii] = jj;
    if (heights[ii] == heights[jj])
    {
        heights[jj]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long N;
    cin >> N;

    for (long long i = 0; i < N; i++)
    {
        long long value;
        cin >> value;
        sorted_elements[i] = {value, i};
        parents[i] = i;
    }
    sort(sorted_elements, sorted_elements + N);

    long long kL = 0;               // 588467382138998913
    long long kR = 1e18 - 1;        // 588467382138999040
    long long kM = ((kL + kR) / 2); // 588467382138999040
    long long prevkM = -1;
    bool dontprint = false;

    while (kL < kR)
    {

        for (long long i = 0; i < N; i++)
        {
            parents[i] = i;
            heights[i] = 1;
        }
        kM = ((kL + kR) / 2);
        if (prevkM == kM)
        {
            cout << "KL: " << kL << " KM: " << kM << " PREV KM " << kM << " KR: " << kR << endl;
            //      dontprint = true;
            break;
        }
        prevkM = kM;
        bool possible = true;
        for (long long i = 0; i < N - 1; i++)
        {
            if (abs(sorted_elements[i].first - sorted_elements[i + 1].first) <= kM)
            {
                unionSet(sorted_elements[i].second, sorted_elements[i + 1].second);
            }
        }

        for (long long new_index = 0; new_index < N; new_index++)
        {
            long long original_index = sorted_elements[new_index].second;
            if (find(original_index) != find(new_index))
            {
                possible = false;
                break;
            }
        }
        if (possible)
        {
            kR = kM;
        }
        else
        {
            kL = kM + 1;
        }
    }
    if (!dontprint)
        cout << (kL) << endl;
}