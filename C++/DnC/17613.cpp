#include <bits/stdc++.h>
using namespace std;
vector<int> bds;
int solve(int x, int y) {
    // cout << "solve " << x << ' ' << y << '\n';
    if (x == 0 && y == 1) return 1;
    if (x == 0 && y == 0) return 0;
    assert(x <= y);
    int ans = 0;
    for (int k = 1; k <= 30; k++) {
        int bdleft = (1 << k) - 1;
        int bdrght = bdleft << 1;
        if (x > bdrght || y < bdleft) continue;
        if (bdleft < x) {
            int res = solve(x - bdleft, bdrght - bdleft);
            ans = max(ans, res + k);
            // cout << "case 1: " << res + k << '\n';
            continue;
        }
        if (bdrght > y) {
            int res = solve(0, y - bdleft);
            ans = max(ans, res + k);
            // cout << "case 2: " << res + k << '\n';
            continue;
        }
        if (x <= bdleft && y >= bdrght) {
            ans = max(ans, k * (k + 1) / 2 + 1);
            continue;
        } 
        assert(false);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << '\n';
    int T; cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        int res = solve(x, y);
        cout << res << '\n';
    }
}