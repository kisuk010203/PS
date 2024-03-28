#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc, char const* argv[]) {
    ll n, p;
    cin >> n >> p;
    ll ret = 1;
    for (int i = 1; i <= n; i++) {
        ret *= i;
        ret %= p;
    }
    cout << ret << "\n";
    return 0;
}
