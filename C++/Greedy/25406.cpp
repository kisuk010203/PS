#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for(int i = a; i < b; i++)
#define each(a, b) for(auto& a : b)
typedef pair<ll, ll> pll;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    each(x, a) cin >> x;
    vector<int> ans;
    vector<queue<int>> q(n);
    set<pair<int, int>> cnt_set;
    set<int> idx_set;
    set<pair<int, int>> q_front_set;
    rep(i, 0, n) q[a[i] - 1].push(i);
    rep(i, 0, n) {
        if(!q[i].empty()) cnt_set.insert({q[i].size(), i});
        if(!q[i].empty()) q_front_set.insert({q[i].front(), i});
    }
    rep(i, 0, n) {
        auto it = cnt_set.rbegin();
        if(it->first  > (n + 1) / 2) {
            cout << "-1\n";
            return 0;
        }
        int left_n = n - i;
        if(left_n % 2 == 1 && it->first == (left_n + 1) / 2) {
            int targ = it->second;
            int idx = q[targ].front();
            q[targ].pop();
            cnt_set.erase({q[targ].size() + 1, targ});
            q_front_set.erase({idx, targ});
            if(!q[targ].empty()) cnt_set.insert({q[targ].size(), targ});
            if(!q[targ].empty()) q_front_set.insert({q[targ].front(), targ});
            ans.push_back(idx);
        } else {
            auto it = q_front_set.begin();
            int idx = it->first;
            int targ = it->second;
            if(!ans.empty() && a[idx] == a[ans.back()]) {
                it = next(it);
                idx = it->first;
                targ = it->second;
            }
            q[targ].pop();
            cnt_set.erase({q[targ].size() + 1, targ});
            q_front_set.erase({idx, targ});
            if(!q[targ].empty()) cnt_set.insert({q[targ].size(), targ});
            if(!q[targ].empty()) q_front_set.insert({q[targ].front(), targ});
            ans.push_back(idx);
        }
    }
    each(x, ans) cout << x + 1 << ' ';
}