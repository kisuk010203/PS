#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> sticks(100);
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            sticks[temp - 1]++;
        }
        int ans = 0;
        for (int i = 0; i < 100; i++) {
            ans += sticks[i] / 3;
        }
        cout << ans << "\n";    
    }
}