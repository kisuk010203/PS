#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> heights(n);
    vector<int> diff_heights(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
        if (i > 0)
            diff_heights[i - 1] = heights[i] - heights[i - 1];
    }
    int ans = heights[n - 1] - heights[0];
    sort(diff_heights.begin(), diff_heights.end(), greater<int>());
    for (int i = 0; i < k - 1; i++) {
        ans -= diff_heights[i];
    }
    cout << ans << "\n";
}
