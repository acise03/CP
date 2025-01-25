#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[10];
bool visited[10];
int parent[10];
int start, endd;

bool bfs(int vertex, int previous) {
    for (int v: adjList[vertex]) {
        if (!visited[v]) {
            visited[v] = true;
            bfs(v, vertex);
        }
    }
}

bool print(int v, int p, int d) {
    bool tf = false;
    if (v == p) {
        cout << v << endl;
    }
    for (int vv: adjList[v]) {
        if (!visited[vv]) {
            visited[vv] = true;
            tf = bfs(vv, v);
            if (tf) {
                break;
            }
        }
    }
    if (tf) {
        cout << v << endl;
    }
}

int main() {
    adjList[1].push_back(2);
    adjList[2].push_back(1);
    adjList[2].push_back(3);
    adjList[2].push_back(4);
    adjList[2].push_back(6);
    adjList[2].push_back(7);
    adjList[3].push_back(4);
    adjList[3].push_back(8);
    adjList[4].push_back(3);
    adjList[4].push_back(2);
    adjList[4].push_back(5);
    adjList[5].push_back(4);
    adjList[5].push_back(6);
    adjList[6].push_back(5);
    adjList[6].push_back(2);
    adjList[7].push_back(2);
    adjList[8].push_back(3);
    start = 1;
    endd = 3;
    cout << dfs(1, 3) << endl;
    print(3);
}
