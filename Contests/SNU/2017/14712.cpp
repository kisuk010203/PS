#include <bits/stdc++.h>
using namespace std;
#define MAX 25
bool board[MAX][MAX];
int dx[3] = {-1, -1, 0};
int dy[3] = {-1, 0, -1};
int cnt;
int n, m;
bool falsy(int r, int c) {
    for (int i = 0; i < 3; i++) {
        int newr = r + dx[i];
        int newc = c + dy[i];
        if (newr < 0 || newc < 0 || !board[newr][newc])
            return true;
    }
    return false;
}
void dfs(int idx) {
    if (idx >= n * m) {
        cnt++;
        return;
    }
    int r = idx / n;
    int c = idx % n;

    board[r][c] = false;
    dfs(idx + 1);
    if (falsy(r, c)) {
        board[r][c] = true;
        dfs(idx + 1);
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cnt = 0;
    dfs(0);
    cout << cnt << "\n";
}
