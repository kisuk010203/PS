#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    queue<int> que;
    vector<int> ans;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        que.push(i + 1);
    }
    while (!que.empty()) {
        for (int i = 0; i < k - 1; i++) {
            que.push(que.front());
            que.pop();
        }
        ans.push_back(que.front());
        que.pop();
    }
    cout << "<";
    for (int i = 0; i < n; i++) {
        if (i != n - 1)
            cout << ans[i] << ", ";
        else
            cout << ans[i] << ">";
    }
}
