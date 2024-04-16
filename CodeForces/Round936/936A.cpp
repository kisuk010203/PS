#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int median = v[(v.size() - 1) / 2];
        int upper_bound_median =
            upper_bound(v.begin(), v.end(), median) - v.begin();
        cout << upper_bound_median - (v.size() - 1) / 2 << "\n";
    }
}