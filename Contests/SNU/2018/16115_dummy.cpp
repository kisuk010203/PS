#include <bits/stdc++.h>
using namespace std;
vector<pair<double, double>> max_wing;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    double R = 0, a, b;
    int N; cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        double r = a * a + b * b;

        if (r > R)
            max_wing.clear(), max_wing.push_back({a, b}), R = r;
        else if (r == R)
            max_wing.push_back({a, b});
    }

    double ANS = 0, TMP;
    double fir = atan2(max_wing[0].second, max_wing[0].first) * 180 / 3.1415926535;

    double A = fir, B;
    for (int i = 1; i < max_wing.size(); ++i) {
        B = atan2(max_wing[i].second, max_wing[i].first) * 180 / 3.1415926535;

        TMP = B - A + ((B <= A) ? 360 : 0);
        A = B;
        if (ANS < TMP)
            ANS = TMP;
    }
    TMP = fir - A + ((fir <= A) ? 360 : 0);
    if (ANS < TMP)
        ANS = TMP;

    printf("%.7f", ANS);
    return 0;
}
