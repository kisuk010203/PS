#include <bits/stdc++.h>
using namespace std;
int n;
set<int> possible;
int pends[13];
void insert_possible(int idx, int left_sum, int right_sum) {
    if (idx == n) {
        possible.insert(abs(left_sum - right_sum));
        return;
    }
    insert_possible(idx + 1, left_sum, right_sum);
    insert_possible(idx + 1, left_sum, right_sum + pends[idx]);
    insert_possible(idx + 1, left_sum + pends[idx], right_sum);
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> pends[i];
        max_sum += pends[i];
    }
    insert_possible(0, 0, 0);
    cout << max_sum + 1 - possible.size();
}
