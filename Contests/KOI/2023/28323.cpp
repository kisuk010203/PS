#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int cnt = 0, curr = -1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (cnt == 0) {
            cnt++;
            curr = temp % 2;
        } else if (temp % 2 != curr) {
            cnt++;
            curr = 1 - curr;
        }
    }
    cout << cnt;
}
