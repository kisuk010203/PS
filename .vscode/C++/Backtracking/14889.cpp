#include <bits/stdc++.h>
using namespace std;
#define MAX 20
int n, min_res;
int arr[MAX][MAX];
int back_seq[MAX / 2];
bool in_backSeq(int key) {
    for (int i = 0; i < n / 2; i++) {
        if (back_seq[i] == key)
            return true;
    }
    return false;
}
void backtracking(int count) {
    if (count == n / 2) {
        int ans = 0;
        bool in[MAX];
        for (int i = 0; i < n; i++) {
            in[i] = in_backSeq(i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (in[i] && in[j])
                    ans += arr[i][j];
                else if (in[i] || in[j])
                    continue;
                else
                    ans -= arr[i][j];
            }
        }
        ans = abs(ans);
        min_res = min(min_res, ans);
    } else if (count == 0) {
        back_seq[0] = 0;
        backtracking(1);
    } else {
        for (int i = back_seq[count - 1] + 1; i <= n / 2 + count; i++) {
            back_seq[count] = i;
            backtracking(count + 1);
        }
    }
}
int main(int argc, char const *argv[]) {
    memset(arr, 0, sizeof(arr));
    memset(back_seq, 0, sizeof(back_seq));
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    min_res = 1e9;
    backtracking(0);
    cout << min_res;
    return 0;
}
