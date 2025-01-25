#include <bits/stdc++.h>
using namespace std;
int N, L;
int sequence[1000];
bool Recurse(int sum, int index)
{
    index++;

    if (sum == N)
        return true;
    if (sum > N)
        return false;
    if (index < L)
    {
        if (Recurse(sum, index))
        {
            return true;
        }
        else if (Recurse(sum + sequence[index], index))
        {
            return true;
        }
        return false;
    }
    return false;
}

int main()
{
    cin >> N >> L;
    for (int i = 0; i < L; i++)
    {
        cin >> sequence[i];
    }
    if (!Recurse(0, -1))
        cout << "Mom, you tricked me!";
    else
        cout << "I can do it!";
    cout << endl;
}