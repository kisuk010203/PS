#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

struct pair_equal {
    template <class T1, class T2>
    bool operator()(const pair<T1, T2>& p1, const pair<T1, T2>& p2) const {
        return p1.first == p2.first && p1.second == p2.second;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_map<p, bool, pair_hash, pair_equal> edgemap;
        vector<p> points(n);
        for (int i = 0; i < n; i++) {
            ll a, b;
            cin >> a >> b;
            edgemap.insert(make_pair(make_pair(a, b), true));
            points[i] = make_pair(a, b);
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                p pt1 = points[i];
                p pt2 = points[j];
                ll area = (pt1.first - pt2.first) * (pt1.first - pt2.first) +
                          (pt1.second - pt2.second) * (pt1.second - pt2.second);
                if (area <= ans)
                    continue;
                ll x_diff = pt2.first - pt1.first;
                ll y_diff = pt2.second - pt1.second;
                p pt3 = make_pair(pt1.first - y_diff, pt1.second + x_diff);
                p pt4 = make_pair(pt2.first - y_diff, pt2.second + x_diff);
                if (edgemap.find(pt3) != edgemap.end() &&
                    edgemap.find(pt4) != edgemap.end())
                    ans = area;
            }
        }
        cout << ans << '\n';
    }
}
