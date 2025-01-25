#include <bits/stdc++.h>

using namespace std;
int M, Q;
string names[100];
int times[100];
int minimum = INT_MAX;
string result = "";
void Recurse(int index, int currentTime, int highestTime, int currentPeopleCount, string output)
{
    if (currentTime > minimum)
    {
        return;
    }
    if (index == Q)
    {
        if (minimum > currentTime)
        {
            minimum = currentTime;
            result = output;
        }
    }
    else if (index < Q)
    {
        if (currentPeopleCount < M)
        {
            // 1. doesn't include
            Recurse(index + 1, currentTime + times[index+1], times[index+1], 1, (output + "\n" + names[index+1]));

            // 2. includes
            if (times[index+1] > highestTime)
            {
                Recurse(index + 1, currentTime - highestTime + times[index+1], times[index+1], currentPeopleCount + 1, output + " " + names[index+1]);
            }
            else
            {
                Recurse(index + 1, currentTime, highestTime, currentPeopleCount + 1, output + " " + names[index+1]);
            }
        }
        else
        {
            Recurse(index + 1, currentTime + times[index+1], times[index+1], 1, output + "\n" + names[index+1]);
        }
    }
}

int main()
{
    cin >> M >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> names[i];

        cin >> times[i];
    }
    Recurse(0, times[0], times[0], 1, names[0]);
    cout << "Total Time: " << minimum << endl;
    cout << result << endl;
}