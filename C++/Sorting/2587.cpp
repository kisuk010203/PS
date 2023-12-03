#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    vector<int> v(5);
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        cin >> v[i];
        cnt += v[i];
    }
    sort(v.begin(), v.end());
    cout << cnt / 5 << "\n";
    cout << v[2] << "\n";
}
