#include <bits/stdc++.h>
using namespace std;
bool recurse(long long val_curr, long long val_desired, vector<long long> nums, long long index)
{
    if (index >= nums.size())
    {
        if (val_curr == val_desired)
        {
            return true;
        }
        else
            return false;
    }
    long long x = nums[index];
    index++;
    long long k = stoll(to_string(val_curr) + to_string(x));
    return (recurse(val_curr + x, val_desired, nums, index) || recurse(val_curr * x, val_desired, nums, index) || recurse(k, val_desired, nums, index));
}
int main()
{
    string s;
    long long countt = 0;
    while (getline(cin, s) && s != "0")
    {
        stringstream ss(s);
        long long desired;
        ss >> desired;
        char del;
        ss >> del;
        long long x;
        ss >> x;
        vector<long long> arr;
        long long k;
        while (ss >> k)
        {
            arr.push_back(k);
        }
        if (recurse(x, desired, arr, 0))
        {
            countt += desired;
            cout << " COUNT: " << desired << endl;
        }
    }
    cout << countt;
}