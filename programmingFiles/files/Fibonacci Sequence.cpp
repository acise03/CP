#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int a, b, n;
const int mod = 1000000007;
vector<vector<unsigned long long> > arr;

vector<vector<unsigned long long> > multiply(vector<vector<unsigned long long> > matrix1,
                                             vector<vector<unsigned long long> > matrix2) {
    vector<vector<unsigned long long> > ans;
    for (int i = 0; i < matrix1.size(); i++) {
        vector<unsigned long long> row(matrix1.size());
        for (int j = 0; j < matrix1.size(); j++)
            for (int k = 0; k < matrix1.size(); k++) {
                row[j] += matrix1[i][k] * matrix2[k][j];
                row[j] %= mod;
            }
        ans.push_back(row);
    }
    return ans;
}

vector<vector<unsigned long long> > power(vector<vector<unsigned long long> > matrix, unsigned long long n) {
    vector<vector<unsigned long long> > ans;
    for (int i = 0; i < matrix.size(); i++) {
        vector<unsigned long long> r(matrix.size());
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
    cin >> n;
    a = 0;
    b = 1;
    arr.push_back({0, 1});
    arr.push_back({1, 1});
    vector<vector<unsigned long long> > result = power(arr, n);
    cout << result[0][1] % 1000000007 << endl;
}