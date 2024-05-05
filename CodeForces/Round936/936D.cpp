#include <bits/stdc++.h>
using namespace std;
int n, x, ans;
int decrease(int idx, vector<int> &v, bool end);
int solve(int idx, vector<int> &v);
int decrease(int idx, vector<int> &v, bool end) {
    int curr = 0;
    bool inside_interval = false;
    vector<int> new_v;
    for (int i = 0; i < v.size(); i++) {
        curr ^= v[i];
        if ((v[i] >> idx) & 1) {
            if (inside_interval) {
                inside_interval = false;
                new_v.push_back(curr);
                curr = 0;
            } else
                inside_interval = true;
        } else {
            if(!inside_interval) {
                new_v.push_back(curr);
                curr = 0;
            }
        }
    }
    if (end)
        return new_v.size();
    else
        return solve(idx - 1, new_v);
}
int solve(int idx, vector<int> &v) {
    if (idx < 0)
        return v.size();
    int xor_result = 0;
    for (int i = 0; i < v.size(); i++) {
        xor_result ^= ((v[i] >> idx) & 1);
    }
    if (x & (1 << idx)) {
        if (xor_result == 0) {
            return max(decrease(idx, v, true), solve(idx - 1, v));
        } else {
            return solve(idx - 1, v);
        }
    } else {
        if (xor_result == 0) {
            return decrease(idx, v, false);
        } else {
            return -1;
        }
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> x;
        vector<int> v(n);
        ans = -1;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int res = solve(30, v);
        cout << res << "\n";
    }
}
