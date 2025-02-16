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
        int arr[n][n];
        int per[n];
        rep(i, 0, n) {
            string s; cin >> s;
            rep(j, 0, n) arr[i][j] = s[j] - '0';
        }
        fill(per, per + n, -1);
        rep(i, 0, n) {
            int cnt = 0;
            rep(j, i + 1, n) cnt += arr[i][j];
            int idx = 0;
            for(int k = n - 1; k >= 0; k--) {
                if(per[k] == -1 && idx == cnt) {
                    per[k] = i;
                    break;
                }
                if(per[k] == -1) idx++;
            }
        }
        each(a, per) cout << a + 1 << " ";
        cout << "\n";
    }
}