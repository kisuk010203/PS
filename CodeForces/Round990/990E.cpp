#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for(int i = a; i < b; i++)
#define each(a, b) for(auto& a : b)
typedef pair<ll, ll> pll;

#define NMAX 200000
#define INF 2e9

ll upper_seg[NMAX << 2];
ll lower_seg[NMAX << 2];

ll update(ll *seg, int cur, int left, int right, int idx, int val) {
    if(idx < left || right < idx) return seg[cur];
    if(left == right) return seg[cur] = val;
    int mid = (left + right) >> 1;
    return seg[cur] = update(seg, cur << 1, left, mid, idx, val) 
        + update(seg, cur << 1 | 1, mid + 1, right, idx, val);
}
ll get_sum(ll *seg, int cur, int left, int right, int start, int end) {
    if(end < left || right < start) return 0;
    if(start <= left && right <= end) return seg[cur];
    int mid = (left + right) >> 1;
    return get_sum(seg, cur << 1, left, mid, start, end)
        + get_sum(seg, cur << 1 | 1, mid + 1, right, start, end);
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vector<pll> points(n);
        vector<pll> zip_points(n);
        vector<ll> sorted_xs(n);
        vector<ll> sorted_ys(n);
        rep(i, 0, n) {
            ll x, y; cin >> x >> y;
            points[i] = {x, y};
            sorted_xs[i] = x;
            sorted_ys[i] = y;
        }
        sort(all(points));
        sort(all(sorted_xs));
        sort(all(sorted_ys));

        // coordinate zip
        rep(i, 0, n) {
            ll pfirst = lower_bound(all(sorted_xs), points[i].first) - sorted_xs.begin();
            ll psecond = lower_bound(all(sorted_ys), points[i].second) - sorted_ys.begin();
            zip_points[i] = {pfirst, psecond};
        }

        int k_left = 0, k_right = n / 4;
        while(k_left < k_right) {
            // horizontal line first
            int k = (k_left + k_right) >> 1;
            fill(upper_seg, upper_seg + (n << 2), 0);
            fill(lower_seg, lower_seg + (n << 2), 0);
            int hor = 0, curr_idx = 0;
            while(hor < n) {
                while(curr_idx < n && points[curr_idx].first == hor) {
                    update(upper_seg, 1, 0, n - 1, zip_points[curr_idx].second, -1);
                    update(lower_seg, 1, 0, n - 1, zip_points[curr_idx].second, 1);
                    curr_idx++;
                }
            }
        }
        

    }
}