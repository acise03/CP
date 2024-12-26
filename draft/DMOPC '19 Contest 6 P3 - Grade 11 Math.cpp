#include <bits/stdc++.h>

using namespace std;
vector<long long> indexes;
bool visited[500000];
long long nextt[500000];
long long getNext(long long value)
{
    if (visited[nextt[value]])
        nextt[value] = getNext(nextt[value]);
    return nextt[value];
}
int main()
{
    long long _S_, M;
    string S;
    cin >> _S_ >> M;
    cin >> S;

    long long total = 0;
    for (long long i = 0; i < _S_; i++)
    {
        nextt[i] = i + 1;
        if (S[i] != '1')
        {
            indexes.push_back(i);
        }
        else
        {
            total = total + ((S[i] - '0') * (long long)powl(2, _S_ - i - 1)) % 1000000007;
            visited[i] = true;
        }
    }
    for (long long i = 0; i < M; i++)
    {
        long long l, r;
        cin >> l >> r;
        l--;

        long long nextIndex = indexes[lower_bound(indexes.begin(), indexes.end(), l) - indexes.begin()];
        while (nextIndex < r)
        {
            total = ((long long)powl(2, _S_ - nextIndex - 1) + total) % 1000000007;
            indexes.erase(find(indexes.begin(), indexes.end(), nextIndex));
            visited[nextIndex] = true;
            nextIndex = getNext(nextIndex);
        }
        cout << total << endl;
    }
}