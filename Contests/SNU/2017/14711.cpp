#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
int n;
bool board[MAX][MAX];
int dx[4] = {0, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
bool is_possible(int r, int c) { return r >= 0 && c >= 0 && r < n && c < n; }
bool get_all_sum(int r, int c) {
    bool cnt = board[r][c];
    for (int i = 0; i < 4; i++) {
        int newr = r + dx[i];
        int newc = c + dy[i];
        if (is_possible(newr, newc) && board[newr][newc])
            cnt = !cnt;
    }
    return cnt;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    string temp;
    cin >> temp;
    for (int i = 0; i < n; i++) {
        board[0][i] = (temp[i] == '#');
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = get_all_sum(i - 1, j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] ? '#' : '.');
        }
        cout << "\n";
    }
}
