#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long, long> pll;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        ll n, b, c; cin >> n >> b >> c;
        if(b == 0)  {
            if(c >= n) cout << n << "\n";
            else if(c < n - 2) cout << "-1\n";
            else cout << n - 1 << "\n";
        } else {
            if(c >= n) cout << n << "\n";
            else {
                ll i = (n  - c - 1) / b + 1L;
                i  = max(i, 0LL);
                cout << n - i << "\n";
            }
            
        }
    }
}