#include <bits/stdc++.h>
using namespace std;
typedef struct HW {
    int due;
    int weight;
} HW;
bool comp(const HW &a, const HW &b) { return a.due > b.due; }
struct comp_pq {
    bool operator()(const HW &a, const HW &b) { return a.weight < b.weight; }
};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    vector<HW> HWs;
    priority_queue<HW, vector<HW>, comp_pq> HW_pq;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int d, w;
        cin >> d >> w;
        HWs.push_back({d, w});
    }

    sort(HWs.begin(), HWs.end(), comp); // sort HW decreasing due
    int due_idx = 0;
    long long ret = 0;
    for (int due_date = 1000; due_date; due_date--) {
        while (due_idx < n && HWs[due_idx].due >= due_date) {
            HW_pq.push(HWs[due_idx]);
            due_idx++;
        }
        if (HW_pq.empty())
            continue;
        ret += HW_pq.top().weight;
        HW_pq.pop();
    }
    cout << ret << "\n";
}