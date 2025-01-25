// AC
#include <bits\stdc++.h>
using namespace std;

/*
https://dmoj.ca/problem/coci11c6p4
*/
int K;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> K;
    int cuts = 0;
    int pieces = 1;
    while (pieces < K)
    {
        cuts++;
        pieces += cuts;
    }
    int vert = 5000;
    int horiz = -4999;
    cout << cuts << endl;
    for (int i = 0; i < cuts; i++)
    {
        cout << -5000 << " " << vert << " " << horiz << " " << -5000 << endl;
        vert--;
        horiz++;
        //cout << i;
    }
    //cout << "DONE.";
}