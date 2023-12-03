#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int houses[n];
    for (int i = 0; i < n; i++) {
        cin >> houses[i];
    }
    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (houses[i] < l || houses[i] > r)
                cout << houses[i] << " ";
            else {
                cout << l + cnt++ << " ";
            }
        }
        cout << "\n";
    }
}
