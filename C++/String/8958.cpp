#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = 0, curr = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'O') {
                curr++, ans += curr;
            } else {
                curr = 0;
            }
        }
        cout << ans << '\n';
    }
}
