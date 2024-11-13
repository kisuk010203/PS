#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int n ; cin >> n;
        if(n == 1) cout << "0\n";
        else {
            cout << "1";
            for(int i = 0; i < n - 1; i++) cout << "0";
            cout << "\n";
        }
    }
}