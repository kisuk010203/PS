#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int sig_len;
int curr_idx;
string sig2;
bool is_white_col(int idx) {
    for (int i = 0; i < 5; i++) {
        if (sig2[idx + sig_len * i] == '#')
            return false;
    }
    return true;
}
int zero_or_six(int start) {
    if (sig2[start + 1 + sig_len * 2] == '#') {
        if (sig2[start + sig_len * 3] == '#')
            return 6;
        return 9;
    }
    return 0;
}
int two_three_five(int start) {
    if (sig2[start + sig_len] == '#')
        return 5;
    if (sig2[start + sig_len * 3] == '#')
        return 2;
    return 3;
}
int get_digit(int start) {
    int cnt = 0;
    while (start + cnt < sig_len && !is_white_col(start + cnt)) {
        cnt++;
    }
    if (cnt == 1) {
        curr_idx += 2;
        return 1;
    }
    curr_idx += 4;
    int black_cnt = 0;
    for (int i = start; i < start + 3; i++) {
        for (int col = 0; col < 5; col++) {
            black_cnt += (int)(sig2[i + sig_len * col] == '#');
        }
    }
    switch (black_cnt) {
        case 13:
            return 8;
        case 7:
            return 7;
        case 9:
            return 4;
        case 12:
            return zero_or_six(start);
        case 11:
            return two_three_five(start);
        default:
            return -1;
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> sig_len;
    cin >> sig2;
    sig_len /= 5;
    curr_idx = 0;
    while (curr_idx < sig_len) {
        if (is_white_col(curr_idx))
            curr_idx++;
        else {
            int res = get_digit(curr_idx);
            cout << res;
        }
    }
}
