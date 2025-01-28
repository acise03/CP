#include <bits/stdc++.h>
using namespace std;

int N = 1000000;
int M, K;
int p[1000000], height[1000000], setSize[1000000];
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
    cin >> N >> K;

    for (int i = 1; i < N; i++) {
        int w;
        cin >> w;
        edgeList.push_back({w, i, i + 1});
        if (i + K <= N) {
            edgeList.push_back({0, i, i + K});
        }
    }
    initialize();
    sort(edgeList.begin(), edgeList.end());
    int cost = 0;
    for (auto x: edgeList) {
        cost += get<0>(x) * unionSet((get<1>(x)), get<2>(x));
    }
    cout << cost << endl;
}
