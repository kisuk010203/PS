#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii; // first : 효능, second: 원소
pii ingr[10][4][4];
pii board[5][5];

void update(int row, int col, int ingr_row, int ingr_col, int idx) {
    int rate = ingr[idx][ingr_row][ingr_col].first;
    int color = ingr[idx][ingr_row][ingr_col].second;
    board[row][col].first += rate;
    board[row][col].first = max(board[row][col].first, 0);
    board[row][col].first = min(board[row][col].first, 9);
    board[row][col].second = (color ? color : board[row][col].second);
}
void add_ingredient(int row_col, int mode, int idx) {
    int row = row_col >> 1;
    int col = row_col & 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (mode == 0)
                update(row + i, col + j, i, j, idx);
            else if (mode == 1)
                update(row + i, col + j, 3 - j, i, idx);
            else if (mode == 2)
                update(row + i, col + j, 3 - i, 3 - j, idx);
            else if (mode == 3)
                update(row + i, col + j, j, 3 - i, idx);
        }
    }
}
int get_sum() {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            sum += board[i][j].first * board[i][j].second;
            board[i][j].first = 0;
            board[i][j].second = 0;
        }
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unordered_map<char, int> char2int;
    char2int['R'] = 7;
    char2int['B'] = 5;
    char2int['G'] = 3;
    char2int['Y'] = 2;
    char2int['W'] = 0;
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                cin >> ingr[i][j][k].first;
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++) {
                char item;
                cin >> item;
                ingr[i][j][k].second = char2int[item];
            }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            for (int k = 0; k < n; k++) {
                if (i == k || j == k)
                    continue;
                for (int row_col_mode_i = 0; row_col_mode_i < 16;
                     row_col_mode_i++)
                    for (int row_col_mode_j = 0; row_col_mode_j < 16;
                         row_col_mode_j++)
                        for (int row_col_mode_k = 0; row_col_mode_k < 16;
                             row_col_mode_k++) {
                            add_ingredient(row_col_mode_i >> 2,
                                           row_col_mode_i & 3, i);
                            add_ingredient(row_col_mode_j >> 2,
                                           row_col_mode_j & 3, j);
                            add_ingredient(row_col_mode_k >> 2,
                                           row_col_mode_k & 3, k);
                            ans = max(ans, get_sum());
                        }
            }
        }
    }
    cout << ans;
}