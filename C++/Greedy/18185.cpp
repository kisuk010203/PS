#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
int counts[MAX + 3];
int ans = 0;
void delete_sevens(int idx) {
    int sevens = min(counts[idx], min(counts[idx + 1], counts[idx + 2]));
    ans += 7 * sevens;
    for (int j = 0; j < 3; j++) {
        counts[idx + j] -= sevens;
    }
}
void delete_fives(int idx, int amount) {
    int fives = min(counts[idx], amount);
    ans += 5 * fives;
    counts[idx] -= fives;
    counts[idx + 1] -= fives;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    memset(counts, 0, sizeof(counts));
    for (int i = 0; i < n; i++) {
        cin >> counts[i];
    }
    for (int i = 0; i < n; i++) {
        if (counts[i + 1] > counts[i + 2]) {
            delete_fives(i, counts[i + 1] - counts[i + 2]);
            delete_sevens(i);
        } else {
            delete_sevens(i);
            delete_fives(i, counts[i + 1]);
        }
        ans += 3 * counts[i];
    }
    cout << ans << endl;
}
