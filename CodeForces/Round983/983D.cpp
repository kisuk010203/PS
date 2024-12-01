#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<long, long> pll;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vector<int> par(n);
        par[1] = 0;
        int k = 2;
        while(true) {
            cout << "? " << 1 << " " << k << "\n";
            cout.flush();
            int r; cin >> r;
            if(r == 0) {
                par[k] = 1;
                break;
            } else {
                par[k] = 0;
                k++;
            }
        }
        // 1- k 0-1..k-1
        int l = 2, r = k;
        int nxt = k + 1;
        while(nxt < n && l <= r) {
            cout << "? " << l << " " << nxt << "\n";
            cout.flush();
            int res; cin >> res;
            if(res == 0) {
                par[nxt] = l;
                l++;
                r = nxt;
                nxt++;
            } else{
                l++;
            }
        }
        cout << "! ";
        for(int i = 1; i < n; i++) {
            cout << par[i] << " ";
        }
        cout << "\n";
        cout.flush();
    }
}