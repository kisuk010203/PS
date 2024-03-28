#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> vec(n);
    for (ll i = 0; i < n; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    ll ans_left = 0, ans_right = n - 1, ans = 2e9;
    ll left = 0, right = n - 1;
    while (left != right) {
        if (abs(vec[left] + vec[right]) < abs(ans)) {
            ans = vec[left] + vec[right];
            ans_left = left;
            ans_right = right;
        }
        if (vec[left] + vec[right] < 0) {
            left++;
        } else if (vec[left] + vec[right] > 0) {
            right--;
        } else {
            break;
        }
    }
    cout << vec[ans_left] << " " << vec[ans_right] << "\n";
}