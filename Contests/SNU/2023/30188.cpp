#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    string HAN = "hanbyeol\n", GEO = "geometry\n", NUM = "number_theory\n";
    cin >> T;
    while (T--) {
        int s, n, u, p, c;
        cin >> s >> n >> u >> p >> c;
        if (s + n + u == 0) {
            cout << ((p % 2 == 1) ? GEO : NUM);
        } else if (s + n == 0 && u == 1 && p % 2)
            cout << GEO;
        else
            cout << HAN;
    }
}
