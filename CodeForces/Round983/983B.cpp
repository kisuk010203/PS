#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long, long> pll;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int n, k; cin >> n >> k;
        if(n == 1) cout << "1\n1\n";
        else if(k == 1 || k == n) cout << "-1\n";
        else {
            if(k % 2 == 0) cout << "3\n" << "1 " << k << " " << k +1 << "\n";
            else cout << "3\n1 " << k - 1 << " " << k + 2 << "\n";
        }
    }
}