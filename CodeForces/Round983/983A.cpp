#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long, long> pll;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        int m = 0;
        for(int i = 0; i < n * 2; i++) {
            int temp; cin >> temp;
            m+= temp;
        }
        int min_ans = m % 2;
        cout << min_ans << " ";
        if(m <= n) cout << m << "\n";
        else {
            int res = m - n;
            cout << n - res << "\n";
        }
    }
}
