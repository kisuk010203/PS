#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int x, n;
    cin >> x >> n;
    if (n == 1) {
        if (x >= 0) {
            cout << 0;
            return 0;
        }
        cout << "INFINITE";
        return 0;
    }
    if (n == 0) {
        if (x <= 0) {
            cout << 0;
            return 0;
        }
        cout << "INFINITE";
        return 0;
    }
    if (n % 2 == 1) {
        cout << "ERROR\n";
        return 0;
    }
    n /= 2;
    int cnt = 0;
    x -= n;
    while (x > 0) {
        cnt++;
        x -= n;
    }
    cout << cnt;
}
