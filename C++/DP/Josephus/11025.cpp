#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = (res + k) % i;
    }
    cout << res + 1;
}
