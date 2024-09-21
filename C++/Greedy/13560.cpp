#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += v[i];
        if (res >= i * (i + 1) / 2)
            continue;
        cout << "-1\n";
        return 0;
    }
    if (res == n * (n - 1) / 2)
        cout << "1\n";
    else
        cout << "-1\n";
}