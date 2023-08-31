#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll accum[1025][1025];
int main(int argc, char const *argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    memset(accum, 0, sizeof(accum));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ll temp;
            cin >> temp;
            accum[i][j] =
                accum[i - 1][j] + accum[i][j - 1] - accum[i - 1][j - 1] + temp;
        }
    }
    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll ret = accum[x2][y2] - accum[x1 - 1][y2] - accum[x2][y1 - 1] +
                 accum[x1 - 1][y1 - 1];
        cout << ret << "\n";
    }
    return 0;
}
