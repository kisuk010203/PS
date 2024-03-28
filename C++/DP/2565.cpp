#include <bits/stdc++.h>
using namespace std;
typedef pii pair<int, int>;
set<pii> pair_set;
int ans[501][501];
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pair_set.insert({--a, --b});
    }
    memset(ans, 0, sizeof(ans));
    for (int sum = 500 * 2 - 2; sum >= 0; sum--) {
        for (int i = 0; i <= sum; i++) {
            if (i >= 500 || sum - i >= 500)
                continue;
            ans[i][sum - i] = max(ans[i + 1][sum - i], ans[i][sum - i + 1]) +
                              (int)(pair_set.find());
        }
    }
}
