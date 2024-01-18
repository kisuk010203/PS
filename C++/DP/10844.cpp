#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000
int stairs[101][10];
int get_stairs(int len, int start) {
    if (start < 0 || start > 9)
        return 0;
    if (len == 1)
        return 1;
    if (stairs[len][start] != 0)
        return stairs[len][start];
    return stairs[len][start] = (get_stairs(len - 1, start - 1) +
                                 get_stairs(len - 1, start + 1)) %
                                MOD;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    memset(stairs, 0, sizeof(stairs));
    int ans = 0;
    int n;
    cin >> n;
    for (int i = 1; i < 10; i++) {
        ans = (ans + get_stairs(n, i)) % MOD;
    }
    cout << ans << "\n";
}
