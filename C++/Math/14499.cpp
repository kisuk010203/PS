#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int dice[6];
int board[20][20];
int dice_x, dice_y;
bool is_valid(int move) {
    int new_x = dice_x + dx[move];
    int new_y = dice_y + dy[move];
    return new_x >= 0 && new_x < n && new_y >= 0 && new_y < m;
}
void move_east() {
    int temp = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[5];
    dice[5] = dice[2];
    dice[2] = temp;
}
void move_west() {
    move_east();
    move_east();
    move_east();
}
void move_south() {
    int temp = dice[5];
    dice[5] = dice[4];
    dice[4] = dice[0];
    dice[0] = dice[1];
    dice[1] = temp;
}
void move_north() {
    move_south();
    move_south();
    move_south();
}
void copy_board() {
    if (board[dice_x][dice_y] == 0) {
        board[dice_x][dice_y] = dice[5];
    } else {
        dice[5] = board[dice_x][dice_y];
        board[dice_x][dice_y] = 0;
    }
}
void move_dice(int move) {
    if (!is_valid(move))
        return;
    switch (move) {
    case 1:
        move_east();
        break;
    case 2:
        move_west();
        break;
    case 3:
        move_north();
        break;
    case 4:
        move_south();
        break;
    default:
        break;
    }
    dice_x += dx[move];
    dice_y += dy[move];

    copy_board();
    cout << dice[0] << "\n";
}

int main(int argc, char const *argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int k;
    cin >> n >> m >> dice_x >> dice_y >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    memset(dice, 0, sizeof(dice));
    while (k--) {
        int move;
        cin >> move;
        move_dice(move);
    }

    return 0;
}
