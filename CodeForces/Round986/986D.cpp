#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long, long> pll;
typedef pair<char, int> pci;
typedef pair<int, int> pii;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vector<int> q(n + 1), k(n + 1), j(n + 1);
        for(int i = 1; i <= n; i++) cin >> q[i]; //[1..n]
        for(int i = 1; i <= n; i++) cin >> k[i]; //[1..n]
        for(int i = 1; i <= n; i++) cin >> j[i]; //[1..n]
        vector<pci> ans(n + 1);
        vector<bool> bool_ans(n + 1, false);

        for(int i = 0; i <= n; i++) ans[i] = {'0', 0};
        ans[n] = {'0', -1};
        bool_ans[n] = true;
        pii min_q = {q[n], n}; // {value, index}
        pii min_k = {k[n], n}; 
        pii min_j = {j[n], n};

        for(int i = n - 1; i >= 0; i--) {
            if(q[i] > min_q.first) {
                ans[i] = {'q', min_q.second};
                bool_ans[i] = true;
                if(k[i] < min_k.first) min_k = {k[i], i};
                if(j[i] < min_j.first) min_j = {j[i], i};
            } else if(k[i] > min_k.first) {
                ans[i] = {'k', min_k.second};
                bool_ans[i] = true;
                if(q[i] < min_q.first) min_q = {q[i], i};
                if(j[i] < min_j.first) min_j = {j[i], i};
            } else if(j[i] > min_j.first) {
                ans[i] = {'j', min_j.second};
                bool_ans[i] = true;
                if(q[i] < min_q.first) min_q = {q[i], i};
                if(k[i] < min_k.first) min_k = {k[i], i};
            } 
        }
        if(bool_ans[1]) {
            cout << "YES\n";
            vector<pci> res;
            int st = 1;
            while(st != n) {
                res.push_back(ans[st]);
                st = ans[st].second;
            }
            cout << res.size() << "\n";
            for(auto i : res) {
                cout << i.first << " " << i.second << "\n";
            }
        } else {
            cout << "NO\n";
        }
    }
}