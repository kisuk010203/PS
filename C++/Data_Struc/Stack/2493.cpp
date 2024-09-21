#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;

    cin >> n;
    vector<pii> height(n + 1);
    vector<int> ans(n + 1, 0);
    stack<pii> towers;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        height[i + 1] = {i + 1, temp};
    }

    for (int i = n; i > 0; i--) {
        while (!towers.empty() && towers.top().second <= height[i].second) {
            ans[towers.top().first] = i;
            towers.pop();
        }
        towers.push(height[i]);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}