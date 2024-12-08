#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> ver;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        vector<ver> v(N);
        vector<vector<int>> adj(N);
        vector<bool> searched(N);
        for(int i = 0; i < N ; i++) {
            ll x, y, r; cin >> x >> y >> r;
            v[i] = {{x, y}, r};
        }
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                ll x1, y1, r1, x2, y2, r2 ;
                x1 = v[i].first.first;
                y1 = v[i].first.second;
                r1 = v[i].second;
                   
                x2 = v[j].first.first;
                y2 = v[j].first.second;
                r2 = v[j].second;

                ll dist_sq = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                ll r_sq = (r1 + r2) * (r1 + r2);
                if (dist_sq <= r_sq) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        fill(searched.begin(), searched.end(), false);
        for(int i = 0; i < N; i++) {
            if(searched[i]) continue;
            vector<int> stk;
            stk.push_back(i);
            while(!stk.empty()) {
                int cur = stk.back();
                stk.pop_back();
                if(searched[cur]) continue;
                searched[cur] = true;
                for(int nxt : adj[cur]) {
                    if(!searched[nxt]) stk.push_back(nxt);
                }
            }
            cnt++;
        }
        cout << cnt << '\n';
        
    }
}