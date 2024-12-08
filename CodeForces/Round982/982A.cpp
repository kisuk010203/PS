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
        int max_w = 0, max_h = 0;
        rep(i, 0, n) {
            int w, h; cin >> w >> h;
            max_w = max(max_w, w);
            max_h = max(max_h, h);
        }
        cout << 2 * (max_w + max_h) << '\n';
    }
}