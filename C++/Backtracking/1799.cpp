#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int board[10][10];
int n;
int ans;
int ditto;
p bishop[100];
int valid(int r, int c, int cnt) {
    if (!board[r][c])
        return 0;
    for (int i = 1; i <= cnt; i++) {
        int temp_r = bishop[i].first, temp_c = bishop[i].second;
        if ((r + c == temp_r + temp_c) || (r - c == temp_r - temp_c))
            return 0;
    }
    return 1;
}
p next_idx(p idx) {
    int r = idx.first, c = idx.second;
    if (c < n - 2)
        return make_pair(r, c + 2);
    else if (r < n - 1)
        return make_pair(r + 1, (c + 1) % 2);
    else
        return make_pair(-1, -1);
}
void backtracking(int r, int c, int cnt) {
    if (cnt == 0) {
        int flag = 1;
        for (p idx = make_pair(r, c); idx.first >= 0; idx = next_idx(idx)) {
            if (valid(idx.first, idx.second, cnt)) {
                bishop[1] = idx;
                flag = 0;
                backtracking(idx.first, idx.second, cnt + 1);
            }
        }
        if (flag)
            ans = max(ans, cnt);
    } else {
        int flag = 1;
        for (p idx = next_idx(make_pair(r, c)); idx.first >= 0;
             idx = next_idx(idx)) {
            if (valid(idx.first, idx.second, cnt)) {
                bishop[cnt + 1] = idx;
                flag = 0;
                backtracking(idx.first, idx.second, cnt + 1);
            }
        }
        if (flag)
            ans = max(ans, cnt);
    }
}
int main() {
    cin >> n;
    int r_ans = 0;
    memset(board, 0, sizeof(board));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    backtracking(0, 0, 0);
    r_ans += ans;
    ans = 0;
    backtracking(0, 1, 0);
    r_ans += ans;
    cout << r_ans;
}
