#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
ll radius(p a) {
    return a.first * a.first + a.second * a.second;
}
double custom_atan(p a) {
    double angle = atan2(a.second, a.first);
    if (angle < 0)
        angle += 2 * M_PI;
    return angle;
}
double angle_between(p a, p b) {
    double ca = custom_atan(a);
    double cb = custom_atan(b);
    if (ca < cb)
        return cb - ca;
    else
        return cb - ca + 2 * M_PI;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    vector<p> wing;
    vector<p> max_wing;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        wing.push_back({a, b});
    }
    ll max_radius = 0;
    for (p item : wing) {
        max_radius = max(max_radius, radius(item));
    }
    for (p item : wing) {
        if (max_radius == radius(item))
            max_wing.push_back(item);
    }
    if (max_wing.size() == 1) {
        cout << 360;
        return 0;
    }
    double max_between = 0;
    for (int i = 0; i < max_wing.size(); i++) {
        p a = max_wing[(i + 1) % (max_wing.size())];
        p b = max_wing[i];
        max_between = max(max_between, angle_between(b, a));
    }

    max_between = max_between * 180 / M_PI;
    cout << max_between << "\n";
}
