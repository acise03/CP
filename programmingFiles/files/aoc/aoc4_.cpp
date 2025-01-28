#include <bits/stdc++.h>
using namespace std;
vector<string> arr;
int main()
{
    string input;
    cin >> input;
    while (input != "0")
    {
        arr.push_back(input);
        cin >> input;
    }
    int count = 0;

    for (int i = 1; i < arr.size() - 1; i++)
    {
        for (int j = 1; j < arr[0].length() - 1; j++)
        {
            if (arr[i][j] == 'A')
            {
                if ((arr[i - 1][j + 1] == 'M' && arr[i + 1][j - 1] == 'S' || arr[i - 1][j + 1] == 'S' && arr[i + 1][j - 1] == 'M') && (arr[i - 1][j - 1] == 'M' && arr[i + 1][j + 1] == 'S' || arr[i - 1][j - 1] == 'S' && arr[i + 1][j + 1] == 'M'))
                {
                    count++;
                }
            }
        }
    }

    cout << count;
}