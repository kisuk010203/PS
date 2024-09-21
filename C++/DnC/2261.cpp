#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> point;
point points[101010];

ll min_dist = 808080808080L;

ll dist(point a, point b) {
    return (a.first - b.first) * (a.first - b.first) +
           (a.second - b.second) * (a.second - b.second);
}
void vertical_points(int left, int right, double mid) {
    vector<point> temp;
    for (int i = left; i <= right; i++) {
        double diff = mid - points[i].first;
        if (diff * diff < min_dist)
            temp.push_back(points[i]);
    }
    sort(temp.begin(), temp.end(),
         [](const point &a, const point &b) { return a.second < b.second; });

    for (int i = 0; i < temp.size(); i++)
        for (int j = i + 1;
             j < temp.size() && (temp[i].second - temp[j].second) *
                                        (temp[i].second - temp[j].second) <
                                    min_dist;
             j++)
            min_dist = min(min_dist, dist(temp[i], temp[j]));
}
void brute_force(int left, int right) {
    for (int i = left; i < right; i++) {
        for (int j = i + 1; j <= right; j++) {
            min_dist = min(min_dist, dist(points[i], points[j]));
        }
    }
}
void dnc(int left, int right) {
    if (right <= left)
        return;
    if (right - left <= 3) {
        brute_force(left, right);
        return;
    }

    int idx_mid = (left + right) / 2;
    double mid = (points[idx_mid - 1].first + points[idx_mid].first) / 2;

    dnc(left, idx_mid - 1);
    dnc(idx_mid, right);
    vertical_points(left, right, mid);
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }
    sort(points, points + n);

    dnc(0, n - 1);
    cout << min_dist << "\n";
}
