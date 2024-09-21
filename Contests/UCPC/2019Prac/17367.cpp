#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ld value(int a, int b, int c) {
    if (a == b && b == c) {
        return 10000 + 1000 * (a + 1);
    } else if (a == b || b == c || c == a) {
        return 1000 + 100 * (a + b + c - max({a, b, c}) - min({a, b, c}) + 1);
    } else {
        return 100 * (max({a, b, c}) + 1);
    }
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    ld dp[n][6][6][6];
    for (int a = 0; a < 6; a++) {
        for (int b = 0; b < 6; b++) {
            for (int c = 0; c < 6; c++) {
                dp[0][a][b][c] = value(a, b, c);
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int a = 0; a < 6; a++) {
            for (int b = 0; b < 6; b++) {
                for (int c = 0; c < 6; c++) {
                    ld val = value(a, b, c);
                    ld sum = 0;
                    for (int d = 0; d < 6; d++) {
                        sum += dp[i - 1][b][c][d];
                    }
                    sum /= 6;
                    dp[i][a][b][c] = max(val, sum);
                }
            }
        }
    }
    ld avg = 0;
    for (int a = 0; a < 6; a++) {
        for (int b = 0; b < 6; b++) {
            for (int c = 0; c < 6; c++) {
                avg += dp[n - 3][a][b][c];
            }
        }
    }
    avg /= 216;
    cout << fixed;
    cout.precision(9);
    cout << avg << "\n";
}