#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size();
        ll ones_count = 0;
        ll sum_ones_index = 0;
        ll zeros_count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ones_count++;
                sum_ones_index += i;
            } else if (ones_count > 0) {
                zeros_count++;
            }
        }
        ll ans = zeros_count;
        for (int i = 0; i < ones_count; i++) {
            ans += (n - i - 1);
        }
        ans -= sum_ones_index;
        cout << ans << "\n";
    }
}