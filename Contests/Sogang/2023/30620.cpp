#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll x, y;
    cin >> x >> y;
    cout << "2\n";
    cout << x * (y - 1) << "\n";
    cout << -(x - 1) * y << "\n";
}
