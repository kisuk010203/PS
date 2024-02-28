#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    ll ans = vec[0] + vec[1] + vec[2];
    ll ans_left = vec[0], ans_right = vec[1], ans_target = vec[2];
    for (int i = 0; i < n; i++) {
        ll left = 0, right = n - 1;
        ll target = vec[i];
        while (left != right) {
            if (left == i) {
                left++;
                continue;
            } else if (right == i) {
                right--;
                continue;
            }
            if (abs(vec[left] + vec[right] + target) < abs(ans)) {
                ans_left = vec[left];
                ans_right = vec[right];
                ans_target = target;
                ans = vec[left] + vec[right] + target;
            }
            if (vec[left] + vec[right] + target < 0) {
                left++;
            } else if (vec[left] + vec[right] + target > 0) {
                right--;
            } else {
                break;
            }
        }
    }
    vector<ll> ans_vec = {ans_target, ans_left, ans_right};
    sort(ans_vec.begin(), ans_vec.end());
    for (auto i : ans_vec) {
        cout << i << " ";
    }
    cout << "\n";
}