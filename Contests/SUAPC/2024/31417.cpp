#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> point;
vector<point> new_points;

bool cmp(point &a, point &b) {
    point x = new_points[0];
    ll cross = (a.first - x.first) * (b.second - x.second) -
               (a.second - x.second) * (b.first - x.first);
    return cross > 0; // for collinear points, we need not think.
}
/// @brief Height of the triangle formed by a, b, c, where a is the topmost
/// point.
/// @return height of triangle
double get_height(point &a, point &b, point &c) {
    double bc_length = sqrt((b.first - c.first) * (b.first - c.first) +
                            (b.second - c.second) * (b.second - c.second));
    double cross = abs((b.first - a.first) * (c.second - a.second) -
                       (b.second - a.second) * (c.first - a.first));
    return cross / bc_length;
}
double min_height_triangle(point &a, point &b, point &c) {
    return min(get_height(c, b, a), get_height(b, c, a));
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    double min_height = 1e10;
    for (int i = 0; i < n; i++) {
        new_points = points;
        swap(new_points[0], new_points[i]);
        point main_point = new_points[0];
        sort(new_points.begin() + 1, new_points.end(), cmp);
        for (int j = 1; j < n - 1; j++) {
            min_height =
                min(min_height, min_height_triangle(main_point, new_points[j],
                                                    new_points[j + 1]));
        }
        min_height =
            min(min_height, min_height_triangle(main_point, new_points[n - 1],
                                                new_points[1]));
    }
    cout << fixed << setprecision(9) << min_height << '\n';
}