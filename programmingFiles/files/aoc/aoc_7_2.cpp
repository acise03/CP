#include <bits/stdc++.h>
using namespace std;


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
        vector<long long> deq;
        deq.push_back(x);
        long long k;
        bool tf = false;
        while (ss >> k && !tf)
        {
            long long sizey = deq.size();
            for (long long i = 0; i < sizey; i++)
            {
                if (deq[i] + k == desired || deq[i] * k == desired)
                {
                    tf = true;
                    break;
                }
                if (deq[i] + k < desired)
                {
                    deq.push_back(deq[i] + k);
                }
                if (deq[i] * k < desired)
                {
                    deq.push_back(deq[i] * k);
                }
            }
            deq.erase(deq.begin(), deq.begin() + sizey);
        }
        if (tf)
        {
            countt += desired;
        }
    }

    cout << countt;
}