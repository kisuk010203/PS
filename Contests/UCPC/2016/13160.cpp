#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
struct comp {
    bool operator()(const pii &a, const pii &b) const {
        if (a.second == b.second)
            return (a.first > b.first);
        return (a.second > b.second);
    }
};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pii> intervals(n);
    vector<pii> copy_intervals(n);
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        intervals[i] = {s, e};
        copy_intervals[i] = {s, e};
    }

    sort(intervals.begin(), intervals.end());
    priority_queue<pii, vector<pii>, comp> pq;
    int cnt_max = 0, max_pos = -1;

    for (int i = 0; i < n; i++) {
        while (!pq.empty() && pq.top().second < intervals[i].first)
            pq.pop();
        pq.push(intervals[i]);
        if (cnt_max < (int)(pq.size())) {
            cnt_max = (int)(pq.size());
            max_pos = intervals[i].first;
        }
    }
    cout << cnt_max << endl;
    for (int i = 0; i < n; i++) {
        int s = copy_intervals[i].first, e = copy_intervals[i].second;
        if (s <= max_pos && max_pos <= e)
            cout << i + 1 << " ";
    }
}
