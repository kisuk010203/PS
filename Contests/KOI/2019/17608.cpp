#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> rods;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        rods.push_back(temp);
    }
    int curr_max = 0;
    int ans = 0;
    while (!rods.empty()) {
        int rightmost = rods.back();
        if (rightmost > curr_max) {
            ans++;
            curr_max = rightmost;
        }
        rods.pop_back();
    }
    cout << ans << "\n";
}
