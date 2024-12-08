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
        int n, r; cin >> n >> r;
        vector<int> v(n);
        rep(i, 0, n) cin >> v[i];
        int happy = 0;
        int rows = 0;
        int solo = 0;
        each(x, v) {
            if(x % 2 == 0) happy += x;
            else {happy += (x - 1); solo++;}
            rows += (x / 2);
        }
        if(solo <= r - rows) happy += solo;
        else {
            happy += ((r - rows) * 2 - solo);
        }cout << happy << "\n";
    }
}