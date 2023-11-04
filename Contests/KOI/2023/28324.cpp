#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> points;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        points.push_back(temp);
    }

    int currSpeed = 0;
    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int speedLimit = points[i];
        currSpeed = min(currSpeed + 1, speedLimit);
        ans += currSpeed;
    }
    cout << ans << "\n";
}
