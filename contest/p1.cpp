#include <bits/stdc++.h>
using namespace std;


int n, a, b;
vector<int> adjList[105];
bool visited[105];
int maxLength;
int maxInd;
int totMax;

void recurseB(int v, int currLength) {
    if (maxLength < currLength) {
        maxInd = v;
        maxLength = currLength;
    }
    for (int next: adjList[v]) {
        if (!visited[next]) {
            visited[next] = true;
            recurseB(next, currLength + 1);
            visited[next] = false;
        }
    }
}

void recurseA(int v, int currLength) {
    if (maxLength < currLength) {
        maxInd = v;
        maxLength = currLength;
    }
    for (int next: adjList[v]) {
        if (!visited[next]) {
            visited[next] = true;
            recurseB(next, currLength + 1);
            //     visited[next] = false;
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    visited[1] = true;
    recurseB(1, 1);
    visited[1] = false;

    visited[maxInd] = true;
    recurseA(maxInd, 1);

    totMax = max(totMax, maxLength);

    for (int i = 1; i <= 100; i++) {
        if (!visited[i]) {
            visited[i] = true;
            recurseB(i, 1);
            visited[i] = false;
            totMax = max(totMax, maxLength);
        }
    }
    for (int j = 1; j < 100; j++) {
        totMax = max(totMax, ((int) adjList[j].size() / 2) * 2 + 1);
    }
    cout << totMax << endl;
}
