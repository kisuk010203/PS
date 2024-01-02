#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i += 2) {
        cout << i << " ";
    }
    for (int i = n - (n % 2); i > 0; i -= 2) {
        cout << i << " ";
    }
}
