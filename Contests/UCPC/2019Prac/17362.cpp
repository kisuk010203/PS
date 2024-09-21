#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = n & 7;
    if (ans >= 1 && ans <= 5)
        cout << ans;
    else
        cout << ((10 - ans) & 7);
}