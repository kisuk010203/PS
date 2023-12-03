#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int prev_left = 2, prev_right = 2;
    int fun = 0;
    for (int i = 0; i < T; i++) {
        int curr_left, curr_right;
        cin >> curr_left >> curr_right;
        if (curr_left == curr_right && curr_left != 0)
            fun++;
        if (curr_left == prev_left && curr_left != 0)
            fun++;
        if (curr_right == prev_right && curr_right != 0)
            fun++;
        prev_left = curr_left;
        prev_right = curr_right;
    }
    cout << fun;
}
