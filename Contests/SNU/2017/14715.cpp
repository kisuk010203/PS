#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (!prime[i])
            continue;
        for (int j = 2 * i; j <= n; j += i) {
            prime[j] = false;
        }
    }
    int cnt = 0;
    int curr = n;
    for (int i = 2; i <= n; i++) {
        if (curr == 1)
            break;
        if (!prime[i])
            continue;
        while (curr % i == 0) {
            cnt++;
            curr /= i;
        }
    }
    int ans = ceil(log2(cnt));
    cout << ans << "\n";
}
