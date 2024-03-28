#include <bits/stdc++.h>
using namespace std;
int board[10][10];
int turnon[10][10];
int x_diff[5] = {-1, 0, 0, 0, 1};
int y_diff[5] = {0, -1, 0, 1, 0};
int inbound(int x, int y) {
    return ((x > -1 && x < 10) && (y > -1 && y < 10));
}
int main() {
    int ans[(1 << 10)];
    int res = 500;
    int temp[10][10] = {0};
    for (int i = 0; i < 10; i++) {
        char temps[10];
        scanf("%s", temps);
        for (int j = 0; j < 10; j++)
            board[i][j] = (temps[j] == '#') ? 0 : 1;
    }
    for (int i = 0; i < (1 << 10); i++) {
        for (int x = 0; x < 10; x++)
            for (int j = 0; j < 10; j++)
                temp[x][j] = board[x][j];
        ans[i] = 0;
        for (int j = 0; j < 10; j++) {
            if (i & (1 << j)) {
                turnon[0][j] = 1;
                for (int k = 0; k < 5; k++) {
                    if (inbound(x_diff[k], j + y_diff[k]))
                        temp[x_diff[k]][j + y_diff[k]] =
                            1 - temp[x_diff[k]][j + y_diff[k]];
                }
                ans[i]++;
            } else
                turnon[0][j] = 0;
        }
        for (int x = 1; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                if (temp[x - 1][y]) {
                    turnon[x][y] = 1;
                    for (int k = 0; k < 5; k++) {
                        if (inbound(x + x_diff[k], y + y_diff[k]))
                            temp[x + x_diff[k]][y + y_diff[k]] =
                                1 - temp[x + x_diff[k]][y + y_diff[k]];
                    }
                    ans[i]++;
                }
            }
        }
        bool flag = true;
        for (int j = 0; j < 10; j++)
            if (temp[9][j])
                flag = false;
        if (flag)
            res = min(res, ans[i]);
    }
    if (res == 500)
        res = -1;
    cout << res;
}
