#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (2 * a <= b)
            cout << n * a << "\n";
        else
            cout << (n >> 1) * b + (n & 1) * a << "\n";
    }
}