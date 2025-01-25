#include <bits/stdc++.h>
using namespace std;
string line;

int main()
{
    getline(cin, line);

    int count = 0;

    while (line != "0")
    {
        bool tf = true;
        stringstream ss(line);
        int next;
        ss >> next;
        if (next > prev)
        {
            incdec = true;
        }
        else
        {
            incdec = false;
        }
        if (!(abs(next - prev) >= 1 && abs(next - prev) <= 3))
        {
            tf = false;
        }
        while (ss >> next)
        {

            if (!(next > prev && incdec || next < prev && !incdec) || !(abs(next - prev) >= 1 && abs(next - prev) <= 3))
            {
                tf = false;
            }
            prev = next;
        }
        getline(cin, line);
        if (tf)
        {
            cout << "s";
            count++;
        }
        else {
            cout << "n";
        }
    }
    cout << count;
}