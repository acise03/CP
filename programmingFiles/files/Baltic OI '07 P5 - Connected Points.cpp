#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000000;
vector<vector<int> > arr;

vector<vector<int> > multiply(vector<vector<int> > matrix1,
                              vector<vector<int> > matrix2) {
    vector<vector<int> > ans;
    for (int i = 0; i < matrix1.size(); i++) {
        vector<int> row(matrix1.size());
        for (int j = 0; j < matrix1.size(); j++)
            for (int k = 0; k < matrix1.size(); k++) {
                row[j] += ((matrix1[i][k] % mod) * (matrix2[k][j] % mod)) % mod;
                row[j] %= mod;
            }
        ans.push_back(row);
    }
    return ans;
}

vector<vector<int> > power(vector<vector<int> > matrix, int n) {
    vector<vector<int> > ans;
    for (int i = 0; i < matrix.size(); i++) {
        vector<int> r(matrix.size());
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

int n;

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    arr.push_back({0, 0, 1});
    arr.push_back({0, 0, 2});
    arr.push_back({2, 1, 4});
    vector<vector<int> > result = power(arr, n - 2);

    cout << (4 * result[0][1] + 2 * result[2][1] + 2 * result[0][2] + result[2][2]) % mod << endl;
}