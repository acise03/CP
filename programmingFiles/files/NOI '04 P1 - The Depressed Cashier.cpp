#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
#define int long long
using namespace __gnu_pbds;
using namespace std;

template<class T>
using Tree = tree<T, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update>;

int n, mini, k;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> mini;
    int change = 0;

    Tree<int> employeeees;
    int leaves = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c >> k;
        if (c == 'I') {
            employeeees.insert(k - change);
            while (!employeeees.empty() && *employeeees.begin() + change < mini) {
                employeeees.erase(employeeees.begin());
            }
        } else if (c == 'A') {
            change += k;
        } else if (c == 'S') {
            change -= k;
            while (!employeeees.empty() && *employeeees.begin() + change < mini) {
                employeeees.erase(employeeees.begin());
                leaves++;
            }
        } else if (c == 'F') {
            if (k > employeeees.size()) {
                cout << -1 << endl;
            } else {
                k--;
                cout << *employeeees.find_by_order(employeeees.size() - k - 1) + change << endl;
            }
        }
    }
    while (!employeeees.empty() && *employeeees.begin() + change < mini) {
        employeeees.erase(employeeees.begin());
        leaves++;
    }

    cout << leaves << endl;
}