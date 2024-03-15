#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n1, m1, n2, m2;
        cin >> n1 >> m1 >> n2 >> m2;
        ld base_res = 1;
        ld prev = 1;
        ld accum = 1;
        for (int i = 0; i >= -m1; i--) {
            base_res *= (n1 + i + 1);
            base_res /= (n1 + n2 + 2 + i);
        }
        for (int i = m1 + 1; i <= m1 + m2; i++) {
            ld curr =
                prev * (i * (m1 + n2 + 2 - i)) / ((i - m1) * ((n1 + n2 + 2 - i)));
            accum += curr;
            prev = curr;
        }
        base_res *= accum;
        cout << base_res << "\n";
    }
}