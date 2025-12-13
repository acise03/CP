#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b, n;
const int mod = 1000000000;
vector<vector<long long> > arr;

vector<vector<long long> > multiply(vector<vector<long long> > matrix1,
                                    vector<vector<long long> > matrix2) {
    vector<vector<long long> > ans;
    for (int i = 0; i < matrix1.size(); i++) {
        vector<long long> row(matrix1.size());
        for (int j = 0; j < matrix1.size(); j++)
            for (int k = 0; k < matrix1.size(); k++) {
                row[j] += matrix1[i][k] * matrix2[k][j];
                row[j] %= mod;
            }
        ans.push_back(row);
    }
    return ans;
}

vector<vector<long long> > power(vector<vector<long long> > matrix, long long n) {
    vector<vector<long long> > ans;
    for (int i = 0; i < matrix.size(); i++) {
        vector<long long> r(matrix.size());
        ans.push_back(r);
    }
    for (int i = 0; i < ans.size(); i++)
        ans[i][i] = 1;
    while (n > 0) {
        if (n & 1)
            ans = multiply(ans, matrix);
        matrix = multiply(matrix, matrix);
        n >>= 1;
    }
    return ans;
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> n;
    arr.push_back({0, 1});
    arr.push_back({1, 1});
    vector<vector<long long> > result = power(arr, n);
    int cou = 0;
    cou += (result[0][0] * a) % 1000000000 + (result[0][1] * b) % 1000000000;
    cout << cou % 1000000000 << endl;
}