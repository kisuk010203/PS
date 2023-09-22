#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    ll a = 1, b = 1;
    for (int i = 0; i < n; i++) {
        ll temp = b;
        b = a + b;
        a = temp;
    }
    cout << 2*b << "\n";
}