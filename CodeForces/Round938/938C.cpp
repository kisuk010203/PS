#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        // cout << "Test case : " << T << "\n";
        ll n, k;
        cin >> n >> k;
        vector<ll> dur(n);
        for (int i = 0; i < n; i++) {
            cin >> dur[i];
        }
        int left_ptr = 0, right_ptr = n - 1;
        while (left_ptr < right_ptr && k > 0) {
            // cout << "Current k : " << k << "\n";
            // cout << "Left pointer : " << left_ptr << " Right pointer : " <<
            // right_ptr << "\n";
            if (dur[left_ptr] <= ((k + 1) >> 1) && dur[right_ptr] <= (k >> 1)) {
                // cout << "Both smaller than k/2\n";
                if (dur[left_ptr] < dur[right_ptr]) {
                    k -= (dur[left_ptr] << 1);
                    dur[right_ptr] -= dur[left_ptr];
                    left_ptr++;
                } else if (dur[left_ptr] > dur[right_ptr]) {
                    k -= (dur[right_ptr] << 1);
                    dur[left_ptr] -= dur[right_ptr];
                    right_ptr--;
                } else {
                    k -= (dur[left_ptr] << 1);
                    left_ptr++;
                    right_ptr--;
                }
            } else if (dur[left_ptr] <= ((k + 1) >> 1)) {
                // cout << "Left smaller than k/2\n";
                k -= (dur[left_ptr] << 1);
                dur[right_ptr] -= (dur[left_ptr]);
                left_ptr++;
            } else if (dur[right_ptr] <= (k >> 1)) {
                // cout << "Right smaller than k/2\n";
                k -= (dur[right_ptr] << 1);
                dur[left_ptr] -= dur[right_ptr];
                right_ptr--;
            } else {
                // cout << "Both greater than k/2\n";
                k = 0;
            }
        }
        if (left_ptr == right_ptr && k > 0) {
            dur[left_ptr] -= k;
            if (dur[left_ptr] <= 0)
                left_ptr++;
        }

        cout << n - max(0, right_ptr - left_ptr + 1) << "\n";
    }
}