#include <bits/stdc++.h>
using namespace std;

int N = 10000000;
int M;
int p[N], height[N], setSize[N];
int numSets;
vector<tuple<int, int, int> > edgeList; // weight, edge, edge

void initialize() {
    for (int i = 0; i < N; ++i) {
        p[i] = i;
        setSize[i] = 1; //optionalfeature
    }
    numSets = N; //optionalfeature
}

int findSet(int i) {
    if (p[i] == i)
        return i;
    p[i] = findSet(p[i]); //PathCompression
    return p[i];
}

bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

int numDisjointSets() {
    return numSets;
}

int sizeOfSet(int i) {
    return setSize[findSet(i)];
}

bool unionSet(int i, int j) {
    if (isSameSet(i, j))
        return 0;
    int x = findSet(i);
    int y = findSet(j);
    if (height[x] > height[y])
        swap(x, y);
    p[x] = y;
    if (height[x] == height[y])
        height[y]++; //HeightCompression
    setSize[y] += setSize[x];
    numSets--;
    return 1;
}

int main() {
    initialize();
    sort(edgeList.begin(), edgeList.end());
    int cost = 0;

    for (auto x: edgeList) {
        cost += get<0>(x) * unionSet((get<1>(x)), get<2>(x));
    }
}
