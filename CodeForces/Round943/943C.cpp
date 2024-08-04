#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> x(n + 1);
        vector<int> a(n + 1);
        for (int i = 2; i <= n; i++)
            cin >> x[i];
        a[1] = x[2] + 1;
        for (int i = 2; i <= n; i++) {
            a[i] = x[i];
            if (i < n && a[i] <= x[i + 1]) {
                a[i] += a[i - 1] * ((x[i + 1] - a[i]) / a[i - 1] + 1);
            }
        }
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
}