#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        unordered_map<int, int> count;
        int max_count = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            count[x]++;
            max_count = max(max_count, count[x]);
        }
        if (max_count >= k)
            cout << k - 1 << "\n";
        else
            cout << n << "\n";
    }
}