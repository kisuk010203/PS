#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for(int i = a; i < b; i++)
#define each(a, b) for(auto& a : b)
typedef pair<ll, ll> pll;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        int arr[2][n];
        rep(i, 0, 2) rep(j, 0, n) cin >> arr[i][j];
        vector<int> v;
        ll ans = 0L;

        rep(i, 0, n) {
            ans += max(arr[0][i], arr[1][i]);
            v.push_back(min(arr[0][i], arr[1][i]));
        }
        ans += *max_element(all(v));
        cout << ans << "\n";
    }
}