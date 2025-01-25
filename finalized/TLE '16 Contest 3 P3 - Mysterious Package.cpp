#include <bits/stdc++.h>
using namespace std;

int N, CSid, girlID, p, s, nthStudent;

int classToPeriod[1000000];

map<int, int> IDtoStudentNum;
vector<int> StudentNumToClasses[1000000];

set<int> adjList[1000000];

int minPPl[1000000];

bool cmp(int a, int b) {
    return classToPeriod[a] < classToPeriod[b];
}

int main() {
    cin >> N;
    cin >> CSid >> girlID;
    nthStudent = 0;
    try {
        for (int i = 0; i < N; i++) {
            cin >> p >> s;
            classToPeriod[i] = p;
            for (int j = 0; j < s; j++) {
                int id;
                cin >> id;
                if (!(IDtoStudentNum.find(id) != IDtoStudentNum.end())) {
                    IDtoStudentNum[id] = nthStudent;
                    nthStudent++;
                }
                StudentNumToClasses[IDtoStudentNum[id]].push_back(i);
            }
        }
    } catch (bad_alloc &ba) {
        cout << "bad_alloc caught: " << ba.what() << '\n';
    }
    for (int i = 0; i < nthStudent; i++) {
        sort(StudentNumToClasses[i].begin(), StudentNumToClasses[i].end(), cmp);
        for (int j = 0; j < StudentNumToClasses[i].size(); j++) {
            for (int k = j + 1;
                 k < StudentNumToClasses[i].size(); k++) {
                if (classToPeriod[StudentNumToClasses[i][j]] < classToPeriod[StudentNumToClasses[i][k]]) {
                    adjList[StudentNumToClasses[i][j]].insert(StudentNumToClasses[i][k]);
                }
            }
        }
    }

    deque<int> nextIs;

    memset(minPPl, -1, size(minPPl));
    for (int i: StudentNumToClasses[IDtoStudentNum[CSid]]) {
        nextIs.push_back(i);
        minPPl[i] = 1;
    }
    int mini = INT_MAX;
    int ind = 0;
    while (!nextIs.empty()) {
        int pp = nextIs.front();
        nextIs.pop_front();
        if (count(StudentNumToClasses[IDtoStudentNum[girlID]].begin(),
                  StudentNumToClasses[IDtoStudentNum[girlID]].end(),
                  pp) > 0) {
            if (mini > classToPeriod[pp]) {
                ind = pp;
                mini = classToPeriod[pp];
            }
        }
        if (mini == INT_MAX)
            for (int i: adjList[pp]) {
                if (minPPl[i] == -1) {
                    minPPl[i] = minPPl[pp] + 1;
                    nextIs.push_back(i);
                }
            }
    }
    if (minPPl[ind] == -1 || mini == INT_MAX) {
        cout << "delivery failure" << endl;
    } else {
        cout << minPPl[ind] << endl << mini << endl;
    }
}