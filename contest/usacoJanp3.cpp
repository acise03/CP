#include <bits/stdc++.h>
using namespace std;

int N;
int cows[7505];
int vets[7505];
int counts[7505];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int tot = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> vets[i];
        tot += vets[i] == cows[i];
    }

    // middle is an index
    for (int mid = 0; mid < N; mid++) {
        int c = tot;
        for (int length = 0; mid - length >= 0 && mid + length < N; length++) {
            if (cows[mid - length] == vets[mid + length]) {
                c++;
                c -= cows[mid - length] == vets[mid - length];
            } else if (cows[mid - length] == vets[mid - length]) {
                c--;
            }
            if (cows[mid + length] == vets[mid - length]) {
                c++;
                c -= cows[mid + length] == vets[mid + length];
            } else if (cows[mid + length] == vets[mid + length]) {
                c--;
            }
            counts[c]++;
        }
    }


    // middle is not an index
    for (int mid = 1; mid < N; mid++) {
        int c = tot;
        for (int length = 0; mid - length - 1 >= 0 && mid + length < N; length++) {
            if (cows[mid - length - 1] == vets[mid + length]) {
                c++;
                c -= cows[mid - length - 1] == vets[mid - length - 1];
            } else if (cows[mid - length - 1] == vets[mid - length - 1]) {
                c--;
            }
            if (cows[mid + length] == vets[mid - length - 1]) {
                c++;
                c -= cows[mid + length] == vets[mid + length];
            } else if (cows[mid + length] == vets[mid + length]) {
                c--;
            }
            counts[c]++;
        }
    }


    for (int i = 0; i <= N; i++) {
        cout << counts[i] << endl;
    }
}
