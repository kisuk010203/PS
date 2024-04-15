#include <bits/stdc++.h>
using namespace std;
int arr[200005];
int n;
bool check() {
    arr[n] = arr[0];
    arr[n + 1] = arr[1];
    arr[n + 2] = arr[2];
    for (int i = 0; i < n; i++) {
        if (arr[i] && arr[i + 1] && arr[i + 2] && arr[i + 3])
            return true;
    }
    return false;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        if (n <= 2) {
            bool flag = true;
            while (flag) {
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    cnt += (int)(arr[i] != 0);
                    arr[(i + 1) % n] = max(0, arr[(i + 1) % n] - arr[i]);
                }
                flag = cnt > 1;
            }
            vector<int> alive;
            for (int i = 0; i < n; i++) {
                if (arr[i] != 0) {
                    alive.push_back(i);
                }
            }
            cout << alive.size() << "\n";
            for (auto item : alive) {
                cout << item + 1 << " ";
            }
            cout << "\n";
            continue;
        } else if (n == 3) {
            int cnt = 3;
            while (cnt == 3) {
                cnt = 0;
                for (int i = 0; i < n; i++) {
                    cnt += (int)(arr[i] != 0);
                    arr[(i + 1) % n] = max(0, arr[(i + 1) % n] - arr[i]);
                }
            }

            if (cnt <= 1) {
                vector<int> alive;
                for (int i = 0; i < n; i++) {
                    if (arr[i] != 0) {
                        alive.push_back(i);
                    }
                }
                cout << alive.size() << "\n";
                for (auto item : alive) {
                    cout << item + 1 << " ";
                }
                cout << "\n";
                continue;
            } else { // cnt == 2
                int dead = 3;
                for (int i = 0; i < n; i++) {
                    if (arr[i] != 0) {
                        dead -= i;
                    }
                }
                cout << "1\n";
                cout << (dead + 1) % 3 + 1 << "\n";
                continue;
            }
        }

        while (check()) {
            for (int curr = 0; curr < n; curr++) {
                arr[(curr + 1) % n] = max(0, arr[(curr + 1) % n] - arr[curr]);
            }
        }
        // cout << "Test :  " << t << "\n";
        // for(int i=0; i<n; i++){
        //     cout << arr[i] << " ";
        // }cout << "\n";

        vector<int> alive;
        int start = 0;
        while (arr[start] != 0) {
            arr[((start + 1) % n)] = max(0, arr[(start + 1) % n] - arr[start]);
            start++;
        }
        for (int idx = start; idx < n + start;) {
            // cout << "Checking ... " << idx << "\n";
            if (arr[idx % n] == 0) {
                idx++;
                continue;
            }
            alive.push_back(idx % n);
            if (arr[(idx + 2) % n] != 0 && arr[(idx + 1) % n] != 0) {
                long long x = arr[(idx % n)], y = arr[(idx + 1) % n],
                          z = arr[(idx + 2) % n];
                long long x_hits_y = y / x;
                long long y_hits_z =
                    y * (x_hits_y)-x * (x_hits_y + 1) * (x_hits_y) / 2;
                bool z_lives = (z > y_hits_z);
                if (z_lives && idx + 2 < n + start)
                    alive.push_back((idx + 2) % n);
                idx += 3;
            } else
                idx += 2;
        }
        cout << alive.size() << "\n";
        int end_idx = alive.size() - 1;
        while (end_idx > 0 && alive[end_idx] < alive[0]) {
            end_idx--;
        }
        for (int i = end_idx + 1; i < alive.size(); i++)
            cout << alive[i] + 1 << " ";
        for (int i = 0; i <= end_idx; i++)
            cout << alive[i] + 1 << " ";
        cout << "\n";
    }
}