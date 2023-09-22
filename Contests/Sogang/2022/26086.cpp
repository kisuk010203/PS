#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    bool is_reversed = false;
    deque<int> jobs;
    int sort_begin = 0, sort_end = 0;
    int n, q, k;
    cin >> n >> q >> k;
    vector<pair<int, int>> queries;
    int sort_idx = -1;
    for (int i = 0; i < q; i++) {
        int mode, job = 0;
        cin >> mode;
        if (mode == 0)
            cin >> job;
        queries.push_back({mode, job});
        if (mode == 1)
            sort_idx = i;
    }

    for (int i = 0; i < sort_idx; i++) {
        pair<int, int> p = queries[i];
        int mode = p.first, job = p.second;
        if (mode == 0)
            jobs.push_back(job);
    }
    sort(jobs.begin(), jobs.end());

    for (int i = sort_idx + 1; i < q; i++) {
        pair<int, int> p = queries[i];
        int mode = p.first, job = p.second;
        if (mode == 2)
            is_reversed = !is_reversed;
        else {
            if (is_reversed) {
                jobs.push_back(job);
            } else
                jobs.push_front(job);
        }
    }

    if (!is_reversed) {
        for (int i = 0; i < k - 1; i++) {
            jobs.pop_front();
        }
        cout << jobs.front();
    } else {
        for (int i = 0; i < k - 1; i++) {
            jobs.pop_back();
        }
        cout << jobs.back();
    }
}
