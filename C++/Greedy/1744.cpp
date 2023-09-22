#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    vector<int> positive;
    vector<int> negative;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp > 0)
            positive.push_back(temp);
        else
            negative.push_back(temp);
    }
    sort(positive.begin(), positive.end(), greater<int>());
    sort(negative.begin(), negative.end());

    int ans = 0;
    for (int i = 0; i < negative.size(); i += 2) {
        if (i + 1 < negative.size()) {
            ans += negative[i] * negative[i + 1];
        } else {
            ans += negative[i];
        }
    }
    for (int i = 0; i < positive.size(); i += 2) {
        if (i + 1 < positive.size()) {
            if (positive[i + 1] == 1) {
                ans += positive[i] + positive[i + 1];
            } else {
                ans += positive[i] * positive[i + 1];
            }
        } else
            ans += positive[i];
    }
    cout << ans << "\n";
}