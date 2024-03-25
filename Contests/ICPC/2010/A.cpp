#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int res = 0;
            for (int j = 0; j < i; j++) {
                res += (int)(arr[j] <= arr[i]);
            }
            ans += res;
        }
        cout << ans << '\n';
    }
}
