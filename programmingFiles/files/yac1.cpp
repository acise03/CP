#include <bits/stdc++.h>
using namespace std;

int T, N, s;
deque<int> seq;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for (int testcase = 0; testcase < T; testcase++) {
        seq.clear();
        cin >> N;
        bool tc1 = true;
        bool tc2 = false;
        bool tc3 = false;
        cin >> s;
        int tc2v = s;
        int i = 0;
        do {
            seq.push_back(s);
            if (tc1) {
                if (s != 1) {
                    tc1 = false;
                    tc2 = true;
                } else {
                    tc2v = s;
                }
            }
            if (tc2) {
                if (s != tc2v) {
                    tc2 = false;
                    tc3 = true;
                }
            }
            i++;
            if (i < N)
                cin >> s;
        } while (i < N);
        if (tc1) {
            if (N % 2 == 0) {
                cout << "Mike" << endl;
            } else {
                cout << "Josh" << endl;
            }
        } else if (tc2) {
            cout << "Mike" << endl;
        } else {
            sort(seq.begin(), seq.end());
            while (!seq.empty() && seq.front() == 1) {
                seq.pop_front();
                if (seq.front() == 1) {
                    seq.pop_front();
                } else {
                    seq.push_front(1);
                    break;
                }
            }
            if (N == 2) {
                if (seq.front() == 1) {
                    seq.pop_front();
                    if (seq.front() == 1)
                        cout << "Mike" << endl;
                    else
                        cout << "Josh" << endl;
                } else {
                    cout << "Mike" << endl;
                }
            } else {
                if (seq.front() == 1) {
                    cout << "Josh" << endl;
                } else {
                    cout << "Mike" << endl;
                }
            }
        }
    }
}
