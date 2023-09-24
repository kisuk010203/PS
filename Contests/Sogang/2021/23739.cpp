#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int cnt = 0, remained_time = 30;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp <= remained_time) {
            cnt++;
            remained_time -= temp;
            if (remained_time == 0)
                remained_time += 30;
        } else {
            if (remained_time * 2 >= temp)
                cnt++;
            remained_time = 30;
        }
    }
    cout << cnt;
}
