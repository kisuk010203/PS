#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int n, q; cin >> n >> q;
        vector<int> v(n), vm(n), kol(n);
        for(int i = 0; i < n; i++) {
            int temp; cin >> temp;
            temp--;
            v[i] = temp;
            vm[temp] = i;
        }
        string s; cin >> s;
        for(int i = 0; i < n; i++) {
            kol[min(vm[i], i)]++;
            kol[max(vm[i], i)]--;
        }
        for(int i = 1; i < n; i++) kol[i] += kol[i - 1];
        set<int> ss;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == 'L' && s[i+1] == 'R' && kol[i] != 0) ss.insert(i);
        }
        while(q--) {
            int i; cin >> i; i--;
            s[i] = (s[i] == 'L') ? 'R' : 'L';
            if(i > 0 && s[i-1] == 'L' && s[i] == 'R' && kol[i - 1] != 0) {
                ss.insert(i - 1);
            } else ss.erase(i - 1);
            if(i < n - 1 && s[i] == 'L' && s[i+1] == 'R' && kol[i] != 0) {
                ss.insert(i);
            } else ss.erase(i);
            cout << (ss.empty() ? "YES" : "NO") << "\n";
        }
    }
}