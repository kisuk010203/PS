#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> odds;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp % 2 == 0)
            ans += temp;
        else {
            odds.push_back(temp);
        }
    }
    sort(odds.begin(), odds.end());
    int start = 0;
    if (odds.size() % 2 == 1) {
        start = 1;
    }
    for (; start < odds.size(); start++) {
        ans += odds[start];
    }
    cout << ans << "\n";
}
