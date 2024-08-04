#include <bits/stdc++.h>
using namespace std;
void compute_z_values(string target, vector<int> &z_values) {
    int n = target.size();
    z_values.resize(n);
    z_values[0] = n;
    int l = 0, r = 0;
    for (int k = 1; k < n; k++) {
        if (k > r) {
            l = r = k;
            while (r < n && target[r - l] == target[r])
                r++;
            z_values[k] = r - l;
            r--;
        } else {
            int k1 = k - l;
            if (z_values[k1] < r - k + 1)
                z_values[k] = z_values[k1];
            else {
                l = k;
                while (r < n && target[r - l] == target[r])
                    r++;
                z_values[k] = r - l;
                r--;
            }
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
        int n, l, r;
        cin >> n >> l >> r;
        string base_string;
        cin >> base_string;
        vector<int> z_values;
        compute_z_values(base_string, z_values);
        int left = 1, right = n;
        while (left <= right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(z_values[i] >= mid) {
                    cnt++;
                    i += mid - 1;
                }
            }
            if(cnt >= l) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << left - 1 << "\n";
    }
}