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
        switch (n) {
        case 2:
            cout << "1 1\n1 2\n";
            break;
        case 3:
            cout << "2 1\n2 3\n3 1\n";
            break;
        default:
            for (int i = 1; i <= n; i++) {
                if (i == n - 1)
                    cout << i << " " << n << "\n";
                else
                    cout << i << " " << i << "\n";
            }

            break;
        }
        cout << "\n";
    }
}