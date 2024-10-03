#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    double x = (c * e - b * f) / (a * e - b * d);
    double y = (c * d - a * f) / (b * d - a * e);
    cout << x << " " << y << "\n";
}