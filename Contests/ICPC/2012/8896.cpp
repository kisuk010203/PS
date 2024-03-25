#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<string> robots;
        vector<bool> alive;
        for (int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            robots.push_back(temp);
            alive.push_back(true);
        }
        int k = robots[0].length();
        for (int i = 0; i < k; i++) {
            int r = 0, p = 0, s = 0;
            for (int j = 0; j < n; j++) {
                if (alive[j]) {
                    if (robots[j][i] == 'R')
                        r++;
                    if (robots[j][i] == 'P')
                        p++;
                    if (robots[j][i] == 'S')
                        s++;
                }
            }
            int alive_count = (r != 0) + (p != 0) + (s != 0);
            if (alive_count == 2) {
                if (r == 0) {
                    for (int j = 0; j < n; j++) {
                        if (robots[j][i] == 'P')
                            alive[j] = false;
                    }
                } else if (p == 0) {
                    for (int j = 0; j < n; j++) {
                        if (robots[j][i] == 'S')
                            alive[j] = false;
                    }

                } else {  // s == 0
                    for (int j = 0; j < n; j++) {
                        if (robots[j][i] == 'R')
                            alive[j] = false;
                    }
                }
            } else
                continue;
        }
        int alive_count = 0;
        int alive_robot;
        for (int i = 0; i < n; i++) {
            if (alive[i]) {
                alive_count++;
                alive_robot = i + 1;
            }
        }
        if (alive_count == 1) {
            cout << alive_robot << "\n";
        } else
            cout << "0\n";
    }
}
