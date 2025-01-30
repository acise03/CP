#include <bits/stdc++.h>
using namespace std;

int N = 10005;
int M;
int p[10005], height[10005], setSize[10005];
int numSets;
vector<tuple<int, int, int> > edgeList; // weight, edge, edge
vector<tuple<int, int, int> > edgeListWithZero; // weight, edge, edge

void initialize1() {
    for (int i = 1; i <= N; ++i) {
        p[i] = i;
        setSize[i] = 1; //optionalfeature
    }
    numSets = N; //optionalfeature
}

void initialize2() {
    for (int i = 0; i <= N; ++i) {
        p[i] = i;
        setSize[i] = 1; //optionalfeature
    }
    numSets = N + 1; //optionalfeature
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

map<pair<int, int>, vector<int> > edgesToPens;
map<pair<int, int>, int> edgesToCost;

int main() {
    cin >> M;
    N = M + 1;

    for (int i = 1; i <= M; i++) {
        int e;
        cin >> e;
        int corners[e];
        for (int j = 0; j < e; j++) {
            cin >> corners[j];
        }

        for (int j = 0; j < e; j++) {
            int cost;
            cin >> cost;
            int a = corners[j];
            int b = corners[(j + 1) % e];
            if (a > b) {
                swap(a, b);
            }
            edgesToCost[{a, b}] = cost;
            edgesToPens[{a, b}].push_back(i);
        }
    }
    // outside is 0
    for (auto v: edgesToPens) {
        if (v.second.size() == 1) {
            edgeListWithZero.push_back({edgesToCost[v.first], 0, v.second[0]});
        } else {
            edgeList.push_back({edgesToCost[v.first], v.second[0], v.second[1]});
            edgeListWithZero.push_back({edgesToCost[v.first], v.second[0], v.second[1]});
        }
    }

    sort(edgeList.begin(), edgeList.end());
    sort(edgeListWithZero.begin(), edgeListWithZero.end());

    int mini = INT_MAX;

    N = M;
    initialize1();
    int tot = 0;

    for (auto x: edgeList) {
        tot += get<0>(x) * unionSet(get<1>(x), get<2>(x));
    }
    if (numDisjointSets() == 1)
        mini = min(mini, tot);

    initialize2();

    tot = 0;
    for (auto x: edgeListWithZero) {
        tot += get<0>(x) * unionSet(get<1>(x), get<2>(x));
    }
    if (numDisjointSets() == 1)
        mini = min(mini, tot);

    cout << mini << endl;
}
