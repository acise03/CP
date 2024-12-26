#include <bits/stdc++.h>

using namespace std;
int D, N;
int distances[32];
int ds[5281];

int main()

{
    cin >> D >> N;
    fill(ds, ds+5281, 100);
    for (int i = 0; i < N; i++)
    {
        cin >> distances[i];
    }
    ds[0] = 0;

    queue<int> currents;

    currents.push(0);

    while (currents.size() > 0)
    {
        int k = currents.front();
        currents.pop();
        for (int i = 0; i < N; i++)
        {
            if (k + distances[i] <= 5280)
            {
                if (ds[k + distances[i]] > ds[k] + 1)
                {
                    ds[k + distances[i]] = ds[k] + 1;
                    currents.push(k + distances[i]);
                    if (ds[k + distances[i]] > 100)
                    {
                        cout << k + distances[i] << "     " << ds[k + distances[i]] << endl;
                    }
                }
            }
        }
    }

    if (ds[D] != 100)
    {
        cout << "Roberta wins in " << ds[D] << " strokes." << endl;
    }
    else
    {
        cout << "Roberta acknowledges defeat." << endl;
    }
}