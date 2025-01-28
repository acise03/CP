#include <bits/stdc++.h>
using namespace std;

int N = 100001;
int u, v;
int M;
int p[100001], height[100001], setSize[100001];
int numSets;
vector<tuple<int, int, int, int> > edgeList; // weight, edge, edge, edgeNumber

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

int unionSet(int i, int j) {
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
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> u >> v;
        edgeList.push_back({i, u, v, i});
    }

    initialize();

    sort(edgeList.begin(), edgeList.end());
    string output = "";

    for (auto x: edgeList) {
        int k = get<0>(x) * unionSet((get<1>(x)), get<2>(x));
        if (k > 0) {
            output += to_string(get<3>(x)) + "\n";
        }
    }
    if (numDisjointSets() > 1) {
        cout << "Disconnected Graph" << endl;
    } else {
        cout << output;
    }
}
