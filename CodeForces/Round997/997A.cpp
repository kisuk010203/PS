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
        int n, m; cin >> n >> m;
        int lft = m, btm = m;
        rep(i, 0, n) {
            
            int x, y; cin >> x >> y;
            if(i == 0) continue;
            lft += x;
            btm += y;
        }
        cout << (lft + btm) * 2 << "\n";
    }
}