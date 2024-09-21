#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, cnt;
// state : lambda = 0, y = 1
int dx[6] = {0, -1, 1, 0, 1, -1};
int dy[6] = {2, -1, -1, -2, 1, 1};
bool searched[100][100];
void solve(int len, int x, int y, int last_x, int last_y, int state) {
    if (len == n) {
        // cout << x << " " << y << "\n";
        if (searched[50 + x][50 + y])
            cnt++;
        return;
    }
    if (searched[50 + x][50 + y])
        return;
    searched[50 + x][50 + y] = true;
    for (int i = 0; i < 3; i++) {
        if (x + dx[3 * state + i] != last_x || y + dy[3 * state + i] != last_y)
            solve(len + 1, x + dx[3 * state + i], y + dy[3 * state + i], x, y,
                  1 - state);
    }
    searched[50 + x][50 + y] = false;
}
int main() {
    cin >> n;
    memset(searched, false, sizeof(searched));
    searched[50][50] = true;
    solve(0, 0, 2, 0, 0, 1);
    cout << cnt << "\n";
}