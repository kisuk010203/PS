#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    vector<int> diff;
    bool is_last_brown = s[n - 1] == 'B';
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            diff.push_back(i + 1);
        }
    }
    int diff_size = diff.size();
    if (diff_size == 0) {
        if (is_last_brown) {
            cout << -1 << '\n';
        } else
            cout << 0 << '\n';
    } else if (diff_size == 1) {
        if (is_last_brown) {
            cout << -1 << '\n';
        } else {
            cout << "1\n" << diff[0] << '\n';
        }
    } else {
        cout << diff_size << '\n';
        if (is_last_brown) {
            cout << diff[diff_size - 1] << "\n";
            for (int i = 0; i < diff_size - 1; i++) {
                cout << diff[i] << "\n";
            }
        } else {
            for (auto d : diff) {
                cout << d << "\n";
            }
        }
    }
}