#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    int zero_cnt = 0, one_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j])
                one_cnt++;
            else
                zero_cnt++;
        }
    }

    if (one_cnt % 2 || zero_cnt % 2) {
        cout << -1;
        return 0;
    }
}
