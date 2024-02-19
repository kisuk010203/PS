#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<char> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    char alice;
    cin >> alice;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == alice)
            cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
