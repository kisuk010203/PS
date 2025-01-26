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
        vector<int> v(n);
        each(a, v) cin >> a;
        int cur_s = 0;
        int happ = 0;
        each(a, v){
            cur_s += a;

            if(sqrt(cur_s) == (int)sqrt(cur_s) && (int)sqrt(cur_s) % 2 == 1) happ++;
        }
        cout << happ << "\n";
    }
}