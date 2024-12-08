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
        vector<int> v(n) ;
        rep(i, 0, n) cin >> v[i];
        int min_ans = n;
        rep(i, 0, n) {
            int cnt = i;
            rep(j, i + 1, n)
                if(v[j] > v[i]) cnt++;
            min_ans = min(min_ans, cnt);
        }
        cout << min_ans << '\n';
    }
}