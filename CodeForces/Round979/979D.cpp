#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define NMAX 200000
ll arr[NMAX];
pll seg[4 * NMAX]; // minmax
pll init(int node, int left, int right) {
    if(left == right) return seg[node] = {arr[left] - 1, arr[left] - 1};
    int mid = (left + right) / 2;
    pll left_minmax = init(node * 2, left, mid);
    pll right_minmax = init(node * 2 + 1, mid + 1, right);
    return seg[node] = {
        min(left_minmax.first, right_minmax.first),
        max(left_minmax.second, right_minmax.second)  
    };
}
pll query(int node, int left, int right, int qleft, int qright) {
    if(qright < left || qleft > right) return {NMAX * 2, - NMAX * 2};
    if(qleft <= left && right <= qright) return seg[node];
    int mid = (left + right) / 2;
    pll left_minmax = query(node * 2, left, mid, qleft, qright);
    pll right_minmax = query(node * 2 + 1, mid + 1, right, qleft, qright);
    return {
        min(left_minmax.first, right_minmax.first),
        max(left_minmax.second, right_minmax.second)
    };
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int n, q; cin >> n >> q;
        for(int i = 0; i < n; i++) cin >> arr[i];
        string s; cin >> s;
        init(1, 0, n - 1);
        map<int, bool> mp;
        int false_cnt = 0;
        int st = -1;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == 'L' && s[i + 1] == 'R') {
                pll res = query(1, 0, n - 1, st + 1, i);
                mp[i] = (res.second == i && res.first == st + 1);
                st = i;
            }
        }
        pll res = query(1, 0, n - 1, st + 1, n - 1);
        mp[n - 1] = (res.second == n - 1 && res.first == st + 1);
        mp[-1] = false;
        while(q--) {
            for(auto item : mp) {
                cout << item.first << ": " << item.second << " ";
            } 
            int ch; cin >> ch;
            ch--;
            if(ch!=0 && s[ch - 1] == 'L' && s[ch] == 'L') { // LL->LR
            cout << "CASE1" << "\n";
                auto nxt = mp.upper_bound(ch);
                auto prv = prev(nxt);
                if(prv == mp.end()) {
                    pll res = query(1, 0, n - 1, 0, ch);
                    mp[ch] = (res.second == ch && res.first == 0);
                } else {
                    pll res = query(1, 0, n - 1, prv->first + 1, ch);
                    mp[ch] = (res.second == ch && res.first == prv->first + 1);

                }
                pll res = query(1, 0, n - 1, ch + 1, nxt->first);
                if(!mp[nxt->first]) false_cnt--;
                mp[nxt->first] = (res.second == nxt->first && res.first == ch + 1);
                if(!mp[nxt->first]) false_cnt++;
                if(!mp[ch]) false_cnt++;
            }
            else if(ch!=0 && s[ch - 1] == 'L' && s[ch] == 'R') { // LR->LL
            cout << "CASE2" << "\n";
                auto nxt = mp.upper_bound(ch);
                auto prv = prev(nxt);
                if(prv == mp.end()) {
                    pll res = query(1, 0, n - 1, 0, nxt->first);
                    if(!mp[nxt->first]) false_cnt--;
                    mp[nxt->first] = (res.second == nxt->first && res.first == 0);
                    if(!mp[nxt->first]) false_cnt++;
                } else {
                    pll res = query(1, 0, n - 1, prv->first + 1, nxt->first);
                    if(!mp[nxt->first]) false_cnt--;
                    mp[nxt->first] = (res.second == nxt->first && res.first == prv->first + 1);
                    if(!mp[nxt->first]) false_cnt++;
                }
                if(!mp[ch]) false_cnt--;
                mp.erase(ch);
            }
            
            else if(s[ch] == 'R' && s[ch + 1] == 'R') {// RR->LR 
            cout << "CASE3" << "\n";
                auto nxt = mp.upper_bound(ch);
                auto prv = prev(nxt);
                if(prv == mp.end()) {
                    pll res = query(1, 0, n - 1, 0, ch);
                    mp[ch] = (res.second == ch && res.first == 0);

                } else {
                    pll res = query(1, 0, n - 1, prv->first + 1, ch);
                    mp[ch] = (res.second == ch && res.first == prv->first + 1);

                }
                pll res = query(1, 0, n - 1, ch + 1, nxt->first);
                if(!mp[nxt->first]) false_cnt--;
                mp[nxt->first] = (res.second == nxt->first && res.first == ch + 1);
                if(!mp[nxt->first]) false_cnt++;
                if(!mp[ch]) false_cnt++;
            }
            else if(s[ch] == 'L' && s[ch + 1] == 'R') { // LR->RR
            cout << "CASE4" << "\n";
                for(auto item : mp) {
                    cout << item.first << ": " << item.second << " ";
                }
                cout << ch << " ";
                auto nxt = mp.upper_bound(1);
                auto prv = prev(nxt);
                auto dprv = prev(prv);
                cout << ch << nxt->first <<nxt->second;
                cout << prv->first << prv->second;
                if(prv == mp.end()) {
                    pll res = query(1, 0, n - 1, 0, nxt->first) ;
                    if(!mp[nxt->first]) false_cnt--;
                    mp[nxt->first] = (res.second == nxt->first && res.first == 0);
                    if(!mp[nxt->first]) false_cnt++;

                } else {
                    cout <<"HERE";
                    pll res = query(1, 0, n - 1, dprv->first + 1, nxt->first);
                    if(!mp[nxt->first]) false_cnt--;
                    mp[nxt->first] = (res.second == nxt->first && res.first == dprv->first + 1);
                    if(!mp[nxt->first]) false_cnt++;
                }
                if(!mp[ch]) false_cnt--;
                mp.erase(ch);
            }

            if(false_cnt == 0) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}