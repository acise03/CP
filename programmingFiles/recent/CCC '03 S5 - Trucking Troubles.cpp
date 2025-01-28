#include <bits/stdc++.h>
using namespace std;

int N = 10005;
int M;
int p[10005], height[10005], setSize[10005];
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

int c, r, d;
unordered_set<int> mustVisit;

int main() {
    cin >> c >> r >> d;
    N = c;

    initialize();

    for (int i = 0; i < r; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edgeList.push_back({-w, x, y});
    }

    for (int i = 0; i < d; i++) {
        int dcity;
        cin >> dcity;
        mustVisit.insert(dcity);
    }

    sort(edgeList.begin(), edgeList.end());
    int cost = 0;


    for (auto x: edgeList) {
        cost -= get<0>(x) * unionSet((get<1>(x)), get<2>(x));
        if (mustVisit.find(get<1>(x)) != mustVisit.end() && isSameSet(get<1>(x), 1)) {
            mustVisit.erase(get<1>(x));
            for (int v: mustVisit) {
                if (isSameSet(v, 1)) {
                    mustVisit.erase(v);
                }
            }
        }
        if (mustVisit.find(get<2>(x)) != mustVisit.end() && isSameSet(get<2>(x), 1)) {
            mustVisit.erase(get<2>(x));
            for (int v: mustVisit) {
                if (isSameSet(v, 1)) {
                    mustVisit.erase(v);
                }
            }
        }
        if (mustVisit.empty()) break;
    }
    cout << cost << endl;
}
