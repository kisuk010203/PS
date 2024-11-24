#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long, long> pll;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int n, a, b; cin >> n >> a >> b;
        string s; cin >> s;
        bool flag = true;
        int x = 0, y = 0;
        for(int i = 0; i < 40 * s.size(); i++) {
            char idx = s[i % s.size()];
            if(idx== 'N') y++;
            else if(idx == 'S') y--;
            else if(idx == 'E') x++;
            else x--;
            if(x == a && y == b) {
                cout << "YES\n";
                flag  = false;
                break;
            }
        }
        if (flag)   cout << "NO\n";
    }
}