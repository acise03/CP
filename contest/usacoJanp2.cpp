#include <bits/stdc++.h>
using namespace std;

int N;
int numbers[1000005];
int diffNumbersCount[1000005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> numbers[i];
        int currNums = count(numbers, numbers + i, numbers[i]);
        if (currNums == 0) {
            diffNumbersCount[i] = diffNumbersCount[i - 1] + 1;
        }
        else {
            diffNumbersCount[i] = diffNumbersCount[i - 1];

        }
    }
    int total = 0;
    for (int i = N; i >= 1; i--) {
        int afterCount = count(numbers + i, numbers + N + 1, numbers[i]);
        if (afterCount == 2) {
            total += diffNumbersCount[i] - 1;
        }
    }
    cout << total << endl;
}
