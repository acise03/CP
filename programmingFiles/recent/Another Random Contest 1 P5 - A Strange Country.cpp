#include <bits/stdc++.h>
using namespace std;

int N;
int M, K;
int p[5005], height[5005], setSize[5005];
int days[300005];
int numSets;
deque<tuple<int, int, int, int> > edgeList; // weight, edge, edge, num

void initialize() {
    for (int i = 1; i <= N; ++i) {
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
    cin >> N;
    cin >> M;
    cin >> K;

    for (int i = 1; i <= M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u > v) {
            swap(u, v);
        }
        edgeList.push_back({w, u, v, i});
    }


    sort(edgeList.begin(), edgeList.end());
    memset(days, -1, sizeof(days));
    for (int ii = 1; ii <= K; ii++) {
        initialize();
        for (auto x: edgeList) {
            if (days[get<3>(x)] != -1) {
                continue;
            }
            int val = unionSet((get<1>(x)), get<2>(x));
            if (val == 1) {
                days[get<3>(x)] = ii;
            }
        }
    }
    for (int jj = 1; jj <= M; jj++) {
        cout << days[jj] << endl;
    }
}