#include <bits/stdc++.h>
using namespace std;

#define int long long

int N, M;
int p[100005], height[100005], setSize[100005];
int friendliness[100005];
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

signed main() {
    cin >> N;
    cin >> M;

    for (int i = 1; i <= N; i++) {
        cin >> friendliness[i];
    }


    for (int j = 1; j <= M; j++) {
        int first, second;
        cin >> first >> second;
        edgeList.emplace_back(0, first, second);
    }

    for (int i = 1; i < N; i++) {
        edgeList.push_back({abs(friendliness[i] - friendliness[i+1]), i, i+1});
    }

    initialize();
    sort(edgeList.begin(), edgeList.end());
    int cost = 0;

    for (auto x: edgeList) {
        cost += get<0>(x) * unionSet((get<1>(x)), get<2>(x));
    }
    cout << cost << endl;
}
