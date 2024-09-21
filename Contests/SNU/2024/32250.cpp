#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    int both_ends[n + 1];
    int ans = 0;

    both_ends[1] = 1;
    both_ends[2] = 1;
    both_ends[3] = 2;
    both_ends[4] = 2;
    if (n <= 5) {
        cout << (n + 1) / 2;
        return 0;
    }

    for (int i = 5; i <= n; i++) {
        both_ends[i] = both_ends[(i / 2) + 1] + both_ends[i - (i / 2)] - 1;
    }
    for (int k = 1; k < n - 1; k++) {
        ans = max(ans, both_ends[k + 1] + both_ends[n - k] - 1);
    }
    cout << ans << "\n";
}