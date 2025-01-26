#include <bits/stdc++.h>
using namespace std;

int m, n;
string street1, street2, observation;

const int N = 400000;
int p[N], height[N], setSize[N];
map<string, int> roadtoNum;

int numSets;
void initialize()
{
    for (int i = 0; i < N; ++i)
    {
        p[i] = i;
        setSize[i] = 1; // optional feature
    }
    numSets = N; // optional feature
}
int findSet(int i)
{
    if (p[i] == i)
        return i;
    p[i] = findSet(p[i]); // Path Compression
    return p[i];
}
bool isSameSet(int i, int j)
{
    return findSet(i) == findSet(j);
}
int numDisjointSets()
{
    return numSets;
}
int sizeOfSet(int i)
{
    return setSize[findSet(i)];
}
void unionSet(int i, int j)
{
    if (isSameSet(i, j))
        return;
    int x = findSet(i);
    int y = findSet(j);
    if (height[x] > height[y])
        swap(x, y);
    p[x] = y;
    if (height[x] == height[y])
        height[y]++; // Height Compression
    setSize[y] += setSize[x];
    numSets--;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    initialize();

    for (int i = 0; i < m; i++)
    {
        cin >> street1 >> street2 >> observation;
        if (roadtoNum.count(street1) < 1)
            roadtoNum[street1] = roadtoNum.size();
        if (roadtoNum.count(street2) < 1)
            roadtoNum[street2] = roadtoNum.size();
        if (observation == "parallel")
        {
            unionSet(roadtoNum[street1], roadtoNum[street2]);
            unionSet(roadtoNum[street1] + N / 2, roadtoNum[street2] + N / 2);
        }
        else
        {
            unionSet(roadtoNum[street1] + N / 2, roadtoNum[street2]);
            unionSet(roadtoNum[street1], roadtoNum[street2] + N / 2);
        }
    }
    bool f = false;
    for (int i = 0; i < N / 2; i++)
    {
        if (isSameSet(i, i + N / 2) && !f)
        {
            cout << "Waterloo" << endl;
            f = true;
        }
    }
    if (!f)
        for (int i = 0; i < n; i++)
        {
            cin >> street1 >> street2;
            if (roadtoNum.count(street1) < 1 || roadtoNum.count(street2) < 1)
                cout << "unknown" << endl;
            else if (isSameSet(roadtoNum[street1] + N / 2, roadtoNum[street2]))
                cout << "intersect" << endl;
            else if (isSameSet(roadtoNum[street1], roadtoNum[street2]))
                cout << "parallel" << endl;
            else
                cout << "unknown" << endl;
        }
}