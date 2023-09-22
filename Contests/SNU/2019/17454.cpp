#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> f >> e;
        if (c >= d || f >= e || f * c > (e - f) * (d - c)) {
            cout << "GOD\n";
            continue;
        }
        cout << "KDH\n";
        continue;
    }

    return 0;
}
